#include "NhapKhoWidget.h"
#include <QPointer>
#include <QThread>
#include <QFileDialog>
#include <spdlog/spdlog.h>
#include "ThemCongVanDialog.h"
#include "Vietnamese.h"
#include "Copier.h"
#include "MapInfo.h"
#include "Database.h"
#include "TuLieu.hxx"
#include "TuLieu-odb.hxx"
#include "TuLieuBanDo.hxx"
#include "TuLieuBanDo-odb.hxx"
#include "HeQuyChieuType.hxx"
#include "HeQuyChieuType-odb.hxx"
#include "PhuongPhapTLType.hxx"
#include "PhuongPhapTLType-odb.hxx"
#include "PhieuNhapKho.hxx"
#include "PhieuNhapKho-odb.hxx"
#include "PhieuNhapKhoChiTiet.hxx"
#include "PhieuNhapKhoChiTiet-odb.hxx"
#include "Kho.hxx"
#include "Kho-odb.hxx"
#include "TonKho.hxx"
#include "TonKho-odb.hxx"

NhapKhoWidget::NhapKhoWidget(QWidget* parent)
	: QWidget(parent)
{
	setupUi(this);
	progressBar->hide();
	reload();

	connect(scanningWidget, &ScanningWidget::finished,
		[this](QSharedPointer<QStandardItemModel> model) { mItemModel = model; });
	connect(storeButton, &QPushButton::clicked, this, &NhapKhoWidget::store);
	connect(browseStoreDirButton, &QPushButton::clicked, this, &NhapKhoWidget::browseStoreDir);
	connect(browseDmsDirButton, &QPushButton::clicked, this, &NhapKhoWidget::browseFtpDir);
	connect(themCongVanButton, &QPushButton::clicked, this, &NhapKhoWidget::themCongVan);
}

void NhapKhoWidget::reload()
{
	phanLoaiTuLieuWidget->reload();
	disconnect(congVanComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
		this, &NhapKhoWidget::loadTenKhoTuLieu);
	try
	{
		auto db = Database::m_database;
		odb::transaction t(db->begin());
		using PhieuNhapKhoQuery = odb::query<PhieuNhapKho>;
		using PhieuNhapKhoResult = odb::result<PhieuNhapKho>;
		PhieuNhapKhoResult congvan = db->query<PhieuNhapKho>("ORDER BY" + PhieuNhapKhoQuery::mNgayNhapKho + "DESC");
		congVanComboBox->clear();
		for (const auto& c : congvan)
			congVanComboBox->addItem(c.mSoPhieu, c.mPhieuNhapKhoId);

		using HeQuyChieuTypeResult = odb::result<HeQuyChieuType>;
		HeQuyChieuTypeResult hqc = db->query<HeQuyChieuType>();
		mHeQuyChieuType.clear();
		for (const auto& h : hqc)
			mHeQuyChieuType[h.mMa] = h.mHeQuyChieuTypeId;

		using PhuongPhapTLTypeResult = odb::result<PhuongPhapTLType>;
		PhuongPhapTLTypeResult pptl = db->query<PhuongPhapTLType>();
		mPhuongPhapTLType.clear();
		for (const auto& p : pptl)
			mPhuongPhapTLType[p.mMa] = p.mPhuongPhapTLTypeId;
		
		t.commit();
	}
	catch (const odb::exception& ex)
	{
		spdlog::get("logger")->error(ex.what());
	}

	if (congVanComboBox->count() > 0)
	{
		connect(congVanComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
			this, &NhapKhoWidget::loadTenKhoTuLieu);
		loadTenKhoTuLieu(0);
	}
}

void NhapKhoWidget::store()
{
	if (mItemModel == nullptr && mItemModel->rowCount() == 0)
		return;

	auto storeDir = storeDirLineEdit->text();
	if (storeDir.trimmed().isEmpty())
		return;

	m_id_tulieutype = phanLoaiTuLieuWidget->idLoadLoaiTuLieu();
	m_id_tyletype = scanningWidget->idTyLeType();

	QPointer<Copier> copier(new Copier(mItemModel.get(), storeDir));
	QPointer<QThread> thread(new QThread());
	copier->moveToThread(thread);

	connect(copier, SIGNAL(started()), this, SLOT(copierStarted()));
	connect(copier, SIGNAL(finished()), this, SLOT(copierFinished()));
	connect(copier, SIGNAL(progressPath(const QString&)), this, SLOT(copierProgress(const QString&)));
	connect(copier, SIGNAL(completeRow(int, const QString&)), this, SLOT(completeRow(int, const QString&)));
	connect(copier, SIGNAL(warnExists(int)), this, SLOT(warnExists(int)));

	connect(copier, SIGNAL(finished()), thread, SLOT(quit()));
	connect(copier, SIGNAL(finished()), copier, SLOT(deleteLater()));
	connect(thread, SIGNAL(started()), copier, SLOT(run()));
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();
}

void NhapKhoWidget::browseStoreDir()
{
	auto dir = QFileDialog::getExistingDirectory(this, Vietnamese::str(L"Chọn thư mục lưu"));
	if (!dir.isEmpty())
	{
		storeDirLineEdit->setText(dir);
	}
}

void NhapKhoWidget::browseFtpDir()
{
	auto dir = QFileDialog::getExistingDirectory(this, Vietnamese::str(L"Chọn thư mục FTP"));
	if (!dir.isEmpty())
	{
		dmsDirLineEdit->setText(dir);
	}
}

void NhapKhoWidget::copierStarted()
{
	progressPathLabel->clear();
	progressBar->show();
	progressBar->setMaximum(mItemModel->rowCount());
	progressBar->setValue(0);
	mScale = scanningWidget->scaleText();
}

void NhapKhoWidget::copierFinished() const
{
	progressBar->hide();
	progressPathLabel->clear();
}

void NhapKhoWidget::copierProgress(const QString& path) const
{
	progressPathLabel->setText(path);
}

void NhapKhoWidget::completeRow(int row, const QString& destination)
{
	const QString& code = mItemModel->item(row, 0)->text();
	const QDate& date = QDate::fromString(mItemModel->item(row, 8)->text(), "dd-MM-yyyy");
	progressBar->setValue(row + 1);
	
	bool successful = insertToDatabase(code, date, destination);
	mItemModel->setItem(row, 10, new QStandardItem(
		successful ? QIcon(":/icons/apply.svg") : QIcon(":/icons/cancel.svg"),
		successful ? "Xong" : Vietnamese::str(L"Lỗi")));
	
	if (successful == false)
	{
		QDir dir(destination);
		dir.removeRecursively();

		spdlog::get("logger")->debug("Remove {}", destination.toStdString());
		if (dir.cd("..") && dir.isEmpty())
		{
			spdlog::get("logger")->debug("Empty -> Remove {}", dir.path().toStdString());
			dir.removeRecursively();
		}		
	}
}

void NhapKhoWidget::warnExists(int row)
{
	progressBar->setValue(row + 1);
	mItemModel->setItem(row, 10, new QStandardItem(QIcon(":/icons/warning.svg"), Vietnamese::str(L"Đã có")));
}

void NhapKhoWidget::themCongVan()
{
	auto dialog = std::make_unique<ThemCongVanDialog>();
	dialog->reload();
	if (dialog->exec() == QDialog::Accepted)
	{
		this->reload();
	}
}

void NhapKhoWidget::loadTenKhoTuLieu(int idx)
{
	spdlog::get("logger")->debug("Load TenKhoTuLieu");
	try
	{
		auto id_congvan = congVanComboBox->itemData(idx).toInt();
		auto db = Database::m_database;
		odb::transaction t(db->begin());

		auto cong_van = db->load<PhieuNhapKho>(id_congvan);
		auto kho = db->load<Kho>(cong_van->mKhoId);
		if (kho.get())
		{
			tenKhoLineEdit->setText(kho->mTenKho);
		}
		t.commit();
	}
	catch (const odb::exception& e)
	{
		spdlog::get("logger")->error(e.what());
	}
}

bool NhapKhoWidget::insertToDatabase(const QString& code, const QDate& date, const QString& destination)
{
	bool successful = false;
	const MapInfo& sheet = MapInfo::get(code, mScale);
	QString path = destination;
	path.replace(dmsDirLineEdit->text() + "/", "");

	spdlog::get("logger")->debug("insert to database");
	try
	{
		auto db = Database::m_database;
		odb::transaction t(db->begin());

		auto tu_lieu = make_unique<TuLieu>(m_id_tulieutype, code, sheet.mTenManh);
		size_t id_tulieu = db->persist(*tu_lieu);
		
		size_t id_hequychieu = mHeQuyChieuType[sheet.mHeToaDo];
		size_t id_pptl = 1000;
		if (mPhuongPhapTLType.contains(sheet.mPhuongPhapThanhLap))
			id_pptl = mPhuongPhapTLType[sheet.mPhuongPhapThanhLap];

		auto ban_do = make_unique<TuLieuBanDo>(id_tulieu, m_id_tyletype,
			code, sheet.mTenManh, sheet.mKhoangCaoDeu, id_hequychieu, sheet.mMuiChieu,
			sheet.mNamSanXuat, date, id_pptl, path);
		db->persist(*ban_do);

		size_t id_phieunhapkho = congVanComboBox->currentData().toInt();
		auto phieunhapkho_chitiet = make_unique<PhieuNhapKhoChiTiet>(id_phieunhapkho, id_tulieu);
		db->persist(*phieunhapkho_chitiet);

		auto phieunhapkho = db->load<PhieuNhapKho>(id_phieunhapkho);
		auto ton_kho = make_unique<TonKho>(phieunhapkho->mKhoId, id_tulieu);
		db->persist(*ton_kho);

		t.commit();
		successful = true;
		spdlog::get("logger")->info("Insert [{}] [{}]", code.toStdString(), path.toStdString());
	}
	catch (const odb::exception& e)
	{
		spdlog::get("logger")->error(e.what());
	}
	return successful;
}

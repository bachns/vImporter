#include "NhapKhoWidget.h"

#include <spdlog/spdlog.h>

NhapKhoWidget::NhapKhoWidget(QWidget* parent)
	: QWidget(parent)
{
	spdlog::get("logger")->trace(__FUNCTION__);
	setupUi(this);
}

NhapKhoWidget::~NhapKhoWidget()
{
	spdlog::get("logger")->trace(__FUNCTION__);
}

void NhapKhoWidget::reload()
{
	phanLoaiTuLieuWidget->reload();
}
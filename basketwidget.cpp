#include "basketwidget.h"
#include "ui_basketwidget.h"

BasketWidget::BasketWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BasketWidget)
{
    ui->setupUi(this);
}

BasketWidget::~BasketWidget()
{
    delete ui;
}

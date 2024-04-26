#include "productwidget.h"
#include "ui_productwidget.h"
#include <QWidget>

ProductWidget::ProductWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductWidget)
{
    ui->setupUi(this);
}
void ProductWidget::add() {
    this->setWindowFlags(Qt::WindowStaysOnTopHint |
                         Qt::WindowSystemMenuHint |
                         Qt::FramelessWindowHint|
                         Qt::Window |
                         Qt::Popup);
    this->move(movingWidgetXCentre,movingWidgetYCentre);
    this->show();
}
ProductWidget::~ProductWidget()
{
    delete ui;
}

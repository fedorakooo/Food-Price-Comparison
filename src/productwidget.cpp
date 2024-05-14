#include "productwidget.h"
#include "ui_productwidget.h"

ProductWidget::ProductWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductWidget)
{
    ui->setupUi(this);

    ui->label->setAlignment(Qt::AlignCenter);

    this->setWindowFlags(Qt::WindowStaysOnTopHint |
                         Qt::WindowSystemMenuHint |
                         Qt::FramelessWindowHint|
                         Qt::Window |
                         Qt::Popup);
}

void ProductWidget::add(Product* product) {
    if(product->getName() != " " && product->getBestPrice() != 0) {
        ui->nameProduct->setText(product->getName());
        ui->labelPriceFirstShop->setText(QString::number(product->getArrPrice()[0]));
        ui->labelPriceSecondShop->setText(QString::number(product->getArrPrice()[1]));
        ui->labelPriceThirdShop->setText(QString::number(product->getArrPrice()[2]));
        ui->labelPriceFourthShop->setText(QString::number(product->getArrPrice()[3]));
        ui->labelPriceFifthShop->setText(QString::number(product->getArrPrice()[4]));
        ui->labelPriceSixthShop->setText(QString::number(product->getArrPrice()[5]));
        ui->labelPriceSeventhShop->setText(QString::number(product->getArrPrice()[6]));
        QPixmap picture = product->getPicture();
        picture = picture.scaled(ui->label->size(), Qt::KeepAspectRatio);

        ui->label->setPixmap(picture);

        this->move(movingWidgetXCentre,movingWidgetYCentre);
        this->show();
    }
}

ProductWidget::~ProductWidget()
{
    delete ui;
}

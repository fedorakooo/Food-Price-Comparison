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
        setPrice(ui->labelPriceFirstShop, product->getArrPrice()[0]);
        setPrice(ui->labelPriceSecondShop, product->getArrPrice()[1]);
        setPrice(ui->labelPriceThirdShop, product->getArrPrice()[2]);
        setPrice(ui->labelPriceFourthShop, product->getArrPrice()[3]);
        setPrice(ui->labelPriceFifthShop, product->getArrPrice()[4]);
        setPrice(ui->labelPriceSixthShop, product->getArrPrice()[5]);
        setPrice(ui->labelPriceSeventhShop, product->getArrPrice()[6]);
        QPixmap picture = product->getPicture();
        picture = picture.scaled(ui->label->size(), Qt::KeepAspectRatio);

        ui->label->setPixmap(picture);

        this->move(MOVING_WIDGET_X_CENTRE,MOVING_WIDGET_Y_CENTRE);
        this->show();
    }
}

ProductWidget::~ProductWidget()
{
    delete ui;
}

void ProductWidget::setPrice(QLabel* label, double price) {
    label->setText((price == -1) ? "—" : StringProcessing::additionPrice(QString::number(price)));
}

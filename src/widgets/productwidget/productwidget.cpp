#include "productwidget.h"
#include "ui_productwidget.h"

#include "logic/stringformatter.h"

ProductWidget::ProductWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductWidget)
{
    ui->setupUi(this);

    arrLabelPriceShop = {
        ui->labelPriceFirstShop,
        ui->labelPriceSecondShop,
        ui->labelPriceThirdShop,
        ui->labelPriceFourthShop,
        ui->labelPriceFifthShop,
        ui->labelPriceSixthShop,
        ui->labelPriceSeventhShop
    };

    arrLabelShop = {
        ui->labelShop_1,
        ui->labelShop_2,
        ui->labelShop_3,
        ui->labelShop_4,
        ui->labelShop_5,
        ui->labelShop_6,
        ui->labelShop_7
    };

    ui->label->setAlignment(Qt::AlignCenter);
    setAppearance();

    setWindowFlags(Qt::WindowStaysOnTopHint |
                   Qt::WindowSystemMenuHint |
                   Qt::FramelessWindowHint |
                   Qt::Window |
                   Qt::Popup);
}

ProductWidget::~ProductWidget() {
    delete ui;
}

void ProductWidget::setAppearance() {
    QFont* fontPrice = new QFont();
    QFont* font = new QFont();
    font->setPointSize(10);
    font->setBold(true);
    fontPrice->setPointSize(13);
    ui->nameProduct->setFont(*font);
    for(int i = 0; i < SIZE_PRODUCT_PRICES; i++) {
        arrLabelShop[i]->setFont(*font);
        arrLabelPriceShop[i]->setFont(*fontPrice);
    }
}

// Add product to widget and display its data
void ProductWidget::add(Product* product) {
    if (product->getName().trimmed() != "" && product->getBestPrice() != 0) {
        ui->nameProduct->setText(product->getName());

        for (int i = 0; i < SIZE_PRODUCT_PRICES; i++) {
            if (product->getArrPrice()[i] == product->getBestPrice()) {
                setBestPrice(i, product->getArrPrice()[i]);
            } else {
                setPrice(i, product->getArrPrice()[i]);
            }
        }

        QPixmap picture = product->getPicture().scaled(ui->label->size(), Qt::KeepAspectRatio);
        ui->label->setPixmap(picture);

        this->move(MOVING_WIDGET_X_CENTRE, MOVING_WIDGET_Y_CENTRE);
        this->show();
    }
}

void ProductWidget::setBestPrice(int number, double price) {
    arrLabelShop[number]->setStyleSheet("QLabel { color : red; }");
    arrLabelPriceShop[number]->setStyleSheet("QLabel { color : red; }");
    arrLabelPriceShop[number]->setText((price == -1) ? "—" : StringFormatter::formatPrice(QString::number(price)));
}

void ProductWidget::setPrice(int number, double price) {
    arrLabelShop[number]->setStyleSheet("QLabel { color : black; }");
    arrLabelPriceShop[number]->setStyleSheet("QLabel { color : black; }");
    arrLabelPriceShop[number]->setText((price == -1) ? "—" : StringFormatter::formatPrice(QString::number(price)));
}

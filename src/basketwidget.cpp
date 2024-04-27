#include "basketwidget.h"
#include "ui_basketwidget.h"

BasketWidget::BasketWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BasketWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint |
                         Qt::WindowSystemMenuHint |
                         Qt::FramelessWindowHint|
                         Qt::Window |
                         Qt::Popup);
    this->move(200,100);
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(120);
    ui->tableWidget->setColumnWidth(0, 120);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    numberProductOnBasket = 0;
}


void BasketWidget::addProductBasket(Product* product) {
       if(product->getName() != " " && product->getBestPrice() != 0) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        QTableWidgetItem *nameProductItem = new QTableWidgetItem;
        nameProductItem->setText(product->getName());
        ui->tableWidget->setItem(numberProductOnBasket, 1, nameProductItem);
        for(int i = 0; i < 7; i++) {
            ui->tableWidget->setItem(numberProductOnBasket, 2 + i,
                                 new QTableWidgetItem(QString::number(product->getArrPrice()[i])));
        }
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setData(Qt::DecorationRole,product->getPixmap().scaled(120,120,Qt::IgnoreAspectRatio));  // 50-ширина 50-длина
        ui->tableWidget->setItem(numberProductOnBasket, 0, item);
        numberProductOnBasket++;
    }
}

BasketWidget::~BasketWidget()
{
    delete ui;
}

#include "basketwidget.h"
#include "ui_basketwidget.h"
#include "stringprocessing.h"

BasketWidget::BasketWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::BasketWidget) {
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::WindowSystemMenuHint | Qt::FramelessWindowHint | Qt::Window | Qt::Popup);

    // move window to center of screen
    move(MOVING_WIDGET_X_CENTRE, MOVING_WIDGET_Y_CENTRE);

    setupTable();
    updateInfo();
}

BasketWidget::~BasketWidget() {
    delete ui;
}

// Configure the basket table
void BasketWidget::setupTable() {
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(WIDGET_SIZE);
    ui->tableWidget->setColumnWidth(0, WIDGET_SIZE);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

// Add product to basket
void BasketWidget::addProductBasket(Product* product) {
    // if object is not valid, finish this method
    if (!product->isValid()) return;

    addProductToTable(product);
    updateProductPrices(product);

    auto *button = new QPushButton("Удалить");
    ui->tableWidget->setIndexWidget(ui->tableWidget->model()->index(numberProductsOnBasket + 1, 9), button);
    connect(button, &QPushButton::clicked, this, &BasketWidget::deleteProduct);

    updateInfo();
    numberProductsOnBasket++;
}

// Add product to the product table widget
void BasketWidget::addProductToTable(Product* product) {
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    auto *nameProductItem = new QTableWidgetItem(product->getName());
    ui->tableWidget->setItem(numberProductsOnBasket + 1, 1, nameProductItem);

    for (int i = 0; i < NUMBER_CATEGORY; i++) {
        auto *item = new QTableWidgetItem;
        // value -1 indicates that the product is not available in this store
        if (product->getArrPrice()[i] == -1) {
            arrNoProduct[i]++;
            item->setText("-");
        } else {
            arrFullPrice[i] += product->getArrPrice()[i];
            item->setText(StringProcessing::additionPrice(QString::number(product->getArrPrice()[i])));
        }
        ui->tableWidget->setItem(numberProductsOnBasket + 1, 2 + i, item);
    }

    // scale the image to a certain size
    QPixmap pixmap = product->getPicture().scaled(120, 120, Qt::KeepAspectRatio);

    auto *itemPicture = new QTableWidgetItem;
    itemPicture->setData(Qt::DecorationRole, pixmap);
    ui->tableWidget->setItem(numberProductsOnBasket + 1, 0, itemPicture);
}

// Updates the minimum prices of the product in the table by highlighting them with a certain color
void BasketWidget::updateProductPrices(Product* product) {
    double minimum = std::numeric_limits<double>::max();
    const QVector<double> &prices = product->getArrPrice();

    for (double price : prices) {
        if (price > 0) {
            minimum = qMin(minimum, price);
        }
    }

    for (int i = 0; i < NUMBER_CATEGORY; i++) {
        if (prices[i] == minimum) {
            auto *item = new QTableWidgetItem(StringProcessing::additionPrice(QString::number(prices[i])));
            item->setForeground(QBrush(QColor(255, 0, 0))); // QColor(255, 0, 0) is equivalent to red color
            ui->tableWidget->setItem(numberProductsOnBasket + 1, 2 + i, item);
        }
    }
}

void BasketWidget::deleteProduct() {
    auto *button = qobject_cast<QPushButton*>(sender());
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        if (ui->tableWidget->cellWidget(row, 9) == button) {
            updateProductInfo(row);
            ui->tableWidget->removeRow(row);
            numberProductsOnBasket--;
            break;
        }
    }
    updateInfo();
}

// Update product information after removal of the product
void BasketWidget::updateProductInfo(int row) {
    for (int col = 0; col < NUMBER_CATEGORY; col++) {
        auto *item = ui->tableWidget->item(row, col + 2);
        if (item->text() == "-") {
            arrNoProduct[col]--;
        } else {
            arrFullPrice[col] -= item->text().toDouble();
            if (arrFullPrice[col] < NUMBER_CHECK_CORRECT_FULL_PRICE_VALUE) {
                arrFullPrice[col] = 0;
            }
        }
    }
}

// Updates general information about products
void BasketWidget::updateInfo() {
    QFont font;
    font.setPointSize(13);

    auto *nameProductItem = new QTableWidgetItem("Информация о всех продуктах");
    ui->tableWidget->setItem(0, 1, nameProductItem);

    double minimum = std::numeric_limits<double>::max();
    for (int i = 0; i < NUMBER_CATEGORY; i++) {
        if (arrNoProduct[i] == 0) {
            minimum = qMin(minimum, arrFullPrice[i]);
        }
    }

    for (int i = 0; i < NUMBER_CATEGORY; i++) {
        std::unique_ptr<QTableWidgetItem> item;
        if (arrNoProduct[i] == 0 && arrFullPrice[i] == minimum && minimum != 0) {
            item = std::make_unique<QTableWidgetItem>(StringProcessing::additionPrice(QString::number(arrFullPrice[i])));
            item->setForeground(QBrush(QColor(255, 0, 0)));
        } else if (arrNoProduct[i] != 0) {
            item = std::make_unique<QTableWidgetItem>("-");
        } else {
            item = std::make_unique<QTableWidgetItem>(StringProcessing::additionPrice(QString::number(arrFullPrice[i])));
        }
        item->setFont(font);
        ui->tableWidget->setItem(0, 2 + i, item.release());
    }

    auto *button = new QPushButton("Удалить всё");
    connect(button, &QPushButton::clicked, this, &BasketWidget::clearBasket);
    ui->tableWidget->setIndexWidget(ui->tableWidget->model()->index(0, 9), button);
}

void BasketWidget::clearBasket() {
    while (numberProductsOnBasket > 0) {
        for (int i = 0; i < NUMBER_CATEGORY; i++) {
            arrFullPrice[i] = 0;
            arrNoProduct[i] = 0;
        }
        ui->tableWidget->removeRow(1);
        numberProductsOnBasket--;
    }
    updateInfo();
}

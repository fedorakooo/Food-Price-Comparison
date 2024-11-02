#pragma once

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>

#include "logic/product.h"

namespace Ui {
class BasketWidget;
}

class BasketWidget : public QWidget {
    Q_OBJECT

public:
    explicit BasketWidget(QWidget *parent = nullptr);
    ~BasketWidget();

public slots:
    void addProductBasket(Product* product);

private slots:
    void deleteProduct();
    void clearBasket();
    void updateInfo();

private:
    static constexpr int NUMBER_CATEGORY = 7;
    static constexpr int WIDGET_SIZE = 120;
    static constexpr int MOVING_WIDGET_X_CENTRE = 200;
    static constexpr int MOVING_WIDGET_Y_CENTRE = 100;
    static constexpr double NUMBER_CHECK_CORRECT_FULL_PRICE_VALUE = 0.001;

    int arrNoProduct[NUMBER_CATEGORY] = {};
    int numberProductsOnBasket = 0;
    double arrFullPrice[NUMBER_CATEGORY] = {};

    Ui::BasketWidget *ui;

    void setupTable();
    void addProductToTable(Product* product);
    void updateProductPrices(Product* product);
    QTableWidgetItem* createItemForCategory(int i, double minimum) const;
    void updateProductInfo(int row);
};

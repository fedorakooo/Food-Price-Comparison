#pragma once

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <QFont>
#include "logic/product.h"

namespace Ui {
class ProductWidget;
}

class ProductWidget : public QWidget {
    Q_OBJECT

public:
    ProductWidget(QWidget *parent = nullptr);
    ~ProductWidget();
    void add(Product* product);

private:
    void setAppearance();
    void setPrice(int number, double price);
    void setBestPrice(int number, double price);

    QVector<QLabel*> arrLabelPriceShop;
    QVector<QLabel*> arrLabelShop;

    static const int MOVING_WIDGET_X_CENTRE = 200;
    static const int MOVING_WIDGET_Y_CENTRE = 100;
    static const int SIZE_PRODUCT_PRICES = 7;

    Ui::ProductWidget *ui;
};

#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QFont>

#include "logic/stringformatter.h"
#include "logic/product.h"

namespace Ui {
class ProductWidget;
}

class ProductWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProductWidget(QWidget *parent = nullptr);
    ~ProductWidget();
    void add(Product* product);
private:
    void setAppearance();
    QVector<QLabel*> arrPrice;
    void setPrice(int number, double price);
    void setBestPrice(int number, double price);
    QVector<QLabel*> arrLabelPriceShop;
    QVector<QLabel*> arrLabelShop;
    const int MOVING_WIDGET_X_CENTRE = 200;
    const int MOVING_WIDGET_Y_CENTRE = 100;
    const int SIZE_PRODUCT_PRICES = 7;
    Ui::ProductWidget *ui;
};

#endif // PRODUCTWIDGET_H

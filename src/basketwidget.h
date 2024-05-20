#ifndef BASKETWIDGET_H
#define BASKETWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include "product.h"
#include "stringprocessing.h"

namespace Ui {
class BasketWidget;
}

class BasketWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BasketWidget(QWidget *parent = nullptr);
    ~BasketWidget();
public slots:
    void addProductBasket(Product* product);
private:
    int arrNoProduct[7] {};
    int numberProductOnBasket;
    double arrFullPrice[7] {};
    const int NUMBER_CATEGORY = 7;
    Ui::BasketWidget *ui;
private slots:
    void deleteProduct();
    void deleteBasket();
    void updateInfo();

};

#endif // BASKETWIDGET_H

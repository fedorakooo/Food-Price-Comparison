#ifndef BASKETWIDGET_H
#define BASKETWIDGET_H

#include <QWidget>
#include "product.h"

namespace Ui {
class BasketWidget;
}

class BasketWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BasketWidget(QWidget *parent = nullptr);
    ~BasketWidget();
    void addProductBasket(Product* product);
private:
    int numberProductOnBasket;
    Ui::BasketWidget *ui;
};

#endif // BASKETWIDGET_H

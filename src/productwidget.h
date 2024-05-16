#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include "product.h"

namespace Ui {
class ProductWidget;
}

class ProductWidget : public QWidget
{
    Q_OBJECT
protected:

public:
    explicit ProductWidget(QWidget *parent = nullptr);
    ~ProductWidget();
    void add(Product* product);
private:
    void setPrice(QLabel* label, double price);
    int const MOVING_WIDGET_X_CENTRE = 200;
    int const MOVING_WIDGET_Y_CENTRE = 100;
    Ui::ProductWidget *ui;
};

#endif // PRODUCTWIDGET_H

#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QMouseEvent>
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
    int const movingWidgetXCentre = 200;
    int const movingWidgetYCentre = 100;
    Ui::ProductWidget *ui;
};

#endif // PRODUCTWIDGET_H

#ifndef BASKETWIDGET_H
#define BASKETWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "product.h"
#include <QStandardItemModel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTableWidget>
#include <QGraphicsPixmapItem>

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
    QStandardItemModel *model = new QStandardItemModel;
    int numberProductOnBasket;
    double arrFullPrice[7] {};
    Ui::BasketWidget *ui;
private slots:
    void deleteProduct();
    void deleteBasket();
    void updateInfo();

};

#endif // BASKETWIDGET_H

#ifndef BASKETWIDGET_H
#define BASKETWIDGET_H

#include <QWidget>

namespace Ui {
class BasketWidget;
}

class BasketWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BasketWidget(QWidget *parent = nullptr);
    ~BasketWidget();

private:
    Ui::BasketWidget *ui;
};

#endif // BASKETWIDGET_H

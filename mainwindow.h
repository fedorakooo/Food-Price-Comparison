#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "productwidget.h"
#include <QFont>
#include <QWidget>
#include "basketwidget.h"
#include <QDir>
#include <QGroupBox>
#include "dataprocessing.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setInformationFirstProduct(Product product);
    void setInformationSecondProduct(Product product);
    void setInformationThirdProduct(Product product);
    void setInformationFourthProduct(Product product);
    void setInformationFifthProduct(Product product);
    void setInformationSixthProduct(Product product);
    void setInformationSomeProduct(int numberProduct, Product product);
    void setCorrectFontPrice();
    void setCorrectNamePrice();
    void setCorrectPathDirectory();
    int getAppealToProducts(int mousePressX, int mousePressY);
    void setFon();
private:
    QWidget *mainWidget;
    ProductWidget *productWidget;
    BasketWidget *basketWidget;
    QFont fontPrice;
    QString path = "";
    QFont fontName;
    DataProcessing data;
    Ui::MainWindow *ui;
    int const sizeElementPathBuildFile = 48;
private slots:
    void on_buttonCollapse_clicked();
    void on_buttonClose_clicked();
    void on_buttonBasket_clicked();
    void on_buttonOpenWidget_1_clicked();
};
#endif // MAINWINDOW_H

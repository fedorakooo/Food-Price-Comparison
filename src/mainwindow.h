#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFont>
#include <QWidget>
#include <QDir>
#include <QGroupBox>
#include "dataprocessing.h"
#include "basketwidget.h"
#include "productwidget.h"
#include "product.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QWidget *mainWidget;
    ProductWidget *productWidget;
    BasketWidget *basketWidget;
    QFont fontPrice;
    QString path = "";
    QFont fontName;
    DataProcessing data;
    Ui::MainWindow *ui;
    int numberPage;
    int numberAllPage;
    Product* arrProductScreen[6] {};
    int const sizeElementPathBuildFile = 48;
private slots:
    void setInformationFirstProduct(Product* product);
    void setInformationSecondProduct(Product* product);
    void setInformationThirdProduct(Product* product);
    void setInformationFourthProduct(Product* product);
    void setInformationFifthProduct(Product* product);
    void setInformationSixthProduct(Product* product);
    void setInformationSomeProduct(int numberProduct, Product* product);
    void setCorrectFontPrice();
    void setCorrectNamePrice();
    void setCorrectPathDirectory();
    void setFon();
    void setProductInformationMainWindow();
    void setSettingFontPrice();
    void setSettingButtonsOpenProductWidget();
    void setSettingFontName();
    void updateMainWindowProductInformation();
    void changeLabelPage();
    void updateInformationProduct();
    void on_buttonCollapse_clicked();
    void on_buttonClose_clicked();
    void on_buttonBasket_clicked();
    void on_buttonOpenWidget_1_clicked();
    void on_buttonOpenWidget_2_clicked();
    void on_buttonOpenWidget_3_clicked();
    void on_buttonOpenWidget_4_clicked();
    void on_buttonOpenWidget_5_clicked();
    void on_buttonOpenWidget_6_clicked();
    void nextPage();
    void previosPage();
    void on_buttonAddProduct_1_clicked();
    void on_buttonAddProduct_2_clicked();
    void on_buttonAddProduct_3_clicked();
    void on_buttonAddProduct_4_clicked();
    void on_buttonAddProduct_5_clicked();
    void on_buttonAddProduct_6_clicked();
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWidget>
#include <QDir>
#include <QSignalMapper>
#include "basketwidget.h"
#include "productwidget.h"
#include "product.h"
#include "data.h"
#include "projectappearance.h"
#include "stringprocessing.h"
#include "productsort.h"

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
    const QString DIRECTORY_IMAGE = "/image/";
    Data* data = new Data();
    Product* arrProductMainWindow[6];
    int numberPage;
    int numberAllPage;
    void updatePage();
    QString path;
    QVector<QLabel*> arrLabelPrice;
    QVector<QLabel*> arrLabelPicture;
    QVector<QPushButton*> arrButtonOpenProductWidget;
    QVector<QGroupBox*> arrGroupBox;
    Ui::MainWindow *ui;
private slots:
    void setNewSubcategory(int number);
    void fillAllWidget();
    void fillArrLabelPrice();
    void fillArrLabelPicture();
    void fillArrButtonOpenProductWidget();
    void fillArrGroupBox();
    void nextPage();
    void previousPage();
    void setSettingAllWidget();
    void updateDataMainWindow();
    void updateProductsMainWindow();
    void setInformationSomeProduct(int number, Product* product);
    void on_buttonAddProduct_1_clicked();
    void on_buttonAddProduct_2_clicked();
    void on_buttonAddProduct_3_clicked();
    void on_buttonAddProduct_4_clicked();
    void on_buttonAddProduct_5_clicked();
    void on_buttonAddProduct_6_clicked();
    void on_buttonSearchProduct_clicked();
    void on_buttonOpenWidget_1_clicked();
    void on_buttonOpenWidget_2_clicked();
    void on_buttonOpenWidget_3_clicked();
    void on_buttonOpenWidget_4_clicked();
    void on_buttonOpenWidget_5_clicked();
    void on_buttonOpenWidget_6_clicked();
};
#endif // MAINWINDOW_H

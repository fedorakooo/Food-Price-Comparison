#pragma once

#include <QMainWindow>
#include <QGroupBox>
#include <QButtonGroup>
#include <QWidget>
#include <QDir>
#include <QPalette>
#include <QRadioButton>
#include <QSignalMapper>
#include <QCompleter>
#include <QKeyEvent>

#include "widgets/basketwidget/basketwidget.h"
#include "widgets/productwidget/productwidget.h"
#include "data_processing/data.h"
#include "logic/product.h"

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
    QStringList* wordList;
    QVector<QStringList*> wordListCategory;

    QWidget *mainWidget;
    ProductWidget *productWidget;
    BasketWidget *basketWidget;
    Data* data;

    Product* arrProductMainWindow[6];

    int numberPage;
    int numberAllPage;
    QString search;
    QString path;

    QCompleter *completer;

    QVector<QLabel*> arrLabelPrice;
    QVector<QLabel*> arrLabelPicture;
    QVector<QPushButton*> arrButtonOpenProductWidget;
    QVector<QPushButton*> arrButtonAddProductBasket;
    QVector<QGroupBox*> arrGroupBox;

    Ui::MainWindow *ui;

    QString category;
    QString subcategory;
    int numberSort;

    const QString DIRECTORY_IMAGE = "./image/";
    const int SIZE_PRODUCTS = 6;
    const int SEARCH_BUTTON_CODE = 16777220;

private slots:
    void updatePage();
    void updateCompleter();

    void setupConnections();
    void setupCompleter();
    void setupBackground();
    void setupUiElements();
    void setupButtonConnections();

    void on_buttonAddProduct_clicked(int index);
    void on_buttonOpenWidget_clicked(int index);
    void setupOpenWidgetButtonConnections();

    void updateVisibleButton();
    void setCategory();
    void newCategory(int number);
    void newSubcategory(int number);

    void fillAllWidget();
    void fillArrLabelPrice();
    void fillArrLabelPicture();
    void fillArrButtonOpenProductWidget();
    void fillArrButtonAddProductBasket();
    void fillArrGroupBox();
    void fillComboBox();

    void nextPage();
    void previousPage();
    void setSettingAllWidget();
    void updateDataMainWindow();
    void updateProductsMainWindow();

    void setInformationSomeProduct(int number, Product* product);
    void on_buttonSearchProduct_clicked();

    void on_radioButtonClicked(int sortType);
    void connectRadioButtons();

    void on_pushButton_clicked();

    void updateProductData();
    void sortProducts();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

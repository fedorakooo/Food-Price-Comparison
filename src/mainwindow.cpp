#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), numberPage(0)
{
    mainWidget = new QWidget(this);
    ui->setupUi(this);

    ui->radioRecommendProduct->setChecked(true);

    path = QDir::currentPath();

    fillAllWidget();
    setSettingAllWidget();

    productWidget = new ProductWidget();
    basketWidget = new BasketWidget();


    {
        ui->comboBoxCategory->addItem("Категории");
        ui->comboBoxCategory->addItem("Вода, напитки, соки, кофе и чай");
    }
    numberAllPage = data->product.size() / 6;

    updatePage();

    connect(ui->buttonClose, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->buttonCollapse, &QPushButton::clicked, this, &MainWindow::showMinimized);
    connect(ui->buttonBasket, &QPushButton::clicked, basketWidget, &BasketWidget::show);
    connect(ui->buttonNextPage, &QPushButton::clicked, this, &MainWindow::nextPage);
    connect(ui->buttonPreviosPage, &QPushButton::clicked, this, &MainWindow::previousPage);
    connect(ui->comboBoxCategory, SIGNAL(currentIndexChanged(int)), this, SLOT(setNewSubcategory(int)));

    this->showFullScreen();
}

void MainWindow::setNewSubcategory(int number) {
    switch(number) {
        case 0: {
            ui->comboBoxSubcategoty->clear();
            ui->comboBoxSubcategoty->addItem("Подкатегории");
            break;
        }
        case 1: {
            ui->comboBoxSubcategoty->clear();
            ui->comboBoxSubcategoty->addItem("Подкатегории");
            ui->comboBoxSubcategoty->addItem("Вода минеральная, питьевая");
            ui->comboBoxSubcategoty->addItem("Чай, чайные напитки");
            ui->comboBoxSubcategoty->addItem("Напитки, напитки сокосодержащие");
            ui->comboBoxSubcategoty->addItem("Кофе в зернах");
            break;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillArrLabelPrice() {
    arrLabelPrice.push_back(ui->productPrice_1);
    arrLabelPrice.push_back(ui->productPrice_2);
    arrLabelPrice.push_back(ui->productPrice_3);
    arrLabelPrice.push_back(ui->productPrice_4);
    arrLabelPrice.push_back(ui->productPrice_5);
    arrLabelPrice.push_back(ui->productPrice_6);
}

void MainWindow::fillArrLabelPicture() {
    arrLabelPicture.push_back(ui->productPicture_1);
    arrLabelPicture.push_back(ui->productPicture_2);
    arrLabelPicture.push_back(ui->productPicture_3);
    arrLabelPicture.push_back(ui->productPicture_4);
    arrLabelPicture.push_back(ui->productPicture_5);
    arrLabelPicture.push_back(ui->productPicture_6);
}

void MainWindow::fillArrGroupBox() {
    arrGroupBox.push_back(ui->groupBox_1);
    arrGroupBox.push_back(ui->groupBox_2);
    arrGroupBox.push_back(ui->groupBox_3);
    arrGroupBox.push_back(ui->groupBox_4);
    arrGroupBox.push_back(ui->groupBox_5);
    arrGroupBox.push_back(ui->groupBox_6);
}


void MainWindow::fillArrButtonOpenProductWidget() {
    arrButtonOpenProductWidget.push_back(ui->buttonOpenWidget_1);
    arrButtonOpenProductWidget.push_back(ui->buttonOpenWidget_2);
    arrButtonOpenProductWidget.push_back(ui->buttonOpenWidget_3);
    arrButtonOpenProductWidget.push_back(ui->buttonOpenWidget_4);
    arrButtonOpenProductWidget.push_back(ui->buttonOpenWidget_5);
    arrButtonOpenProductWidget.push_back(ui->buttonOpenWidget_6);
}

void MainWindow::updateProductsMainWindow() {
    for(int i = 0; i < 6; i++) {
        setInformationSomeProduct(i, arrProductMainWindow[i]);
    }
}

void MainWindow::fillAllWidget() {
    fillArrLabelPicture();
    fillArrLabelPrice();
    fillArrButtonOpenProductWidget();
    fillArrGroupBox();
}

void MainWindow::setSettingAllWidget() {
    ProjectAppearance::setSettingFontPrice(arrLabelPrice);
    ProjectAppearance::setSettingButtonsOpenProductWidget(arrButtonOpenProductWidget);
    ProjectAppearance::setSettingFontName(arrGroupBox);
    ProjectAppearance::setSettingFontPicture(arrLabelPicture);
}

void MainWindow::setInformationSomeProduct(int number, Product* product) {
    arrGroupBox[number]->setTitle(product->getName());
    arrLabelPrice[number]->setText(QString::number(product->getBestPrice()));
    arrLabelPicture[number]->setPixmap(QPixmap(path + DIRECTORY_IMAGE + product->getFileName()));
}


void MainWindow::on_buttonAddProduct_1_clicked()
{
    basketWidget->addProductBasket(arrProductMainWindow[0]);
}

void MainWindow::on_buttonAddProduct_2_clicked()
{
    basketWidget->addProductBasket(arrProductMainWindow[1]);
}

void MainWindow::on_buttonAddProduct_3_clicked()
{
    basketWidget->addProductBasket(arrProductMainWindow[2]);
}

void MainWindow::on_buttonAddProduct_4_clicked()
{
    basketWidget->addProductBasket(arrProductMainWindow[3]);
}

void MainWindow::on_buttonAddProduct_5_clicked()
{
    basketWidget->addProductBasket(arrProductMainWindow[4]);
}

void MainWindow::updateDataMainWindow() {
    for(int i = numberPage * 6; i < data->product.size() && i < (numberPage * 6 + 6); i++) {
        arrProductMainWindow[i % 6] = data->product[i];
    }
}

void MainWindow::on_buttonAddProduct_6_clicked()
{
    basketWidget->addProductBasket(arrProductMainWindow[5]);
}

void MainWindow::nextPage() {
    if(numberPage < numberAllPage - 1) {
        numberPage++;
        updatePage();
    }
}

void MainWindow::previousPage() {
    if(numberPage) {
        numberPage--;
        updatePage();
    }
}

void MainWindow::updatePage() {
    updateDataMainWindow();
    updateProductsMainWindow();
    ui->labelNumberPage->setText(QString::number(numberPage + 1) + "/" + QString::number(numberAllPage));
}

void MainWindow::on_buttonSearchProduct_clicked()
{
    qDebug() << data->product.size();
    QString substr = ui->lineSearch->text();
    data->setProduct("1", "1", substr);
    numberPage = 0;
    numberAllPage = data->product.size() / 6;
    updatePage();

    qDebug() << substr << data->product.size();
}

void MainWindow::on_buttonOpenWidget_1_clicked()
{
    productWidget->add(arrProductMainWindow[0]);
}


void MainWindow::on_buttonOpenWidget_2_clicked()
{
    productWidget->add(arrProductMainWindow[1]);
}


void MainWindow::on_buttonOpenWidget_3_clicked()
{
    productWidget->add(arrProductMainWindow[2]);
}


void MainWindow::on_buttonOpenWidget_4_clicked()
{
    productWidget->add(arrProductMainWindow[3]);
}


void MainWindow::on_buttonOpenWidget_5_clicked()
{
    productWidget->add(arrProductMainWindow[4]);
}



void MainWindow::on_buttonOpenWidget_6_clicked()
{
    productWidget->add(arrProductMainWindow[5]);
}


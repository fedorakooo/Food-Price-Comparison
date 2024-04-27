#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    mainWidget = new QWidget(this);
    ui->setupUi(this);

    setCorrectPathDirectory();
    numberPage = 0;
    numberAllPage = data.getNumberAllProduct() / 6;
    updateInformationProduct();
    setSettingButtonsOpenProductWidget();
    basketWidget = new BasketWidget();
    setFon();

    setCorrectFontPrice();
    setCorrectNamePrice();

    setSettingFontPrice();
    setSettingFontName();

    productWidget = new ProductWidget();

    connect(ui->buttonNextPage, &QPushButton::clicked, this, &MainWindow::nextPage);
    connect(ui->buttonPreviosPage, &QPushButton::clicked, this, &MainWindow::previosPage);

    changeLabelPage();
    setProductInformationMainWindow();

    this->showFullScreen();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setProductInformationMainWindow() {
    for(int i = 0; i < 6; i++) {
        setInformationSomeProduct(i, arrProductScreen[i]);
    }
}

void MainWindow::setSettingFontName() {
    ui->groupBox_1->setFont(fontName);
    ui->groupBox_2->setFont(fontName);
    ui->groupBox_3->setFont(fontName);
    ui->groupBox_4->setFont(fontName);
    ui->groupBox_5->setFont(fontName);
    ui->groupBox_6->setFont(fontName);
}

void MainWindow::setSettingFontPrice() {
    ui->productPrice_1->setFont(fontPrice);
    ui->productPrice_2->setFont(fontPrice);
    ui->productPrice_3->setFont(fontPrice);
    ui->productPrice_4->setFont(fontPrice);
    ui->productPrice_5->setFont(fontPrice);
    ui->productPrice_6->setFont(fontPrice);
}

void MainWindow::setSettingButtonsOpenProductWidget() {
    ui->buttonOpenWidget_1->setStyleSheet("QPushButton{background: transparent;}");
    ui->buttonOpenWidget_2->setStyleSheet("QPushButton{background: transparent;}");
    ui->buttonOpenWidget_3->setStyleSheet("QPushButton{background: transparent;}");
    ui->buttonOpenWidget_4->setStyleSheet("QPushButton{background: transparent;}");
    ui->buttonOpenWidget_5->setStyleSheet("QPushButton{background: transparent;}");
    ui->buttonOpenWidget_6->setStyleSheet("QPushButton{background: transparent;}");
}
void MainWindow::updateInformationProduct() {
    for(int i = numberPage * 6; i < (numberPage + 1) * 6; i++) {
        arrProductScreen[i % 6] = data.getProduct(i);
    }
}
void MainWindow::setInformationSomeProduct(int numberProduct, Product* product) {
    switch (numberProduct) {
    case 0: {
        setInformationFirstProduct(product);
        break;
    }
    case 1: {
        setInformationSecondProduct(product);
        break;
    }
    case 2: {
        setInformationThirdProduct(product);
        break;
    }
    case 3: {
        setInformationFourthProduct(product);
        break;
    }
    case 4: {
        setInformationFifthProduct(product);
        break;
    }
    case 5: {
        setInformationSixthProduct(product);
        break;
    }
    default: {

    }
    }
}

void MainWindow::setInformationFirstProduct(Product* product) {
    ui->groupBox_1->setTitle(product->getName());
    ui->productPrice_1->setText(QString::number(product->getBestPrice()));
    ui->productPicture_1->setPixmap(product->getPixmap());
    ui->productPicture_1->setScaledContents(true);
}

void MainWindow::setInformationSecondProduct(Product* product) {
    ui->groupBox_2->setTitle(product->getName());
    ui->productPrice_2->setText(QString::number(product->getBestPrice()));
    ui->productPicture_2->setPixmap(product->getPixmap());
    ui->productPicture_2->setScaledContents(true);
}

void MainWindow::setInformationThirdProduct(Product* product) {
    ui->groupBox_3->setTitle(product->getName());
    ui->productPrice_3->setText(QString::number(product->getBestPrice()));
    ui->productPicture_3->setPixmap(product->getPixmap());
    ui->productPicture_3->setScaledContents(true);
}

void MainWindow::setInformationFourthProduct(Product* product) {
    ui->groupBox_4->setTitle(product->getName());
    ui->productPrice_4->setText(QString::number(product->getBestPrice()));
    ui->productPicture_4->setPixmap(product->getPixmap());
    ui->productPicture_4->setScaledContents(true);
}

void MainWindow::setInformationFifthProduct(Product* product) {
    ui->groupBox_5->setTitle(product->getName());
    ui->productPrice_5->setText(QString::number(product->getBestPrice()));
    ui->productPicture_5->setPixmap(product->getPixmap());
    ui->productPicture_5->setScaledContents(true);
}

void MainWindow::setInformationSixthProduct(Product* product) {
    ui->groupBox_6->setTitle(product->getName());
    ui->productPrice_6->setText(QString::number(product->getBestPrice()));
    ui->productPicture_6->setPixmap(product->getPixmap());
    ui->productPicture_6->setScaledContents(true);
}


void MainWindow::on_buttonCollapse_clicked()
{
    showMinimized();
}


void MainWindow::on_buttonClose_clicked()
{
    close();
}

void MainWindow::setCorrectFontPrice() {
    fontPrice.setPointSize(14);
    fontPrice.setWeight(QFont::Bold);
}

void MainWindow::setCorrectNamePrice() {
    fontName.setPointSize(9);
    fontName.setWeight(QFont::Bold);
}

void MainWindow::on_buttonBasket_clicked()
{
    basketWidget->show();
}

void MainWindow::on_buttonOpenWidget_1_clicked()
{
    productWidget->add(arrProductScreen[0]);
}


void MainWindow::on_buttonAddProduct_6_clicked()
{
    basketWidget->addProductBasket(arrProductScreen[5]);
}

void MainWindow::on_buttonOpenWidget_2_clicked()
{
    productWidget->add(arrProductScreen[1]);
}

void MainWindow::on_buttonOpenWidget_3_clicked()
{
    productWidget->add(arrProductScreen[2]);
}

void MainWindow::on_buttonOpenWidget_4_clicked()
{
    productWidget->add(arrProductScreen[3]);
}

void MainWindow::on_buttonOpenWidget_5_clicked()
{
    productWidget->add(arrProductScreen[4]);
}

void MainWindow::on_buttonOpenWidget_6_clicked()
{
    productWidget->add(arrProductScreen[5]);
}

void MainWindow::setCorrectPathDirectory() {
    QString buildPath = QCoreApplication::applicationDirPath();
    for(int i = 0; i < buildPath.size() - sizeElementPathBuildFile; i++) {
        path += buildPath[i];
    }
}

void MainWindow::setFon() {
    QPalette palette;
    palette.setBrush(mainWidget->backgroundRole(),QBrush(QPixmap(path + "/Data/Picture/View/fon.jpg")));
    mainWidget->setPalette(palette);
    mainWidget->resize(1920,1080);
    mainWidget->setAutoFillBackground(true);
}

void MainWindow::changeLabelPage() {
    ui->labelNumberPage->setText(QString::number(numberPage + 1) + " / " + QString::number(numberAllPage + 1));
}

void MainWindow::nextPage() {
    if(numberPage < numberAllPage) {
        numberPage++;
        updateMainWindowProductInformation();
    }
}

void MainWindow::previosPage() {
    if(numberPage > 0) {
        numberPage--;
        updateMainWindowProductInformation();
    }
}

void MainWindow::updateMainWindowProductInformation() {
    changeLabelPage();
    updateInformationProduct();
    setProductInformationMainWindow();
}

void MainWindow::on_buttonAddProduct_1_clicked()
{
    basketWidget->addProductBasket(arrProductScreen[0]);
}

void MainWindow::on_buttonAddProduct_2_clicked()
{
    basketWidget->addProductBasket(arrProductScreen[1]);
}

void MainWindow::on_buttonAddProduct_3_clicked()
{
    basketWidget->addProductBasket(arrProductScreen[2]);
}

void MainWindow::on_buttonAddProduct_4_clicked()
{
    basketWidget->addProductBasket(arrProductScreen[3]);
}

void MainWindow::on_buttonAddProduct_5_clicked()
{
    basketWidget->addProductBasket(arrProductScreen[4]);
}



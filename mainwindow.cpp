#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setCorrectPathDirectory();

    mainWidget=new QWidget(this);
    basketWidget = new BasketWidget();

    setFon();
    setCorrectFontPrice();
    setCorrectNamePrice();


    ui->setupUi(this);

    ui->buttonOpenWidget_1->setStyleSheet("QPushButton{background: transparent;}");
    ui->buttonOpenWidget_2->setStyleSheet("QPushButton{background: transparent;}");
    ui->buttonOpenWidget_3->setStyleSheet("QPushButton{background: transparent;}");
    ui->buttonOpenWidget_4->setStyleSheet("QPushButton{background: transparent;}");
    ui->buttonOpenWidget_5->setStyleSheet("QPushButton{background: transparent;}");
    ui->buttonOpenWidget_6->setStyleSheet("QPushButton{background: transparent;}");

    ui->productPrice_1->setFont(fontPrice);
    ui->productPrice_2->setFont(fontPrice);
    ui->productPrice_3->setFont(fontPrice);
    ui->productPrice_4->setFont(fontPrice);
    ui->productPrice_5->setFont(fontPrice);
    ui->productPrice_6->setFont(fontPrice);

    ui->groupBox_1->setFont(fontName);
    ui->groupBox_2->setFont(fontName);
    ui->groupBox_3->setFont(fontName);
    ui->groupBox_4->setFont(fontName);
    ui->groupBox_5->setFont(fontName);
    ui->groupBox_6->setFont(fontName);

    for(int i = 0; i < 6; i++) {
        setInformationSomeProduct(i + 1, data.getProduct(i));
    }
    this->showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInformationSomeProduct(int numberProduct, Product product) {
    switch (numberProduct) {
    case 1: {
        setInformationFirstProduct(product);
        break;
    }
    case 2: {
        setInformationSecondProduct(product);
        break;
    }
    case 3: {
        setInformationThirdProduct(product);
        break;
    }
    case 4: {
        setInformationFourthProduct(product);
        break;
    }
    case 5: {
        setInformationFifthProduct(product);
        break;
    }
    case 6: {
        setInformationSixthProduct(product);
        break;
    }
    default: {

    }
    }
}

void MainWindow::setInformationFirstProduct(Product product) {
    ui->groupBox_1->setTitle(product.getName());
    ui->productPrice_1->setText(QString::number(product.getBestPrice()));
    QPixmap pixmap(path + "/Data/Picture/Product/" + product.getName());
    ui->productPicture_1->setPixmap(pixmap);
    ui->productPicture_1->setScaledContents(true);
}

void MainWindow::setInformationSecondProduct(Product product) {
    ui->groupBox_2->setTitle(product.getName());
    ui->productPrice_2->setText(QString::number(product.getBestPrice()));
    QPixmap pixmap(path + "/Data/Picture/Product/" + product.getName());
    ui->productPicture_2->setPixmap(pixmap);
    ui->productPicture_2->setScaledContents(true);
}

void MainWindow::setInformationThirdProduct(Product product) {
    ui->groupBox_3->setTitle(product.getName());
    ui->productPrice_3->setText(QString::number(product.getBestPrice()));
    QPixmap pixmap(path + "/Data/Picture/Product/" + product.getName());
    ui->productPicture_3->setPixmap(pixmap);
    ui->productPicture_3->setScaledContents(true);
}

void MainWindow::setInformationFourthProduct(Product product) {
    ui->groupBox_4->setTitle(product.getName());
    ui->productPrice_4->setText(QString::number(product.getBestPrice()));
    QPixmap pixmap(path + "/Data/Picture/Product/" + product.getName());
    ui->productPicture_4->setPixmap(pixmap);
    ui->productPicture_4->setScaledContents(true);
}

void MainWindow::setInformationFifthProduct(Product product) {
    ui->groupBox_5->setTitle(product.getName());
    ui->productPrice_5->setText(QString::number(product.getBestPrice()));
    QPixmap pixmap(path + "/Data/Picture/Product/" + product.getName());
    ui->productPicture_5->setPixmap(pixmap);
    ui->productPicture_5->setScaledContents(true);
}

void MainWindow::setInformationSixthProduct(Product product) {
    ui->groupBox_6->setTitle(product.getName());
    ui->productPrice_6->setText(QString::number(product.getBestPrice()));
    QPixmap pixmap(path + "/Data/Picture/Product/" + product.getName());
    ui->productPicture_6->setPixmap(pixmap);
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
    productWidget = new ProductWidget();
    productWidget->add();
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

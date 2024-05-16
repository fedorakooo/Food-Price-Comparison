#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,numberPage(0), numberSort(0), ui(new Ui::MainWindow), search("")
{
    mainWidget = new QWidget(this);
    ui->setupUi(this);

    data = new Data();

    ui->radioPopularProduct->setChecked(true);

    path = QDir::currentPath();

    fillAllWidget();
    setSettingAllWidget();

    productWidget = new ProductWidget();
    basketWidget = new BasketWidget();

    category = "Категории";
    subcategory = "Подкатегории";

    {
        ui->comboBoxCategory->addItem("Категории");
        ui->comboBoxCategory->addItem("Вода, напитки, соки, кофе и чай");
        ui->comboBoxCategory->addItem("Бакалея");
        ui->comboBoxCategory->addItem("Овощи и фрукты");
        ui->comboBoxCategory->addItem("Мучные кондитерские изделия");
        ui->comboBoxCategory->addItem("Сахарные кондитерские изделия");
        ui->comboBoxCategory->addItem("Замороженные продукты");
        ui->comboBoxCategory->addItem("Молочные продукты, яйца");

        ui->comboBoxSubcategoty->addItem("Подкатегории");
    }
    numberAllPage = data->product.size() / 6;
    updatePage();

    connect(ui->buttonClose, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->buttonCollapse, &QPushButton::clicked, this, &MainWindow::showMinimized);
    connect(ui->buttonBasket, &QPushButton::clicked, basketWidget, &BasketWidget::show);
    connect(ui->buttonNextPage, &QPushButton::clicked, this, &MainWindow::nextPage);
    connect(ui->buttonPreviosPage, &QPushButton::clicked, this, &MainWindow::previousPage);
    connect(ui->comboBoxCategory, SIGNAL(currentIndexChanged(int)), this, SLOT(newCategory(int)));
    connect(ui->comboBoxSubcategoty, SIGNAL(currentIndexChanged(int)), this, SLOT(newSubcategory(int)));

    this->showFullScreen();
}

void MainWindow::newCategory(int number) {
    category = ui->comboBoxCategory->currentText();
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
            ui->comboBoxSubcategoty->addItem("Кофе молотый");
            ui->comboBoxSubcategoty->addItem("Кофе растворимый");
            ui->comboBoxSubcategoty->addItem("Соки, нектары, морсы, сиропы");
            ui->comboBoxSubcategoty->addItem("Энергетические напитки");
            break;
        }
        case 2: {
            ui->comboBoxSubcategoty->clear();
            ui->comboBoxSubcategoty->addItem("Подкатегории");
            ui->comboBoxSubcategoty->addItem("Мука, мучные смеси");
            ui->comboBoxSubcategoty->addItem("Макаронные изделия");
            ui->comboBoxSubcategoty->addItem("Крупы");
            ui->comboBoxSubcategoty->addItem("Консервация овощная, грибная");
            ui->comboBoxSubcategoty->addItem("Консервы мясные и мясорастительные");
            ui->comboBoxSubcategoty->addItem("Орехи, сухофрукты");
            ui->comboBoxSubcategoty->addItem("Растительное масло, заправки, уксус");
            ui->comboBoxSubcategoty->addItem("Готовые завтраки, хлопья и каши быстрого приготовления");
            ui->comboBoxSubcategoty->addItem("Семечки");
            ui->comboBoxSubcategoty->addItem("Сахар и заменители, соль, крахмал, сода и прочие добавки");
            ui->comboBoxSubcategoty->addItem("Специи, приправы, пряности");
            break;
        }
        case 3: {
            ui->comboBoxSubcategoty->clear();
            ui->comboBoxSubcategoty->addItem("Подкатегории");
            ui->comboBoxSubcategoty->addItem("Фрукты, ягоды");
            break;
        }
        case 4: {
            ui->comboBoxSubcategoty->clear();
            ui->comboBoxSubcategoty->addItem("Подкатегории");
            ui->comboBoxSubcategoty->addItem("Вафли");
            ui->comboBoxSubcategoty->addItem("Мучные кондитерские изделия, в том числе без глютена");
            ui->comboBoxSubcategoty->addItem("Печенье, пряничные изделия");
            break;
        }
        case 5: {
            ui->comboBoxSubcategoty->clear();
            ui->comboBoxSubcategoty->addItem("Подкатегории");
            ui->comboBoxSubcategoty->addItem("Жевательная резинка, освежающие конфеты");
            ui->comboBoxSubcategoty->addItem("Конфеты шоколадные в коробках");
            ui->comboBoxSubcategoty->addItem("Конфеты, карамель, драже, ирис");
            ui->comboBoxSubcategoty->addItem("Халва, зефир, мармелад, суфле, пастила");
            ui->comboBoxSubcategoty->addItem("Шоколад, шоколадные батончики");
            break;
        }
        case 6: {
            ui->comboBoxSubcategoty->clear();
            ui->comboBoxSubcategoty->addItem("Подкатегории");
            ui->comboBoxSubcategoty->addItem("Блинчики, пиццы и основы, лазанья, тесто и прочее (замороженные)");
            ui->comboBoxSubcategoty->addItem("Пельмени, вареники, чебуреки, равиоли, клецки и прочее (замороженные)");
            break;
        }
        case 7: {
            ui->comboBoxSubcategoty->clear();
            ui->comboBoxSubcategoty->addItem("Подкатегории");
            ui->comboBoxSubcategoty->addItem("Йогурты густые");
            ui->comboBoxSubcategoty->addItem("Йогурты питьевые, молочные коктейли и напитки (сладкие)");
            ui->comboBoxSubcategoty->addItem("Молоко");
            ui->comboBoxSubcategoty->addItem("Молоко сгущенное и концентрированное");
            ui->comboBoxSubcategoty->addItem("Сыры твердые");
            ui->comboBoxSubcategoty->addItem("Творога зерненые (с наполнителем)");
            ui->comboBoxSubcategoty->addItem("Масло сливочное");
            ui->comboBoxSubcategoty->addItem("Кефир");
            ui->comboBoxSubcategoty->addItem("Мороженое порционное");
            ui->comboBoxSubcategoty->addItem("Сырки глазированные, творожные торты");
            ui->comboBoxSubcategoty->addItem("Творога зерненые (без наполнителей)");
            ui->comboBoxSubcategoty->addItem("Яйца куриные");
            break;
        }
    }
    numberPage = 0;
    data->setProduct(category, subcategory);
    sortProduct();
    updatePage();
}

void MainWindow::newSubcategory(int number) {
    subcategory = ui->comboBoxSubcategoty->currentText();
    data->setProduct(category, subcategory);
    numberPage = 0;
    sortProduct();
    updatePage();
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
    numberAllPage = data->product.size() / 6;
    updateDataMainWindow();
    updateProductsMainWindow();
    ui->labelNumberPage->setText(QString::number(numberPage + 1) + "/" + QString::number(numberAllPage));
}

void MainWindow::on_buttonSearchProduct_clicked()
{
    search = ui->lineSearch->text();
    data->setProduct(category, subcategory, search);
    numberPage = 0;
    numberAllPage = data->product.size() / 6;
    updatePage();
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

void MainWindow::on_radioPopularProduct_clicked()
{
    numberSort = 0;
    data->setPopularProduct(category, subcategory);
    updatePage();
}

void MainWindow::on_radioIncreasingName_clicked()
{
    numberSort = 1;
    ProductSort::threeWayQuickSortIncrease(&data->product, 0, data->product.size() - 1);
    updatePage();
}

void MainWindow::on_radioReductionName_clicked()
{
    numberSort = 2;
    ProductSort::threeWayQuickSortDecrease(&data->product, 0, data->product.size() - 1);
    updatePage();
}

void MainWindow::on_radioIncreasingPrice_clicked()
{
    numberSort = 3;
    ProductSort::timsortIncrease(&(data->product));
    updatePage();
}


void MainWindow::on_radioReductionPrice_clicked()
{
    numberSort = 4;
    ProductSort::timsortDecrease(&(data->product));
    updatePage();
}

void MainWindow::on_pushButton_clicked()
{
    search = "";
    ui->lineSearch->clear();
    data->setPopularProduct(category, subcategory);
    updatePage();
}

void MainWindow::sortProduct() {
    switch(numberSort) {
        case 0: {
            on_radioPopularProduct_clicked();
            break;
        }
        case 1: {
            on_radioIncreasingName_clicked();
            break;
        }
        case 2: {
            on_radioReductionName_clicked();
            break;
        }
        case 3: {
            on_radioIncreasingPrice_clicked();
            break;
        }
        case 4: {
            on_radioReductionPrice_clicked();
            break;
        }
    }
}


#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "logic/productsort.h"
#include "logic/projectappearance.h"
#include "logic/stringformatter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    mainWidget(new QWidget(this)),
    productWidget(new ProductWidget()),
    basketWidget(new BasketWidget()),
    data(new Data()),
    numberPage(0),
    search(""),
    ui(new Ui::MainWindow),
    numberSort(0)
{
    ui->setupUi(this);
    setupButtonConnections();
    setupOpenWidgetButtonConnections();
    setupUiElements();
    setupBackground();
    setupCompleter();
    setupConnections();

    numberAllPage = data->product.size() / SIZE_PRODUCTS;
    updatePage();
    showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUiElements()
{
    ui->radioPopularProduct->setChecked(true);
    path = QDir::currentPath();
    wordList = new QStringList();
    fillAllWidget();
    setSettingAllWidget();
}

void MainWindow::setupBackground()
{
    QPixmap background("./image/fon");
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(background));
    setPalette(palette);
}

// Initialize the AutoFill for search fields based on categories and subcategories.
void MainWindow::setupCompleter()
{
    setCategory();
    completer = new QCompleter(data->getWordList(category, subcategory), this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineSearch->setCompleter(completer);
}

// Connect the signals of different interface buttons with corresponding slots
void MainWindow::setupConnections()
{
    connect(ui->buttonClose, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->buttonCollapse, &QPushButton::clicked, this, &MainWindow::showMinimized);
    connect(ui->buttonBasket, &QPushButton::clicked, basketWidget, &BasketWidget::show);
    connect(ui->buttonNextPage, &QPushButton::clicked, this, &MainWindow::nextPage);
    connect(ui->buttonPreviosPage, &QPushButton::clicked, this, &MainWindow::previousPage);
    connect(ui->comboBoxCategory, SIGNAL(currentIndexChanged(int)), this, SLOT(newCategory(int)));
    connect(ui->comboBoxSubcategoty, SIGNAL(currentIndexChanged(int)), this, SLOT(newSubcategory(int)));
}

void MainWindow::newCategory(int number) {
    category = ui->comboBoxCategory->currentText();

    QMap<int, QStringList> subcategories = {
        {0, {"Подкатегории"}},
        {1, {"Подкатегории", "Вода минеральная, питьевая", "Чай, чайные напитки",
             "Напитки, напитки сокосодержащие", "Кофе в зернах", "Кофе молотый",
             "Кофе растворимый", "Соки, нектары, морсы, сиропы", "Энергетические напитки"}},
        {2, {"Подкатегории", "Мука, мучные смеси", "Макаронные изделия", "Крупы",
             "Консервация овощная, грибная", "Консервы мясные и мясорастительные",
             "Орехи, сухофрукты", "Растительное масло, заправки, уксус",
             "Готовые завтраки, хлопья и каши быстрого приготовления", "Семечки",
             "Сахар и заменители, соль, крахмал, сода и прочие добавки",
             "Специи, приправы, пряности"}},
        {3, {"Подкатегории", "Фрукты, ягоды"}},
        {4, {"Подкатегории", "Вафли", "Мучные кондитерские изделия, в том числе без глютена",
             "Печенье, пряничные изделия"}},
        {5, {"Подкатегории", "Жевательная резинка, освежающие конфеты",
             "Конфеты шоколадные в коробках", "Конфеты, карамель, драже, ирис",
             "Халва, зефир, мармелад, суфле, пастила", "Шоколад, шоколадные батончики"}},
        {6, {"Подкатегории", "Блинчики, пиццы и основы, лазанья, тесто и прочее (замороженные)",
             "Пельмени, вареники, чебуреки, равиоли, клецки и прочее (замороженные)"}},
        {7, {"Подкатегории", "Йогурты густые", "Йогурты питьевые, молочные коктейли и напитки (сладкие)",
             "Молоко", "Молоко сгущенное и концентрированное", "Сыры твердые",
             "Творога зерненые (с наполнителем)", "Масло сливочное", "Кефир",
             "Мороженое порционное", "Сырки глазированные, творожные торты",
             "Творога зерненые (без наполнителей)", "Яйца куриные"}}
    };

    ui->comboBoxSubcategoty->clear();
    ui->comboBoxSubcategoty->addItems(subcategories.value(number, QStringList() << "Подкатегории"));

    numberPage = 0;
    data->setPopularProduct(category, ui->comboBoxSubcategoty->currentText());
    sortProducts();
    updatePage();
    updateCompleter();
}

void MainWindow::newSubcategory(int number) {
    subcategory = ui->comboBoxSubcategoty->currentText();
    data->setPopularProduct(category, subcategory);
    numberPage = 0;
    sortProducts();
    updatePage();
    updateCompleter();
}

void MainWindow::setCategory() {
    ui->comboBoxCategory->addItem("Категории");
    for (int i = 0; i < SIZE_PRODUCTS; i++) {
        ui->comboBoxCategory->addItem(data->ARR_CATEGORY[i]);
    }
    ui->comboBoxSubcategoty->addItem("Подкатегории");
    category = "Категории";
    subcategory = "Подкатегории";
}

// Update autocomplete with new word list
void MainWindow::updateCompleter() {
    completer = new QCompleter(data->getWordList(category, subcategory), this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineSearch->setCompleter(completer);
}

void MainWindow::fillArrLabelPrice() {
    for (int i = 1; i <= 6; i++) {
        arrLabelPrice.push_back(this->findChild<QLabel*>(QString("productPrice_%1").arg(i)));
    }
}

void MainWindow::fillArrLabelPicture() {
    for (int i = 1; i <= 6; i++) {
        arrLabelPicture.push_back(this->findChild<QLabel*>(QString("productPicture_%1").arg(i)));
    }
}

void MainWindow::fillArrGroupBox() {
    for (int i = 1; i <= 6; i++) {
        arrGroupBox.push_back(this->findChild<QGroupBox*>(QString("groupBox_%1").arg(i)));
    }
}

void MainWindow::fillComboBox() {
    const QStringList categories = {
        "Категории",
        "Вода, напитки, соки, кофе и чай",
        "Бакалея",
        "Овощи и фрукты",
        "Мучные кондитерские изделия",
        "Сахарные кондитерские изделия",
        "Замороженные продукты",
        "Молочные продукты, яйца"
    };
    ui->comboBoxCategory->addItems(categories);
    ui->comboBoxSubcategoty->addItem("Подкатегории");
}

void MainWindow::fillArrButtonOpenProductWidget() {
    for (int i = 1; i <= 6; ++i) {
        QString buttonName = QString("buttonOpenWidget_%1").arg(i);
        QPushButton* button = this->findChild<QPushButton*>(buttonName);
        if (button) {
            arrButtonOpenProductWidget.push_back(button);
        } else {
            qDebug() << "Button not found:" << buttonName;
        }
    }
}

void MainWindow::updateProductsMainWindow() {
    for (int i = 0; i < SIZE_PRODUCTS; i++) {
        setInformationSomeProduct(i, arrProductMainWindow[i]);
    }
}

void MainWindow::fillAllWidget() {
    fillArrLabelPicture();
    fillArrLabelPrice();
    fillArrButtonOpenProductWidget();
    fillArrGroupBox();
    fillArrButtonAddProductBasket();
}

void MainWindow::fillArrButtonAddProductBasket() {
    for (int i = 1; i <= 6; ++i) {
        QString buttonName = QString("buttonAddProduct_%1").arg(i);
        QPushButton* button = this->findChild<QPushButton*>(buttonName);

        if (button) {
            arrButtonAddProductBasket.push_back(button);
        } else {
            qDebug() << "Button not found:" << buttonName;
        }
    }
}

// Apply the appearance settings to the interface widgets
void MainWindow::setSettingAllWidget() {
    ProjectAppearance::setSettingFontPrice(arrLabelPrice);
    ProjectAppearance::setSettingButtonsOpenProductWidget(arrButtonOpenProductWidget);
    ProjectAppearance::setSettingFontName(arrGroupBox);
    ProjectAppearance::setSettingFontPicture(arrLabelPicture);
}

// Updates the interface elements of a specific product
void MainWindow::setInformationSomeProduct(int number, Product* product) {
    arrGroupBox[number]->setTitle(product->getName());
    QString bestPrice = StringFormatter::formatPrice(QString::number(product->getBestPrice()));
    if (bestPrice == "-1") {
        arrLabelPrice[number]->setText("");
    } else {
        arrLabelPrice[number]->setText(bestPrice);
    }
    arrLabelPicture[number]->setPixmap(QPixmap(path + DIRECTORY_IMAGE + product->getFileName()));
}

void MainWindow::on_buttonAddProduct_clicked(int index) {
    if (index >= 0 && index < SIZE_PRODUCTS) {
        if (!arrProductMainWindow[index]->getName().isEmpty()) {
            basketWidget->addProductBasket(arrProductMainWindow[index]);
        }
    } else {
        qWarning() << "Index out of bounds for adding product to basket:" << index;
    }
}

// Update the array of displayed products based on current page
void MainWindow::updateDataMainWindow() {
    for (int i = numberPage * SIZE_PRODUCTS; i < data->product.size() && i < (numberPage * SIZE_PRODUCTS + SIZE_PRODUCTS); i++) {
        arrProductMainWindow[i % SIZE_PRODUCTS] = data->product[i];
    }
}

void MainWindow::nextPage() {
    if (numberPage < numberAllPage - 1) {
        numberPage++;
        updatePage();
    }
}

void MainWindow::previousPage() {
    if (numberPage > 0) {
        numberPage--;
        updatePage();
    }
}

// Update products displayed on current page
void MainWindow::updatePage() {
    numberAllPage = data->product.size() / SIZE_PRODUCTS;
    updateDataMainWindow();

    if (data->product.isEmpty()) {
        for (int i = 0; i < SIZE_PRODUCTS; i++) {
            arrProductMainWindow[i] = new Product();
        }
    }

    updateProductsMainWindow();
    updateVisibleButton();
    if (numberAllPage == 0)
        numberAllPage++;
    ui->labelNumberPage->setText(QString::number(numberPage + 1) + "/" + QString::number(numberAllPage));
}

void MainWindow::updateVisibleButton() {
    for (int i = 0; i < SIZE_PRODUCTS; i++) {
        if (arrProductMainWindow[i]->getName() == "") {
            arrGroupBox[i]->setVisible(false);
        } else {
            arrGroupBox[i]->setVisible(true);
        }
    }
}

// Process key presses for search functionality
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == SEARCH_BUTTON_CODE) {
        on_buttonSearchProduct_clicked();
    }
}

void MainWindow::on_buttonSearchProduct_clicked() {
    QString newSearch = ui->lineSearch->text();
    if (newSearch != search) {
        search = newSearch;
        data->setProduct(category, subcategory, search);
    }
    numberPage = 0;
    numberAllPage = data->product.size() / SIZE_PRODUCTS;
    updatePage();
}

void MainWindow::on_buttonOpenWidget_clicked(int index) {
    if (index >= 0 && index < SIZE_PRODUCTS) {
        if (!arrProductMainWindow[index]->getName().isEmpty()) {
            productWidget->add(arrProductMainWindow[index]);
        }
    } else {
        qWarning() << "Index out of bounds for opening product widget:" << index;
    }
}

void MainWindow::setupButtonConnections() {
    for (int i = 1; i <= SIZE_PRODUCTS; ++i) {
        QPushButton* button = this->findChild<QPushButton*>(QString("buttonAddProduct_%1").arg(i));
        if (button) {
            connect(button, &QPushButton::clicked, [this, i]() { on_buttonAddProduct_clicked(i - 1); });
        } else {
            qWarning() << "Button not found:" << QString("buttonAddProduct_%1").arg(i);
        }
    }
}

void MainWindow::setupOpenWidgetButtonConnections() {
    for (int i = 1; i <= SIZE_PRODUCTS; ++i) {
        QPushButton* button = this->findChild<QPushButton*>(QString("buttonOpenWidget_%1").arg(i));
        if (button) {
            connect(button, &QPushButton::clicked, [this, i]() { on_buttonOpenWidget_clicked(i - 1); });
        } else {
            qWarning() << "Button not found:" << QString("buttonOpenWidget_%1").arg(i);
        }
    }
}

void MainWindow::on_radioPopularProduct_clicked() {
    numberSort = 0;
    updateProductData();
}

void MainWindow::on_radioIncreasingName_clicked() {
    numberSort = 1;
    sortProducts();
}

void MainWindow::on_radioReductionName_clicked() {
    numberSort = 2;
    sortProducts();
}

void MainWindow::on_radioIncreasingPrice_clicked() {
    numberSort = 3;
    sortProducts();
}

void MainWindow::on_radioReductionPrice_clicked() {
    numberSort = 4;
    sortProducts();
}

// Clears the search box and drops the view to display popular products
void MainWindow::on_pushButton_clicked() {
    search = "";
    ui->lineSearch->clear();
    numberPage = 0;
    updateProductData();
}

void MainWindow::updateProductData() {
    if (search.isEmpty()) {
        data->setPopularProduct(category, subcategory);
    } else {
        data->setProduct(category, subcategory, search);
    }
    updatePage();
}

// Sort the list of products based on selected criteria
void MainWindow::sortProducts() {
    data->deleteNoProduct();
    numberPage = 0;

    switch (numberSort) {
    case 1:
        ProductSort::threeWayQuickSortIncrease(&data->product, 0, data->product.size() - 1);
        break;
    case 2:
        ProductSort::threeWayQuickSortDecrease(&data->product, 0, data->product.size() - 1);
        break;
    case 3:
        ProductSort::timsortIncrease(&data->product);
        break;
    case 4:
        ProductSort::timsortDecrease(&data->product);
        break;
    default:
        break;
    }

    data->doProductMultiples();
    updatePage();
}

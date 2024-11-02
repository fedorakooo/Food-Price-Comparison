#include "data.h"

#include "logic/productfinder.h"

Data::Data() {
    initializeDatabase();
    randomGenerator = new QRandomGenerator(QDateTime::currentMSecsSinceEpoch());
    query = new QSqlQuery(db);
    createProductsTable();
    initializeCategories();
    setPopularProduct("Категории", "Подкатегории");
    setWordListCategory();
}

Data::~Data() {
    delete query;
    delete randomGenerator;
}

void Data::initializeDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./product.db");

    if (!db.open()) {
        qDebug() << "Error opening QSQLite database:";
    }
}

void Data::createProductsTable() {
    const QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS Products (
            id INTEGER PRIMARY KEY,
            name TEXT NOT NULL,
            category TEXT NOT NULL,
            picture TEXT NOT NULL,
            url TEXT NOT NULL,
            first_price TEXT NOT NULL,
            second_price TEXT NOT NULL,
            third_price TEXT NOT NULL,
            fourth_price TEXT NOT NULL,
            fifth_price TEXT NOT NULL,
            sixth_price TEXT NOT NULL,
            seventh_price TEXT NOT NULL
        )
    )";

    if (!query->exec(createTableQuery)) {
        qDebug() << "Error creating Products table";
    }
}

void Data::initializeCategories() {
    ArrSubcategory = {{
        {"Вода минеральная, питьевая", "Чай, чайные напитки", "Напитки, напитки сокосодержащие", "Кофе в зернах", "Кофе молотый", "Кофе растворимый", "Соки, нектары, морсы, сиропы", "Энергетические напитки"},
        {"Мука, мучные смеси", "Макаронные изделия", "Крупы", "Консервация овощная, грибная", "Консервы мясные и мясорастительные", "Орехи, сухофрукты", "Растительное масло, заправки, уксус", "Готовые завтраки, хлопья и каши быстрого приготовления", "Семечки", "Сахар и заменители, соль, крахмал, сода и прочие добавки", "Специи, приправы, пряности"},
        {"Фрукты, ягоды"},
        {"Вафли", "Мучные кондитерские изделия, в том числе без глютена", "Печенье, пряничные изделия"},
        {"Жевательная резинка, освежающие конфеты", "Конфеты шоколадные в коробках", "Конфеты, карамель, драже, ирис", "Халва, зефир, мармелад, суфле, пастила", "Шоколад, шоколадные батончики"},
        {"Блинчики, пиццы и основы, лазанья, тесто и прочее (замороженные)", "Пельмени, вареники, чебуреки, равиоли, клецки и прочее (замороженные)"},
        {"Йогурты густые", "Йогурты питьевые, молочные коктейли и напитки (сладкие)", "Молоко", "Молоко сгущенное и концентрированное", "Сыры твердые", "Творога зерненые (с наполнителем)", "Масло сливочное", "Кефир", "Мороженое порционное", "Сырки глазированные, творожные торты", "Творога зерненые (без наполнителей)", "Яйца куриные"}
    }};

    mapCategory = {
        {"Вода, напитки, соки, кофе и чай", {1, 360}},
        {"Бакалея", {360, 853}},
        {"Овощи и фрукты", {853, 858}},
        {"Мучные кондитерские изделия", {858, 992}},
        {"Сахарные кондитерские изделия", {992, 1217}},
        {"Замороженные продукты", {1217, 1307}},
        {"Молочные продукты, яйца", {1307, 1830}}
    };
}

// Populates the current list of products according to the given category and subcategory
void Data::setProduct(const QString& category, const QString& subcategory) {
    product.clear();

    if (category == "Категории") {
        loadAllProducts();
    } else if (subcategory == "Подкатегории") {
        loadProductsByCategory(category);
    } else {
        loadProductsBySubcategory(subcategory);
    }

    doProductMultiples();
}

// Populate the current list of products according to the given category, subcategory and search query
void Data::setProduct(const QString& category, const QString& subcategory, const QString& substr) {
    if (substr.isEmpty()) {
        setPopularProduct(category, subcategory);
        return;
    }

    product.clear();
    if (category == "Категории") {
        loadProducts("");
    } else if (subcategory == "Подкатегории") {
        loadProductsByCategory(category);
    } else {
        loadProductsBySubcategory(subcategory, substr);
    }

    doProductMultiples();
}

void Data::loadAllProducts() {
    query->exec("SELECT * FROM Products");
    while (query->next()) {
        product.push_back(createProductFromQuery());
    }
}

void Data::loadProductsByCategory(const QString& category) {
    auto it = mapCategory.find(category);
    if (it != mapCategory.end()) {
        int start = it->second.first;
        int end = it->second.second;

        for (int i = 0; i < 42 && start < end; ++i, ++start) {
            query->exec("SELECT * FROM Products WHERE id = " + QString::number(start));
            if (query->next()) {
                product.push_back(createProductFromQuery());
            }
        }
    }
}

void Data::loadProductsBySubcategory(const QString& subcategory) {
    query->exec("SELECT * FROM Products WHERE subcategory = '" + subcategory + "'");
    while (query->next()) {
        product.push_back(createProductFromQuery());
    }
}

void Data::loadProducts(const QString& substr) {
    query->exec("SELECT * FROM Products");
    while (query->next()) {
        QString name = query->value(1).toString();
        if (ProductFinder::searchKMP(name, substr)) {
            product.push_back(createProductFromQuery());
        }
    }
}

void Data::loadProductsBySubcategory(const QString& subcategory, const QString& substr) {
    query->exec("SELECT * FROM Products WHERE subcategory = '" + subcategory + "'");
    while (query->next()) {
        QString name = query->value(1).toString();
        if (ProductFinder::searchKMP(name, substr)) {
            product.push_back(createProductFromQuery());
        }
    }
}

// Define how to set popular products based on input category and subcategory
void Data::setPopularProduct(QString _category, QString _subcategory) {
    product.clear();

    if (_category == "Категории") {
        handleCategoryProducts();
    } else if (_subcategory == "Подкатегории") {
        handleSubcategoryProducts(_category);
    } else {
        setProduct(_category, _subcategory);
    }

    doProductMultiples();
}

// Handle selection of popular products across all categories
void Data::handleCategoryProducts() {
    QSet<int> set;

    while (set.size() < 42) {
        QString subcategory = getRandomSubcategoryForAnyCategory();
        int numberRandom = randomGenerator->bounded(0, RANGE);
        query->exec("SELECT id FROM Products WHERE subcategory = '" + subcategory + "'");

        if (query->next()) {
            int numberFirstElement = query->value(0).toInt() + numberRandom;
            set.insert(numberFirstElement);
        }
    }

    fetchProductsFromIds(set);
}

// Manage the selection of popular products within a specific category
void Data::handleSubcategoryProducts(const QString& category) {
    QSet<int> set;
    auto it = mapCategory.find(category);

    if (it != mapCategory.end()) {
        int start = it->second.first;
        int end = it->second.second;

        if (end - start < 2 * SIZE_SET_POPULAR_PRODUCTS) {
            setProduct(category, "Подкатегории");
        } else {
            while (set.size() < SIZE_SET_POPULAR_PRODUCTS) {
                QString subcategory = getRandomSubcategory(category);
                int numberRandom = randomGenerator->bounded(0, RANGE);
                query->exec("SELECT * FROM Products WHERE subcategory = '" + subcategory + "'");

                if (query->next()) {
                    int numberFirstElement = query->value(0).toInt() + numberRandom;
                    set.insert(numberFirstElement);
                }
            }
        }
    }
    fetchProductsFromIds(set);
}

QString Data::getRandomSubcategoryForAnyCategory() {
    int numberCategory = randomGenerator->bounded(NUMBER_CATEGORY);
    int numberSubcategory = randomGenerator->bounded(ARR_SIZE_CATEGORY[numberCategory]);
    return ArrSubcategory[numberCategory][numberSubcategory];
}

QString Data::getRandomSubcategory(const QString& category) {
    int numberCategory = getNumberNameCategory(category);
    int numberSubcategory = randomGenerator->bounded(ARR_SIZE_CATEGORY[numberCategory]);
    return ArrSubcategory[numberCategory][numberSubcategory];
}

// Retrieves products from the database using ID sets
void Data::fetchProductsFromIds(const QSet<int>& ids) {
    for (const int id : ids) {
        query->exec("SELECT * FROM Products WHERE id = " + QString::number(id));
        query->next();
        product.push_back(createProductFromQuery());
    }
}

// Product quantity adjustment
void Data::doProductMultiples() {
    while(product.size() % (NUMBER_CATEGORY - 1) != 0) {
        product.push_back(new Product());
    }
}

// Remove from list of non-eligible products
void Data::deleteNoProduct() {
    while(!product.isEmpty() && product.back()->getBestPrice() == -1) {
        product.pop_back();
    }
}

// Create Product object from current SQL query result
Product* Data::createProductFromQuery() {
    QString name = query->value(1).toString();
    QString category = query->value(2).toString();
    QString subcategory = query->value(3).toString();
    QString file = query->value(4).toString();
    QVector<double> prices(NUMBER_CATEGORY);

    for (int i = 0; i < NUMBER_CATEGORY; ++i) {
        QString number = query->value(6 + i).toString();
        prices[i] = (number == '-') ? -1 : number.toDouble();
    }

    return new Product(name, prices, file, category, subcategory);
}

// Return category index based on category name
int Data::getNumberNameCategory(QString category) {
    for(int i = 0; i < NUMBER_CATEGORY; i++) {
        if(ARR_CATEGORY[i] == category) {
            return i;
        }
    }
    return -1;
}

// Fill in the word list for categories
void Data::setWordListCategory() {
    QStringList list;
    query->exec("SELECT name FROM Products");
    while(query->next()) {
        list.push_back(query->value(0).toString());
    }
    wordListCategory.push_back(list);
    for(int i = 0; i < NUMBER_CATEGORY; i++) {
        QStringList list;
        query->exec("SELECT name FROM Products WHERE category = '" + ARR_CATEGORY[i] + "'");
        while(query->next()) {
            list.push_back(query->value(0).toString());
        }
        wordListCategory.push_back(list);
    }
}

// Return a list of words for the given category and subcategory
QStringList Data::getWordList(QString category, QString subcategory) {
    if(subcategory == "Подкатегории") {
        if(category == "Категории") {
            return wordListCategory[0];
        }
        else {
            for(int i = 0; i < NUMBER_CATEGORY; i++) {
                if(ARR_CATEGORY[i] == category) {
                    return wordListCategory[i + 1];
                }
            }
        }
    }
    return QStringList();
}

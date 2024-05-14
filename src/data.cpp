#include "data.h"

Data::Data() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./product.db");

    if(!db.open()) {
        qDebug() << "Error QSQLite";
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Products (id INTEGER PRIMARY KEY, name TEXT NOT NULL, category TEXT NOT NULL, picture TEXT NOT NULL, url TEXT NOT NULL, first_price TEXT NOT NULL, second_price TEXT NOT NULL, third_price TEXT NOT NULL, fourth_price TEXT NOT NULL, fifth_price TEXT NOT NULL, sixth_price TEXT NOT NULL, seventh_price TEXT NOT NULL)");
    product = setAllProduct();
}

QVector<Product*> Data::setAllProduct() {
    query->exec("SELECT * FROM Products");
    QVector<Product*> product;
    while (query->next()) {
        QString name = query->value(1).toString();
        QString category = query->value(2).toString();
        QString subcategory = query->value(3).toString();
        QString file = query->value(4).toString();
        double* price = new double[7];
        for(int i = 0; i < 7; i++) {
            bool ok;
            QString number = query->value(6+i).toString();
            if(number == '-') {
                price[i] = -1;
            }
            else {
                price[i] = number.toDouble(&ok);
            }
        }
        product.push_back(new Product(name, price, file, category, subcategory));
    }
    return product;
}

void Data::setProduct(QString _category, QString _subcategory, QString substr) {
    query->exec("SELECT * FROM Products");
    product.clear();
    while (query->next()) {
            qDebug() << "Yes";
            QString name = query->value(1).toString();
            if(StringProcessing::searchKMP(name, substr)) {
            QString category = query->value(2).toString();
            QString subcategory = query->value(3).toString();
            QString file = query->value(4).toString();
            double* price = new double[7];
            for(int i = 0; i < 7; i++) {
                bool ok;
                QString number = query->value(6+i).toString();
                if(number == '-') {
                    price[i] = -1;
                }
                else {
                    price[i] = number.toDouble(&ok);
                }
            }
            product.push_back(new Product(name, price, file, category, subcategory));
        }
    }
}

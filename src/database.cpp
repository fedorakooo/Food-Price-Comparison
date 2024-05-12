#include "database.h"
#include "ui_database.h"

DataBase::DataBase(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DataBase)
{
    ui->setupUi(this);
    this->show();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./product.db");
    if(db.open()) {
        qDebug() << 1;
    }
    else {
        qDebug() << 0;
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Product(name TEXT, picture TEXT, category TEXT, first_price DOUBLE, second_price DOUBLE, third_price DOUBLE, fourth_price DOUBLE, fifth_price DOUBLE, sixth_price DOUBLE, seventh_price DOUBLE);");
    model = new QSqlTableModel(this, db);
    model->setTable("Product");
    model->select();
    int newRow = model->rowCount();
    model->insertRow(newRow);
    model->setData(model->index(newRow, 0), "Вода минеральная Минск-4 газированная 1л РБ");
    model->setData(model->index(newRow, 1), "https://img.infoprice.by/256/1549/000011549/norm/000011549.n_1.png");
    model->setData(model->index(newRow, 2), "Вода минеральная, питьевая");
    model->setData(model->index(newRow, 3), 1.52);
    model->setData(model->index(newRow, 4), 1.32);
    model->setData(model->index(newRow, 5), 0.99);
    model->setData(model->index(newRow, 6), 1.42);
    model->setData(model->index(newRow, 7), 1.39);
    model->setData(model->index(newRow, 8), 1.29);
    model->setData(model->index(newRow, 9), 1.80);
    model->submitAll();

    ui->tableView->setModel(model);

}

DataBase::~DataBase()
{
    delete ui;
}

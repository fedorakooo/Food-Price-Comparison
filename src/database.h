#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class DataBase;
}

class DataBase : public QWidget
{
    Q_OBJECT
    QSqlDatabase db;
    QSqlQuery* query;
    QSqlTableModel* model;

public:
    explicit DataBase(QWidget *parent = nullptr);
    ~DataBase();

private:
    Ui::DataBase *ui;
};

#endif // DATABASE_H

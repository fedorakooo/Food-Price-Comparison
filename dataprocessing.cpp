#include "dataprocessing.h"

DataProcessing::DataProcessing() {
    QString buildPath = QCoreApplication::applicationDirPath();
    QString path = "";
    for(int i = 0; i < buildPath.size() - 48; i++) {
        path += buildPath[i];
    }
    file = new QFile(path + "/Data/TextInformation/products.txt");
    addSetProduct();
}

void DataProcessing::addSetProduct() {
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
    }
    else {
        QTextStream in(file);
        while (!in.atEnd()) {
            QString information = in.readLine();
            QString name = "";
            double arrPrice[7] = {};
            int i = 0;
            for(; i < information.size() && information[i] != ' '; i++) {
                name += information[i];
            }
            i++;
            for(int k = 0; i < information.size() && k < 7; i++) {
                if(information[i] != ' ') {
                    QString t = "";
                    for(; i < information.size() && information[i] != ' '; i++) {
                        t += information[i];
                    }
                    arrPrice[k] = t.toDouble();
                    k++;
                }
            }
            vectorProduct.push_back(Product(name, arrPrice));
        }
    }
}

Product DataProcessing::getProduct(int number) {
    return vectorProduct[number];
}

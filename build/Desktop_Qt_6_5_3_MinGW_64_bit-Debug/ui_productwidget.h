/********************************************************************************
** Form generated from reading UI file 'productwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTWIDGET_H
#define UI_PRODUCTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductWidget
{
public:
    QLabel *nameProduct;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelShop_1;
    QLabel *labelShop_2;
    QLabel *labelShop_3;
    QLabel *labelShop_4;
    QLabel *labelShop_5;
    QLabel *labelShop_6;
    QLabel *labelShop_7;
    QVBoxLayout *verticalLayout;
    QLabel *labelPriceFirstShop;
    QLabel *labelPriceSecondShop;
    QLabel *labelPriceThirdShop;
    QLabel *labelPriceFourthShop;
    QLabel *labelPriceFifthShop;
    QLabel *labelPriceSixthShop;
    QLabel *labelPriceSeventhShop;
    QLabel *categoryProduct;
    QLabel *label;

    void setupUi(QWidget *ProductWidget)
    {
        if (ProductWidget->objectName().isEmpty())
            ProductWidget->setObjectName("ProductWidget");
        ProductWidget->resize(1054, 602);
        nameProduct = new QLabel(ProductWidget);
        nameProduct->setObjectName("nameProduct");
        nameProduct->setGeometry(QRect(610, 10, 551, 51));
        horizontalLayoutWidget = new QWidget(ProductWidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(610, 130, 401, 441));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelShop_1 = new QLabel(horizontalLayoutWidget);
        labelShop_1->setObjectName("labelShop_1");

        verticalLayout_2->addWidget(labelShop_1);

        labelShop_2 = new QLabel(horizontalLayoutWidget);
        labelShop_2->setObjectName("labelShop_2");

        verticalLayout_2->addWidget(labelShop_2);

        labelShop_3 = new QLabel(horizontalLayoutWidget);
        labelShop_3->setObjectName("labelShop_3");

        verticalLayout_2->addWidget(labelShop_3);

        labelShop_4 = new QLabel(horizontalLayoutWidget);
        labelShop_4->setObjectName("labelShop_4");

        verticalLayout_2->addWidget(labelShop_4);

        labelShop_5 = new QLabel(horizontalLayoutWidget);
        labelShop_5->setObjectName("labelShop_5");

        verticalLayout_2->addWidget(labelShop_5);

        labelShop_6 = new QLabel(horizontalLayoutWidget);
        labelShop_6->setObjectName("labelShop_6");

        verticalLayout_2->addWidget(labelShop_6);

        labelShop_7 = new QLabel(horizontalLayoutWidget);
        labelShop_7->setObjectName("labelShop_7");

        verticalLayout_2->addWidget(labelShop_7);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        labelPriceFirstShop = new QLabel(horizontalLayoutWidget);
        labelPriceFirstShop->setObjectName("labelPriceFirstShop");

        verticalLayout->addWidget(labelPriceFirstShop);

        labelPriceSecondShop = new QLabel(horizontalLayoutWidget);
        labelPriceSecondShop->setObjectName("labelPriceSecondShop");

        verticalLayout->addWidget(labelPriceSecondShop);

        labelPriceThirdShop = new QLabel(horizontalLayoutWidget);
        labelPriceThirdShop->setObjectName("labelPriceThirdShop");

        verticalLayout->addWidget(labelPriceThirdShop);

        labelPriceFourthShop = new QLabel(horizontalLayoutWidget);
        labelPriceFourthShop->setObjectName("labelPriceFourthShop");

        verticalLayout->addWidget(labelPriceFourthShop);

        labelPriceFifthShop = new QLabel(horizontalLayoutWidget);
        labelPriceFifthShop->setObjectName("labelPriceFifthShop");

        verticalLayout->addWidget(labelPriceFifthShop);

        labelPriceSixthShop = new QLabel(horizontalLayoutWidget);
        labelPriceSixthShop->setObjectName("labelPriceSixthShop");

        verticalLayout->addWidget(labelPriceSixthShop);

        labelPriceSeventhShop = new QLabel(horizontalLayoutWidget);
        labelPriceSeventhShop->setObjectName("labelPriceSeventhShop");

        verticalLayout->addWidget(labelPriceSeventhShop);


        horizontalLayout->addLayout(verticalLayout);

        categoryProduct = new QLabel(ProductWidget);
        categoryProduct->setObjectName("categoryProduct");
        categoryProduct->setGeometry(QRect(610, 70, 271, 41));
        label = new QLabel(ProductWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 561, 561));

        retranslateUi(ProductWidget);

        QMetaObject::connectSlotsByName(ProductWidget);
    } // setupUi

    void retranslateUi(QWidget *ProductWidget)
    {
        ProductWidget->setWindowTitle(QCoreApplication::translate("ProductWidget", "Form", nullptr));
        nameProduct->setText(QCoreApplication::translate("ProductWidget", "\320\230\320\274\321\217 \321\202\320\276\320\262\320\260\321\200\320\260", nullptr));
        labelShop_1->setText(QCoreApplication::translate("ProductWidget", "Emall.by", nullptr));
        labelShop_2->setText(QCoreApplication::translate("ProductWidget", "\320\241\320\276\321\201\320\265\320\264\320\270", nullptr));
        labelShop_3->setText(QCoreApplication::translate("ProductWidget", "\320\232\320\276\321\200\320\276\320\275\320\260", nullptr));
        labelShop_4->setText(QCoreApplication::translate("ProductWidget", "\320\241\320\260\320\275\321\202\320\260", nullptr));
        labelShop_5->setText(QCoreApplication::translate("ProductWidget", "\320\225\320\262\321\200\320\276\320\276\320\277\321\202", nullptr));
        labelShop_6->setText(QCoreApplication::translate("ProductWidget", "\320\223\320\270\320\277\320\277\320\276", nullptr));
        labelShop_7->setText(QCoreApplication::translate("ProductWidget", "Green", nullptr));
        labelPriceFirstShop->setText(QCoreApplication::translate("ProductWidget", "\320\246\320\265\320\275\320\260", nullptr));
        labelPriceSecondShop->setText(QCoreApplication::translate("ProductWidget", "\320\246\320\265\320\275\320\260", nullptr));
        labelPriceThirdShop->setText(QCoreApplication::translate("ProductWidget", "\320\246\320\265\320\275\320\260", nullptr));
        labelPriceFourthShop->setText(QCoreApplication::translate("ProductWidget", "\320\246\320\265\320\275\320\260", nullptr));
        labelPriceFifthShop->setText(QCoreApplication::translate("ProductWidget", "\320\246\320\265\320\275\320\260", nullptr));
        labelPriceSixthShop->setText(QCoreApplication::translate("ProductWidget", "\320\246\320\265\320\275\320\260", nullptr));
        labelPriceSeventhShop->setText(QCoreApplication::translate("ProductWidget", "\320\246\320\265\320\275\320\260", nullptr));
        categoryProduct->setText(QCoreApplication::translate("ProductWidget", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217 \321\202\320\276\320\262\320\260\321\200\320\260", nullptr));
        label->setText(QCoreApplication::translate("ProductWidget", "Picture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductWidget: public Ui_ProductWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTWIDGET_H

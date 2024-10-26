QT += core gui
QT += widgets
QT += sql
QT += core
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    widgets/basketwidget/basketwidget.cpp \
    data_processing/data.cpp \
    main.cpp \
    widgets/mainwindow/mainwindow.cpp \
    logic/product.cpp \
    logic/productsort.cpp \
    widgets/productwidget/productwidget.cpp \
    logic/projectappearance.cpp \
    logic/stringprocessing.cpp

HEADERS += \
    widgets/basketwidget/basketwidget.h \
    data_processing/data.h \
    widgets/mainwindow/mainwindow.h \
    logic/product.h \
    logic/productsort.h \
    widgets/productwidget/productwidget.h \
    logic/projectappearance.h \
    logic/stringprocessing.h

FORMS += \
    ui/basketwidget.ui \
    ui/mainwindow.ui \
    ui/productwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

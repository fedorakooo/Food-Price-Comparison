#include "projectappearance.h"

ProjectAppearance::ProjectAppearance() = default;

void ProjectAppearance::setSettingFontPrice(QVector<QLabel*> arrLabelPrice) {
    QFont* fontPrice = new QFont();
    setCorrectFontPrice(fontPrice);
    for (QLabel* label : arrLabelPrice) {
        label->setFont(*fontPrice);
    }
}

void ProjectAppearance::setCorrectFontPrice(QFont* fontPrice) {
    fontPrice->setPointSize(14);
    fontPrice->setWeight(QFont::Bold);
}

void ProjectAppearance::setSettingButtonsOpenProductWidget(QVector<QPushButton*> arrButtonOpenProductWidget) {
    for (QPushButton* button : arrButtonOpenProductWidget) {
        button->setStyleSheet("QPushButton{background: transparent;}");
    }
}

void ProjectAppearance::setSettingFontName(QVector<QGroupBox*> arrGroupBox) {
    QFont* fontName = new QFont();
    setCorrectFontName(fontName);
    for (QGroupBox* box : arrGroupBox) {
        box->setFont(*fontName);
    }
}

void ProjectAppearance::setCorrectFontName(QFont* fontName) {
    fontName->setPointSize(8);
    fontName->setWeight(QFont::Bold);
}

void ProjectAppearance::setSettingFontPicture(QVector<QLabel*> arrLabelPicture) {
    for (QLabel* label : arrLabelPicture) {
        label->setAlignment(Qt::AlignCenter);
    }
}

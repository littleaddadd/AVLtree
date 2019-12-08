/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *nameinput;
    QLineEdit *passwordinput;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(662, 386);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(12);
        label_2->setFont(font);

        gridLayout_3->addWidget(label_2, 4, 0, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout_3->addWidget(label, 3, 0, 1, 1);

        nameinput = new QLineEdit(Dialog);
        nameinput->setObjectName(QString::fromUtf8("nameinput"));
        nameinput->setMinimumSize(QSize(0, 40));

        gridLayout_3->addWidget(nameinput, 3, 1, 1, 1);

        passwordinput = new QLineEdit(Dialog);
        passwordinput->setObjectName(QString::fromUtf8("passwordinput"));
        passwordinput->setMinimumSize(QSize(0, 40));
        passwordinput->setContextMenuPolicy(Qt::DefaultContextMenu);

        gridLayout_3->addWidget(passwordinput, 4, 1, 1, 1);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(11);
        label_3->setFont(font1);

        gridLayout_3->addWidget(label_3, 5, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setFont(font1);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);


        gridLayout_3->addLayout(horizontalLayout, 6, 1, 1, 1);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 40));
        label_4->setFont(font1);

        gridLayout_3->addWidget(label_4, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Dialog, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\347\231\273\351\231\206\347\252\227\345\217\243", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QApplication::translate("Dialog", "\351\273\230\350\256\244\347\224\250\346\210\267\345\220\215admin \351\273\230\350\256\244\345\257\206\347\240\201123", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "\347\231\273\351\231\206", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "\351\200\200\345\207\272", nullptr));
        label_4->setText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\345\222\214\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

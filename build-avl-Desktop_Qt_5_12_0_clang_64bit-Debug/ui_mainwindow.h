/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_insert;
    QAction *action_member;
    QAction *action_remove;
    QAction *action_modify;
    QAction *action_init;
    QAction *action_destroy;
    QAction *action_size;
    QAction *action_traverse;
    QAction *action_relationinsert;
    QAction *action_relationremove;
    QAction *action_relationmodify;
    QAction *action_relationmember;
    QAction *action_relationtraverse;
    QAction *action_relationreset;
    QAction *action_hobbyinsert;
    QAction *action_hobbyremove;
    QAction *action_hobbymodify;
    QAction *action_hobbymember;
    QAction *action_hobbytraverse;
    QAction *action_hobbyreset;
    QAction *bothfollow;
    QAction *bothhobby;
    QAction *twodegreefriend;
    QAction *random;
    QAction *readapplybackup;
    QAction *saveapplybackup;
    QAction *bothfriend;
    QAction *bothfollower;
    QAction *actionhigh;
    QAction *set_insert;
    QAction *set_destroy;
    QAction *set_remove;
    QAction *set_init;
    QAction *set_union;
    QAction *set_intersection;
    QAction *set_difference;
    QAction *set_size;
    QAction *set_member;
    QAction *set_subset;
    QAction *set_equal;
    QAction *saveset;
    QAction *readset;
    QAction *saveapply;
    QAction *readapply;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_3;
    QLineEdit *input2;
    QComboBox *comboBox;
    QLabel *label3;
    QLineEdit *input3;
    QLineEdit *input1;
    QComboBox *comboBox_1;
    QLabel *label1;
    QLabel *label2;
    QLabel *label4;
    QLabel *label5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_save;
    QPushButton *button_ok;
    QPushButton *button_exit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu_user;
    QMenu *menu_relation;
    QMenu *menu_hobby;
    QMenu *menu_search;
    QMenu *menu_random;
    QMenu *menu_file;
    QMenu *menu_system;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        action_insert = new QAction(MainWindow);
        action_insert->setObjectName(QString::fromUtf8("action_insert"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        action_insert->setFont(font);
        action_member = new QAction(MainWindow);
        action_member->setObjectName(QString::fromUtf8("action_member"));
        action_remove = new QAction(MainWindow);
        action_remove->setObjectName(QString::fromUtf8("action_remove"));
        action_modify = new QAction(MainWindow);
        action_modify->setObjectName(QString::fromUtf8("action_modify"));
        action_init = new QAction(MainWindow);
        action_init->setObjectName(QString::fromUtf8("action_init"));
        action_destroy = new QAction(MainWindow);
        action_destroy->setObjectName(QString::fromUtf8("action_destroy"));
        action_size = new QAction(MainWindow);
        action_size->setObjectName(QString::fromUtf8("action_size"));
        action_traverse = new QAction(MainWindow);
        action_traverse->setObjectName(QString::fromUtf8("action_traverse"));
        action_relationinsert = new QAction(MainWindow);
        action_relationinsert->setObjectName(QString::fromUtf8("action_relationinsert"));
        action_relationremove = new QAction(MainWindow);
        action_relationremove->setObjectName(QString::fromUtf8("action_relationremove"));
        action_relationmodify = new QAction(MainWindow);
        action_relationmodify->setObjectName(QString::fromUtf8("action_relationmodify"));
        action_relationmember = new QAction(MainWindow);
        action_relationmember->setObjectName(QString::fromUtf8("action_relationmember"));
        action_relationtraverse = new QAction(MainWindow);
        action_relationtraverse->setObjectName(QString::fromUtf8("action_relationtraverse"));
        action_relationreset = new QAction(MainWindow);
        action_relationreset->setObjectName(QString::fromUtf8("action_relationreset"));
        action_hobbyinsert = new QAction(MainWindow);
        action_hobbyinsert->setObjectName(QString::fromUtf8("action_hobbyinsert"));
        action_hobbyremove = new QAction(MainWindow);
        action_hobbyremove->setObjectName(QString::fromUtf8("action_hobbyremove"));
        action_hobbymodify = new QAction(MainWindow);
        action_hobbymodify->setObjectName(QString::fromUtf8("action_hobbymodify"));
        action_hobbymember = new QAction(MainWindow);
        action_hobbymember->setObjectName(QString::fromUtf8("action_hobbymember"));
        action_hobbytraverse = new QAction(MainWindow);
        action_hobbytraverse->setObjectName(QString::fromUtf8("action_hobbytraverse"));
        action_hobbyreset = new QAction(MainWindow);
        action_hobbyreset->setObjectName(QString::fromUtf8("action_hobbyreset"));
        bothfollow = new QAction(MainWindow);
        bothfollow->setObjectName(QString::fromUtf8("bothfollow"));
        bothhobby = new QAction(MainWindow);
        bothhobby->setObjectName(QString::fromUtf8("bothhobby"));
        twodegreefriend = new QAction(MainWindow);
        twodegreefriend->setObjectName(QString::fromUtf8("twodegreefriend"));
        random = new QAction(MainWindow);
        random->setObjectName(QString::fromUtf8("random"));
        readapplybackup = new QAction(MainWindow);
        readapplybackup->setObjectName(QString::fromUtf8("readapplybackup"));
        saveapplybackup = new QAction(MainWindow);
        saveapplybackup->setObjectName(QString::fromUtf8("saveapplybackup"));
        bothfriend = new QAction(MainWindow);
        bothfriend->setObjectName(QString::fromUtf8("bothfriend"));
        bothfollower = new QAction(MainWindow);
        bothfollower->setObjectName(QString::fromUtf8("bothfollower"));
        actionhigh = new QAction(MainWindow);
        actionhigh->setObjectName(QString::fromUtf8("actionhigh"));
        set_insert = new QAction(MainWindow);
        set_insert->setObjectName(QString::fromUtf8("set_insert"));
        set_destroy = new QAction(MainWindow);
        set_destroy->setObjectName(QString::fromUtf8("set_destroy"));
        set_remove = new QAction(MainWindow);
        set_remove->setObjectName(QString::fromUtf8("set_remove"));
        set_init = new QAction(MainWindow);
        set_init->setObjectName(QString::fromUtf8("set_init"));
        set_union = new QAction(MainWindow);
        set_union->setObjectName(QString::fromUtf8("set_union"));
        set_intersection = new QAction(MainWindow);
        set_intersection->setObjectName(QString::fromUtf8("set_intersection"));
        set_difference = new QAction(MainWindow);
        set_difference->setObjectName(QString::fromUtf8("set_difference"));
        set_size = new QAction(MainWindow);
        set_size->setObjectName(QString::fromUtf8("set_size"));
        set_member = new QAction(MainWindow);
        set_member->setObjectName(QString::fromUtf8("set_member"));
        set_subset = new QAction(MainWindow);
        set_subset->setObjectName(QString::fromUtf8("set_subset"));
        set_equal = new QAction(MainWindow);
        set_equal->setObjectName(QString::fromUtf8("set_equal"));
        saveset = new QAction(MainWindow);
        saveset->setObjectName(QString::fromUtf8("saveset"));
        readset = new QAction(MainWindow);
        readset->setObjectName(QString::fromUtf8("readset"));
        saveapply = new QAction(MainWindow);
        saveapply->setObjectName(QString::fromUtf8("saveapply"));
        readapply = new QAction(MainWindow);
        readapply->setObjectName(QString::fromUtf8("readapply"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMinimumSize(QSize(0, 350));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font1.setPointSize(11);
        textBrowser->setFont(font1);

        verticalLayout->addWidget(textBrowser);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        input2 = new QLineEdit(centralWidget);
        input2->setObjectName(QString::fromUtf8("input2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(input2->sizePolicy().hasHeightForWidth());
        input2->setSizePolicy(sizePolicy2);
        input2->setFont(font1);

        gridLayout_3->addWidget(input2, 1, 1, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        comboBox->setFont(font1);

        gridLayout_3->addWidget(comboBox, 3, 1, 1, 1);

        label3 = new QLabel(centralWidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        sizePolicy2.setHeightForWidth(label3->sizePolicy().hasHeightForWidth());
        label3->setSizePolicy(sizePolicy2);
        label3->setFont(font1);

        gridLayout_3->addWidget(label3, 2, 0, 1, 1);

        input3 = new QLineEdit(centralWidget);
        input3->setObjectName(QString::fromUtf8("input3"));
        sizePolicy2.setHeightForWidth(input3->sizePolicy().hasHeightForWidth());
        input3->setSizePolicy(sizePolicy2);
        input3->setFont(font1);

        gridLayout_3->addWidget(input3, 2, 1, 1, 1);

        input1 = new QLineEdit(centralWidget);
        input1->setObjectName(QString::fromUtf8("input1"));
        sizePolicy2.setHeightForWidth(input1->sizePolicy().hasHeightForWidth());
        input1->setSizePolicy(sizePolicy2);
        input1->setFont(font1);

        gridLayout_3->addWidget(input1, 0, 1, 1, 1);

        comboBox_1 = new QComboBox(centralWidget);
        comboBox_1->setObjectName(QString::fromUtf8("comboBox_1"));
        sizePolicy2.setHeightForWidth(comboBox_1->sizePolicy().hasHeightForWidth());
        comboBox_1->setSizePolicy(sizePolicy2);
        comboBox_1->setFont(font1);

        gridLayout_3->addWidget(comboBox_1, 4, 1, 1, 1);

        label1 = new QLabel(centralWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label1->sizePolicy().hasHeightForWidth());
        label1->setSizePolicy(sizePolicy3);
        label1->setFont(font1);

        gridLayout_3->addWidget(label1, 0, 0, 1, 1);

        label2 = new QLabel(centralWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        sizePolicy2.setHeightForWidth(label2->sizePolicy().hasHeightForWidth());
        label2->setSizePolicy(sizePolicy2);
        label2->setFont(font1);

        gridLayout_3->addWidget(label2, 1, 0, 1, 1);

        label4 = new QLabel(centralWidget);
        label4->setObjectName(QString::fromUtf8("label4"));
        sizePolicy2.setHeightForWidth(label4->sizePolicy().hasHeightForWidth());
        label4->setSizePolicy(sizePolicy2);
        label4->setFont(font1);

        gridLayout_3->addWidget(label4, 3, 0, 1, 1);

        label5 = new QLabel(centralWidget);
        label5->setObjectName(QString::fromUtf8("label5"));
        label5->setFont(font1);

        gridLayout_3->addWidget(label5, 4, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_4->setStretch(0, 1);

        verticalLayout->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_save = new QPushButton(centralWidget);
        button_save->setObjectName(QString::fromUtf8("button_save"));
        button_save->setFont(font1);

        horizontalLayout->addWidget(button_save);

        button_ok = new QPushButton(centralWidget);
        button_ok->setObjectName(QString::fromUtf8("button_ok"));
        sizePolicy2.setHeightForWidth(button_ok->sizePolicy().hasHeightForWidth());
        button_ok->setSizePolicy(sizePolicy2);
        button_ok->setMinimumSize(QSize(0, 0));
        button_ok->setFont(font1);

        horizontalLayout->addWidget(button_ok);

        button_exit = new QPushButton(centralWidget);
        button_exit->setObjectName(QString::fromUtf8("button_exit"));
        sizePolicy2.setHeightForWidth(button_exit->sizePolicy().hasHeightForWidth());
        button_exit->setSizePolicy(sizePolicy2);
        button_exit->setMinimumSize(QSize(0, 0));
        button_exit->setFont(font1);

        horizontalLayout->addWidget(button_exit);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 6);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 1);

        horizontalLayout_2->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 26));
        menu_user = new QMenu(menuBar);
        menu_user->setObjectName(QString::fromUtf8("menu_user"));
        menu_relation = new QMenu(menuBar);
        menu_relation->setObjectName(QString::fromUtf8("menu_relation"));
        menu_hobby = new QMenu(menuBar);
        menu_hobby->setObjectName(QString::fromUtf8("menu_hobby"));
        menu_search = new QMenu(menuBar);
        menu_search->setObjectName(QString::fromUtf8("menu_search"));
        menu_random = new QMenu(menuBar);
        menu_random->setObjectName(QString::fromUtf8("menu_random"));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_system = new QMenu(menuBar);
        menu_system->setObjectName(QString::fromUtf8("menu_system"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_system->menuAction());
        menuBar->addAction(menu_user->menuAction());
        menuBar->addAction(menu_relation->menuAction());
        menuBar->addAction(menu_hobby->menuAction());
        menuBar->addAction(menu_search->menuAction());
        menuBar->addAction(menu_random->menuAction());
        menuBar->addAction(menu_file->menuAction());
        menu_user->addAction(action_insert);
        menu_user->addAction(action_remove);
        menu_user->addAction(action_modify);
        menu_user->addAction(action_member);
        menu_user->addAction(action_size);
        menu_user->addAction(action_traverse);
        menu_relation->addAction(action_relationreset);
        menu_relation->addAction(action_relationinsert);
        menu_relation->addAction(action_relationremove);
        menu_relation->addAction(action_relationmodify);
        menu_relation->addAction(action_relationmember);
        menu_relation->addAction(action_relationtraverse);
        menu_hobby->addAction(action_hobbyreset);
        menu_hobby->addAction(action_hobbyinsert);
        menu_hobby->addAction(action_hobbyremove);
        menu_hobby->addAction(action_hobbymodify);
        menu_hobby->addAction(action_hobbymember);
        menu_hobby->addAction(action_hobbytraverse);
        menu_search->addAction(bothfollow);
        menu_search->addAction(bothhobby);
        menu_search->addAction(twodegreefriend);
        menu_random->addAction(random);
        menu_file->addAction(saveset);
        menu_file->addAction(readset);
        menu_file->addAction(saveapply);
        menu_file->addAction(readapply);
        menu_file->addAction(readapplybackup);
        menu_file->addAction(saveapplybackup);
        menu_system->addAction(action_init);
        menu_system->addAction(action_destroy);
        menu->addSeparator();
        menu->addAction(set_init);
        menu->addAction(set_destroy);
        menu->addAction(set_insert);
        menu->addAction(set_remove);
        menu->addAction(set_intersection);
        menu->addAction(set_union);
        menu->addAction(set_difference);
        menu->addAction(set_size);
        menu->addAction(set_member);
        menu->addAction(set_subset);
        menu->addAction(set_equal);
        menu->addAction(actionhigh);

        retranslateUi(MainWindow);
        QObject::connect(button_exit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\237\272\344\272\216AVL\346\240\221\350\241\250\347\244\272\347\232\204\351\233\206\345\220\210ADT\345\256\236\347\216\260\344\270\216\345\272\224\347\224\250_\350\260\242\346\267\273", nullptr));
        action_insert->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\224\250\346\210\267", nullptr));
        action_member->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\347\224\250\346\210\267", nullptr));
        action_remove->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        action_modify->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\224\250\346\210\267", nullptr));
        action_init->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\347\263\273\347\273\237", nullptr));
        action_destroy->setText(QApplication::translate("MainWindow", "\351\224\200\346\257\201\347\263\273\347\273\237", nullptr));
        action_size->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\224\250\346\210\267\346\225\260", nullptr));
        action_traverse->setText(QApplication::translate("MainWindow", "\351\201\215\345\216\206\346\211\200\346\234\211\347\224\250\346\210\267", nullptr));
        action_relationinsert->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\224\250\346\210\267\347\232\204\347\244\276\344\272\244", nullptr));
        action_relationremove->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\347\224\250\346\210\267\347\232\204\347\244\276\344\272\244", nullptr));
        action_relationmodify->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\224\250\346\210\267\347\232\204\347\244\276\344\272\244", nullptr));
        action_relationmember->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\224\250\346\210\267\347\232\204\347\244\276\344\272\244", nullptr));
        action_relationtraverse->setText(QApplication::translate("MainWindow", "\351\201\215\345\216\206\347\224\250\346\210\267\347\232\204\347\244\276\344\272\244", nullptr));
        action_relationreset->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256\347\224\250\346\210\267\347\232\204\347\244\276\344\272\244", nullptr));
        action_hobbyinsert->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\224\250\346\210\267\347\232\204\347\210\261\345\245\275", nullptr));
        action_hobbyremove->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\347\224\250\346\210\267\347\232\204\347\210\261\345\245\275", nullptr));
        action_hobbymodify->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\224\250\346\210\267\347\232\204\347\210\261\345\245\275", nullptr));
        action_hobbymember->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\224\250\346\210\267\347\232\204\347\210\261\345\245\275", nullptr));
        action_hobbytraverse->setText(QApplication::translate("MainWindow", "\351\201\215\345\216\206\347\224\250\346\210\267\347\232\204\347\210\261\345\245\275", nullptr));
        action_hobbyreset->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\347\224\250\346\210\267\347\232\204\347\210\261\345\245\275", nullptr));
        bothfollow->setText(QApplication::translate("MainWindow", "\345\205\261\345\220\214\345\205\263\346\263\250\346\237\245\350\257\242", nullptr));
        bothhobby->setText(QApplication::translate("MainWindow", "\345\205\261\345\220\214\345\226\234\345\245\275\346\237\245\350\257\242", nullptr));
        twodegreefriend->setText(QApplication::translate("MainWindow", "\344\272\214\345\272\246\345\245\275\345\217\213\346\237\245\350\257\242", nullptr));
        random->setText(QApplication::translate("MainWindow", "\351\232\217\346\234\272\347\224\237\346\210\220\346\225\260\346\215\256", nullptr));
        readapplybackup->setText(QApplication::translate("MainWindow", "\345\272\224\347\224\250\345\244\207\344\273\275\350\257\273\345\217\226", nullptr));
        saveapplybackup->setText(QApplication::translate("MainWindow", "\345\272\224\347\224\250\345\244\207\344\273\275\344\277\235\345\255\230", nullptr));
        bothfriend->setText(QApplication::translate("MainWindow", "\345\205\261\345\220\214\345\245\275\345\217\213\346\237\245\350\257\242", nullptr));
        bothfollower->setText(QApplication::translate("MainWindow", "\345\205\261\345\220\214\347\262\211\344\270\235\346\237\245\350\257\242", nullptr));
        actionhigh->setText(QApplication::translate("MainWindow", "high", nullptr));
        set_insert->setText(QApplication::translate("MainWindow", "set_insert", nullptr));
        set_destroy->setText(QApplication::translate("MainWindow", "set_destroy", nullptr));
        set_remove->setText(QApplication::translate("MainWindow", "set_remove", nullptr));
        set_init->setText(QApplication::translate("MainWindow", "set_init", nullptr));
        set_union->setText(QApplication::translate("MainWindow", "set_union", nullptr));
        set_intersection->setText(QApplication::translate("MainWindow", "set_intersection", nullptr));
        set_difference->setText(QApplication::translate("MainWindow", "set_difference", nullptr));
        set_size->setText(QApplication::translate("MainWindow", "set_size", nullptr));
        set_member->setText(QApplication::translate("MainWindow", "set_member", nullptr));
        set_subset->setText(QApplication::translate("MainWindow", "set_subset", nullptr));
        set_equal->setText(QApplication::translate("MainWindow", "set_equal", nullptr));
        saveset->setText(QApplication::translate("MainWindow", "\351\233\206\345\220\210\344\277\235\345\255\230", nullptr));
        readset->setText(QApplication::translate("MainWindow", "\351\233\206\345\220\210\350\257\273\345\217\226", nullptr));
        saveapply->setText(QApplication::translate("MainWindow", "\351\273\230\350\256\244\344\277\235\345\255\230", nullptr));
        readapply->setText(QApplication::translate("MainWindow", "\351\273\230\350\256\244\350\257\273\345\217\226", nullptr));
        label3->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label1->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label4->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label5->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        button_save->setText(QApplication::translate("MainWindow", "\345\272\224\347\224\250\346\225\260\346\215\256\344\277\235\345\255\230\345\277\253\346\215\267\351\224\256", nullptr));
        button_ok->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", nullptr));
        button_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        menu_user->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267", nullptr));
        menu_relation->setTitle(QApplication::translate("MainWindow", "\347\244\276\344\272\244", nullptr));
        menu_hobby->setTitle(QApplication::translate("MainWindow", "\347\210\261\345\245\275", nullptr));
        menu_search->setTitle(QApplication::translate("MainWindow", "\347\211\271\346\256\212\346\237\245\350\257\242", nullptr));
        menu_random->setTitle(QApplication::translate("MainWindow", "\351\232\217\346\234\272\347\224\237\346\210\220", nullptr));
        menu_file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\255\230\345\202\250", nullptr));
        menu_system->setTitle(QApplication::translate("MainWindow", "\347\263\273\347\273\237", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\351\233\206\345\220\210\350\277\220\347\256\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

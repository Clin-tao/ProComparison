/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Ledit_dest;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pbn_clear;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbn_start;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *ckb_Lock;
    QLabel *label;
    QLineEdit *Ledit_src;
    QPushButton *pushButton;
    QPushButton *pbn_save;
    QTextBrowser *tbo_show;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *ledit_shield;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(852, 532);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Ledit_dest = new QLineEdit(centralwidget);
        Ledit_dest->setObjectName(QString::fromUtf8("Ledit_dest"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ledit_dest->sizePolicy().hasHeightForWidth());
        Ledit_dest->setSizePolicy(sizePolicy);
        Ledit_dest->setMinimumSize(QSize(600, 0));

        horizontalLayout_2->addWidget(Ledit_dest);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pbn_clear = new QPushButton(centralwidget);
        pbn_clear->setObjectName(QString::fromUtf8("pbn_clear"));

        horizontalLayout_3->addWidget(pbn_clear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pbn_start = new QPushButton(centralwidget);
        pbn_start->setObjectName(QString::fromUtf8("pbn_start"));

        horizontalLayout_3->addWidget(pbn_start);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        ckb_Lock = new QCheckBox(centralwidget);
        ckb_Lock->setObjectName(QString::fromUtf8("ckb_Lock"));
        ckb_Lock->setChecked(true);

        gridLayout_2->addWidget(ckb_Lock, 0, 3, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        Ledit_src = new QLineEdit(centralwidget);
        Ledit_src->setObjectName(QString::fromUtf8("Ledit_src"));
        Ledit_src->setEnabled(true);
        sizePolicy.setHeightForWidth(Ledit_src->sizePolicy().hasHeightForWidth());
        Ledit_src->setSizePolicy(sizePolicy);
        Ledit_src->setMinimumSize(QSize(500, 0));

        gridLayout_2->addWidget(Ledit_src, 0, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 6, 1, 1);

        pbn_save = new QPushButton(centralwidget);
        pbn_save->setObjectName(QString::fromUtf8("pbn_save"));

        gridLayout_2->addWidget(pbn_save, 0, 5, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        tbo_show = new QTextBrowser(centralwidget);
        tbo_show->setObjectName(QString::fromUtf8("tbo_show"));

        gridLayout->addWidget(tbo_show, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        ledit_shield = new QLineEdit(centralwidget);
        ledit_shield->setObjectName(QString::fromUtf8("ledit_shield"));

        horizontalLayout->addWidget(ledit_shield);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 852, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ProComparison", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\347\233\256\345\275\225\357\274\232", nullptr));
        Ledit_dest->setText(QApplication::translate("MainWindow", "C:\\Users\\taoclin\\Desktop\\t2", nullptr));
        pbn_clear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\230\276\347\244\272", nullptr));
        pbn_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\243\200\346\265\213\345\271\266\345\244\215\345\210\266", nullptr));
        ckb_Lock->setText(QApplication::translate("MainWindow", "\351\224\201\345\256\232\350\276\223\345\205\245", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\272\220\347\233\256\345\275\225\357\274\232", nullptr));
        Ledit_src->setText(QApplication::translate("MainWindow", "C:\\Users\\taoclin\\Desktop\\t1", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\205\215\347\275\256\346\226\207\344\273\266", nullptr));
        pbn_save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\345\261\217\350\224\275\346\226\207\344\273\266\345\244\271\357\274\232", nullptr));
        ledit_shield->setText(QApplication::translate("MainWindow", "cfg,", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'orderdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERDIALOG_H
#define UI_ORDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderDialog
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *tableWidget;

    void setupUi(QDialog *OrderDialog)
    {
        if (OrderDialog->objectName().isEmpty())
            OrderDialog->setObjectName(QStringLiteral("OrderDialog"));
        OrderDialog->resize(1000, 528);
        OrderDialog->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(OrderDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(880, 470, 93, 28));
        pushButton->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	\n"
"	color: rgb(136, 136, 136);\n"
"	border-radius: 4px;\n"
"	background-color: rgb(255, 255, 255);\n"
"	border: 1px solid gray;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"	\n"
"	color: rgb(0, 85, 255);\n"
"	border: 1px solid blue;\n"
"\n"
"}\n"
"\n"
"QPushButton::checked {\n"
"	\n"
"	background-color: blue;\n"
"	border: 1px solid blue;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}"));
        label = new QLabel(OrderDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 20, 100, 40));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(15);
        label->setFont(font);
        label_2 = new QLabel(OrderDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 60, 391, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        font1.setPointSize(11);
        label_2->setFont(font1);
        tableWidget = new QTableWidget(OrderDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(60, 100, 911, 361));
        tableWidget->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"background-color: rgb(230, 230, 230);"));

        retranslateUi(OrderDialog);

        QMetaObject::connectSlotsByName(OrderDialog);
    } // setupUi

    void retranslateUi(QDialog *OrderDialog)
    {
        OrderDialog->setWindowTitle(QApplication::translate("OrderDialog", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("OrderDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("OrderDialog", "\346\270\251\351\246\250\346\217\220\347\244\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("OrderDialog", "\346\202\250\345\275\223\345\211\215\346\234\211*\344\270\252\350\256\242\345\215\225\357\274\214\346\230\257\345\220\246\351\234\200\350\246\201\344\270\212\346\234\272\357\274\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OrderDialog: public Ui_OrderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QToolButton *serverToolButton;
    QToolButton *instrumentToolButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *ipEdit;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QLineEdit *urlEdit;
    QWidget *page_3;
    QTableWidget *tableWidget;
    QLineEdit *keyWord;
    QPushButton *searchMachine;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(1000, 528);
        SettingDialog->setStyleSheet(QLatin1String("*{\n"
"border-radius:20px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        serverToolButton = new QToolButton(SettingDialog);
        serverToolButton->setObjectName(QStringLiteral("serverToolButton"));
        serverToolButton->setGeometry(QRect(40, 42, 111, 51));
        serverToolButton->setStyleSheet(QString::fromUtf8("*{font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QToolBtton#serverToolButton{\n"
"	background-color: transparent; border: none;\n"
"}\n"
"#serverToolButton::checked{\n"
"	\n"
"   	color: rgb(0, 85, 255);\n"
"	border-width:2px;	\n"
"	border-color: rgb(0, 85, 255);\n"
"}\n"
""));
        serverToolButton->setCheckable(true);
        serverToolButton->setChecked(false);
        instrumentToolButton = new QToolButton(SettingDialog);
        instrumentToolButton->setObjectName(QStringLiteral("instrumentToolButton"));
        instrumentToolButton->setGeometry(QRect(40, 100, 111, 51));
        instrumentToolButton->setStyleSheet(QString::fromUtf8("*{font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QToolBtton#instrumentToolButton{\n"
"	background-color: transparent; border: none;\n"
"}\n"
"\n"
"\n"
"#instrumentToolButton::checked {\n"
"	\n"
"	color: rgb(0, 85, 255);\n"
"	border-width:2px;	\n"
"	border-color: rgb(0, 85, 255);\n"
"}"));
        instrumentToolButton->setCheckable(true);
        stackedWidget = new QStackedWidget(SettingDialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(160, 40, 821, 361));
        stackedWidget->setStyleSheet(QLatin1String("border-radius: 5px;\n"
"background-color: rgb(230, 230, 230);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        ipEdit = new QLineEdit(page);
        ipEdit->setObjectName(QStringLiteral("ipEdit"));
        ipEdit->setGeometry(QRect(210, 130, 561, 51));
        ipEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: 1px solid gray;\n"
"padding-left:5px;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        radioButton1 = new QRadioButton(page);
        radioButton1->setObjectName(QStringLiteral("radioButton1"));
        radioButton1->setGeometry(QRect(70, 70, 131, 31));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(10);
        radioButton1->setFont(font);
        radioButton2 = new QRadioButton(page);
        radioButton2->setObjectName(QStringLiteral("radioButton2"));
        radioButton2->setGeometry(QRect(70, 140, 131, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        radioButton2->setFont(font1);
        urlEdit = new QLineEdit(page);
        urlEdit->setObjectName(QStringLiteral("urlEdit"));
        urlEdit->setGeometry(QRect(210, 60, 561, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        urlEdit->setFont(font2);
        urlEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: 1px solid gray;\n"
"padding-left:5px;\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setStyleSheet(QStringLiteral(""));
        tableWidget = new QTableWidget(page_3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(3, 59, 831, 301));
        tableWidget->setStyleSheet(QLatin1String("* { border: none; }\n"
""));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        keyWord = new QLineEdit(page_3);
        keyWord->setObjectName(QStringLiteral("keyWord"));
        keyWord->setGeometry(QRect(2, 2, 721, 50));
        keyWord->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(194, 194, 194);\n"
""));
        searchMachine = new QPushButton(page_3);
        searchMachine->setObjectName(QStringLiteral("searchMachine"));
        searchMachine->setGeometry(QRect(722, 2, 97, 50));
        searchMachine->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	\n"
"	color: rgb(136, 136, 136);\n"
"	border-radius: 5px;\n"
"\n"
"\n"
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
"\n"
"	border: 1px solid blue;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}"));
        stackedWidget->addWidget(page_3);
        buttonBox = new QDialogButtonBox(SettingDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(779, 410, 201, 91));
        buttonBox->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	\n"
"	color: rgb(136, 136, 136);\n"
"	border-radius: 5px;\n"
"	margin-left:5px;\n"
"	padding:10px 20px;\n"
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
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(SettingDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(700, 431, 93, 49));
        pushButton->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	\n"
"	color: rgb(136, 136, 136);\n"
"	border-radius: 5px;\n"
"\n"
"\n"
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
"\n"
"	border: 1px solid blue;\n"
"	color: rgb(255, 255, 255);\n"
"\n"
"}"));

        retranslateUi(SettingDialog);

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "Dialog", Q_NULLPTR));
        serverToolButton->setText(QApplication::translate("SettingDialog", "\346\234\215\345\212\241\350\256\276\347\275\256", Q_NULLPTR));
        instrumentToolButton->setText(QApplication::translate("SettingDialog", "\344\273\252\345\231\250\350\256\276\347\275\256", Q_NULLPTR));
        ipEdit->setPlaceholderText(QApplication::translate("SettingDialog", "\350\257\267\350\276\223\345\205\245\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200", Q_NULLPTR));
        radioButton1->setText(QApplication::translate("SettingDialog", "\345\237\237\345\220\215", Q_NULLPTR));
        radioButton2->setText(QApplication::translate("SettingDialog", "IP\345\234\260\345\235\200", Q_NULLPTR));
        urlEdit->setPlaceholderText(QApplication::translate("SettingDialog", "\350\257\267\350\276\223\345\205\245\346\234\215\345\212\241\345\231\250\345\237\237\345\220\215\357\274\214\345\246\202\357\274\232http://bk4.ilabeco.com", Q_NULLPTR));
        keyWord->setText(QString());
        keyWord->setPlaceholderText(QApplication::translate("SettingDialog", "\350\257\267\350\276\223\345\205\245\345\205\263\351\224\256\345\255\227", Q_NULLPTR));
        searchMachine->setText(QApplication::translate("SettingDialog", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SettingDialog", "\344\270\212\344\270\200\346\255\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H

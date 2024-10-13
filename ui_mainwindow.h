/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_4;
    QFrame *frame_6;
    QToolButton *noticeButton;
    QToolButton *makehButton;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QLabel *noticeTitle;
    QPlainTextEdit *contentNotice;
    QLabel *author;
    QLabel *publishtime;
    QWidget *page_4;
    QTableWidget *tableWidget;
    QFrame *frame_3;
    QFrame *frame_5;
    QPushButton *qrCodeButton;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *ipLabel;
    QLabel *netWork;
    QFrame *qcCodeFrame;
    QLabel *qcCodeLabel;
    QLabel *label_14;
    QLabel *mcAdminIds;
    QLabel *mcName;
    QLabel *mcNumber;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *accountEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QWidget *page_2;
    QPushButton *dynamicLoginButton;
    QLineEdit *dynamicEdit;
    QToolButton *accountLoginButton;
    QToolButton *dynamicButton;
    QLabel *label_5;
    QPushButton *pushButtonShutdown;
    QPushButton *pushButtonShutMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("QWidget#centralWidget{background-image: url(:/res/images/bg.png);\n"
"}"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(320, 210, 881, 490));
        frame->setStyleSheet(QLatin1String("QFrame#frame{\n"
"	border-radius:20px;\n"
"	background-color: rgba(250, 250, 250, 50);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 445, 490));
        frame_2->setStyleSheet(QLatin1String("*{background-color: rgb(49, 116, 223);}\n"
"\n"
"QFrame#frame_2{\n"
"	  border-top-left-radius: 20px;\n"
"      border-bottom-left-radius: 20px;\n"
"	  \n"
"	\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #3174DE, stop: 1 #256BC9);\n"
"\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(40, 50, 367, 10));
        frame_4->setStyleSheet(QStringLiteral("color: rgb(26, 94, 187);"));
        frame_4->setFrameShape(QFrame::HLine);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(0, -20, 378, 10));
        frame_6->setStyleSheet(QStringLiteral("color: rgb(26, 94, 187);"));
        frame_6->setFrameShape(QFrame::HLine);
        frame_6->setFrameShadow(QFrame::Raised);
        noticeButton = new QToolButton(frame_2);
        noticeButton->setObjectName(QStringLiteral("noticeButton"));
        noticeButton->setGeometry(QRect(100, 20, 92, 35));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        noticeButton->setFont(font);
        noticeButton->setStyleSheet(QLatin1String("*{\n"
"color: rgb(162, 201, 254);\n"
"}\n"
"\n"
"\n"
"QToolButton#noticeButton{\n"
"\n"
"	background-color: transparent; border: none;\n"
"}\n"
"\n"
"\n"
"\n"
"#noticeButton:checked{\n"
"	color: rgb(255, 255, 255);\n"
"	border-width:3px;\n"
"	border-style:none none solid none; 	\n"
"	border-color:#FFFFFF;\n"
"}"));
        noticeButton->setCheckable(true);
        makehButton = new QToolButton(frame_2);
        makehButton->setObjectName(QStringLiteral("makehButton"));
        makehButton->setGeometry(QRect(240, 20, 98, 35));
        makehButton->setFont(font);
        makehButton->setStyleSheet(QLatin1String("*{\n"
"color: rgb(162, 201, 254);\n"
"}\n"
"\n"
"\n"
"\n"
"QToolButton#makehButton{\n"
"	background-color: transparent; border: none;\n"
"}\n"
"\n"
"\n"
"\n"
"QToolButton#makehButton:checked{\n"
"	color: rgb(255, 255, 255);\n"
"	border-width:3px;\n"
"	border-style:none none solid none; 	\n"
"	border-color:#FFFFFF;\n"
"}"));
        makehButton->setCheckable(true);
        stackedWidget_2 = new QStackedWidget(frame_2);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(0, 60, 445, 413));
        stackedWidget_2->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        noticeTitle = new QLabel(page_3);
        noticeTitle->setObjectName(QStringLiteral("noticeTitle"));
        noticeTitle->setGeometry(QRect(10, 10, 378, 31));
        noticeTitle->setFont(font);
        noticeTitle->setStyleSheet(QString::fromUtf8("color: rgba(255, 255, 255, 200);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        noticeTitle->setAlignment(Qt::AlignCenter);
        contentNotice = new QPlainTextEdit(page_3);
        contentNotice->setObjectName(QStringLiteral("contentNotice"));
        contentNotice->setGeometry(QRect(40, 50, 378, 301));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        contentNotice->setFont(font1);
        contentNotice->setStyleSheet(QString::fromUtf8("*{\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgba(255, 255, 255, 200);\n"
"}\n"
"\n"
"QPlainTextEdit {\n"
"    border: none;\n"
"}\n"
"\n"
"QPlainTextEdit QScrollBar {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}"));
        contentNotice->setReadOnly(true);
        author = new QLabel(page_3);
        author->setObjectName(QStringLiteral("author"));
        author->setGeometry(QRect(240, 390, 182, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        author->setFont(font2);
        author->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 200);"));
        author->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        publishtime = new QLabel(page_3);
        publishtime->setObjectName(QStringLiteral("publishtime"));
        publishtime->setGeometry(QRect(250, 370, 182, 20));
        publishtime->setFont(font2);
        publishtime->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgba(255, 255, 255, 200);"));
        publishtime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        tableWidget = new QTableWidget(page_4);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font3);
        __qtablewidgetitem->setBackground(QColor(0, 85, 127));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem18);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(40, 8, 378, 391));
        tableWidget->setFont(font1);
        tableWidget->setStyleSheet(QString::fromUtf8("*{\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTableWidget:Item\n"
"{\n"
"  	border-width:1px;\n"
"	border-style:none none solid none; 	\n"
"	border-color:#548AD5;	\n"
"	text-align:center;\n"
"   \n"
"}\n"
"QTableWidget::QHeaderView::section {background-color:#98ff9f;\n"
" text-align:center;\n"
"}\n"
""));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        stackedWidget_2->addWidget(page_4);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(450, 0, 431, 490));
        frame_3->setStyleSheet(QLatin1String("*{background-color: rgb(253, 253, 253);}\n"
"QFrame#frame_3{\n"
"	  border-top-right-radius: 20px;\n"
"      border-bottom-right-radius: 20px;\n"
"\n"
"     \n"
"\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(380, 0, 49, 49));
        frame_5->setStyleSheet(QStringLiteral(""));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        qrCodeButton = new QPushButton(frame_5);
        qrCodeButton->setObjectName(QStringLiteral("qrCodeButton"));
        qrCodeButton->setGeometry(QRect(0, -1, 49, 49));
        qrCodeButton->setStyleSheet(QLatin1String(";\n"
"border-image: url(:/res/images/wxlogin.png);\n"
"border: none;"));
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 10, 119, 41));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(102, 102, 102);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 20, 70, 31));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(102, 102, 102);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        ipLabel = new QLabel(frame_3);
        ipLabel->setObjectName(QStringLiteral("ipLabel"));
        ipLabel->setGeometry(QRect(30, 50, 181, 31));
        ipLabel->setStyleSheet(QString::fromUtf8("color: rgb(102, 102, 102);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        netWork = new QLabel(frame_3);
        netWork->setObjectName(QStringLiteral("netWork"));
        netWork->setGeometry(QRect(100, 20, 54, 31));
        netWork->setFont(font1);
        netWork->setStyleSheet(QString::fromUtf8("color: rgb(255, 165, 0);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        qcCodeFrame = new QFrame(frame_3);
        qcCodeFrame->setObjectName(QStringLiteral("qcCodeFrame"));
        qcCodeFrame->setGeometry(QRect(0, 99, 431, 331));
        qcCodeFrame->setStyleSheet(QStringLiteral("background-color: rgb(253, 253, 253);"));
        qcCodeFrame->setFrameShape(QFrame::StyledPanel);
        qcCodeFrame->setFrameShadow(QFrame::Raised);
        qcCodeLabel = new QLabel(qcCodeFrame);
        qcCodeLabel->setObjectName(QStringLiteral("qcCodeLabel"));
        qcCodeLabel->setGeometry(QRect(150, 74, 130, 130));
        qcCodeLabel->setStyleSheet(QStringLiteral(""));
        label_14 = new QLabel(qcCodeFrame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(120, 210, 210, 41));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(34, 34, 34);"));
        label_14->setAlignment(Qt::AlignCenter);
        mcAdminIds = new QLabel(frame_3);
        mcAdminIds->setObjectName(QStringLiteral("mcAdminIds"));
        mcAdminIds->setGeometry(QRect(40, 350, 378, 41));
        mcAdminIds->setFont(font1);
        mcAdminIds->setStyleSheet(QString::fromUtf8("color: rgb(102, 102, 102);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        mcName = new QLabel(frame_3);
        mcName->setObjectName(QStringLiteral("mcName"));
        mcName->setGeometry(QRect(40, 400, 201, 16));
        mcName->setFont(font1);
        mcName->setStyleSheet(QString::fromUtf8("color: rgb(102, 102, 102);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        mcNumber = new QLabel(frame_3);
        mcNumber->setObjectName(QStringLiteral("mcNumber"));
        mcNumber->setGeometry(QRect(220, 400, 201, 16));
        mcNumber->setFont(font1);
        mcNumber->setStyleSheet(QString::fromUtf8("color: rgb(102, 102, 102);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        stackedWidget = new QStackedWidget(frame_3);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 149, 431, 201));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(253, 253, 253);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        accountEdit = new QLineEdit(page);
        accountEdit->setObjectName(QStringLiteral("accountEdit"));
        accountEdit->setGeometry(QRect(70, 20, 311, 45));
        accountEdit->setFont(font1);
        accountEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border:none;\n"
"	background-color: rgb(241, 244, 251);\n"
"	border-radius:4px;\n"
"	\n"
"	padding-left:4px;\n"
"}"));
        accountEdit->setCursorPosition(0);
        passwordEdit = new QLineEdit(page);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setGeometry(QRect(70, 80, 311, 45));
        passwordEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border:none;\n"
"	background-color: rgb(241, 244, 251);\n"
"	border-radius:4px;\n"
"	padding-left:4px;\n"
"}"));
        passwordEdit->setEchoMode(QLineEdit::Password);
        loginButton = new QPushButton(page);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(70, 140, 311, 45));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        loginButton->setFont(font4);
        loginButton->setStyleSheet(QString::fromUtf8("*{\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	background-color: rgb(0, 65, 166);\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton#loginButton{\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton#loginButton:pressed{\n"
"	border-radius:10px;\n"
"	padding-top:3px;\n"
"	padding-left:3px;\n"
"}"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        dynamicLoginButton = new QPushButton(page_2);
        dynamicLoginButton->setObjectName(QStringLiteral("dynamicLoginButton"));
        dynamicLoginButton->setGeometry(QRect(70, 110, 311, 45));
        dynamicLoginButton->setFont(font4);
        dynamicLoginButton->setStyleSheet(QString::fromUtf8("*{\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	background-color: rgb(0, 65, 166);\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton#dynamicLoginButton{\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton#dynamicLoginButton:pressed{\n"
"	border-radius: 10px;\n"
"	padding-top:3px;\n"
"	padding-left:3px;\n"
"}"));
        dynamicEdit = new QLineEdit(page_2);
        dynamicEdit->setObjectName(QStringLiteral("dynamicEdit"));
        dynamicEdit->setGeometry(QRect(70, 30, 311, 45));
        dynamicEdit->setFont(font1);
        dynamicEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border:none;\n"
"	background-color: rgb(241, 244, 251);\n"
"	border-radius:4px;\n"
"	\n"
"	padding-left:4px;\n"
"}"));
        stackedWidget->addWidget(page_2);
        accountLoginButton = new QToolButton(frame_3);
        accountLoginButton->setObjectName(QStringLiteral("accountLoginButton"));
        accountLoginButton->setGeometry(QRect(100, 90, 100, 35));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(14);
        accountLoginButton->setFont(font5);
        accountLoginButton->setStyleSheet(QLatin1String("\n"
"\n"
"\n"
"\n"
"QToolButton#accountLoginButton{\n"
"	color: rgb(34, 34, 34);\n"
"	background-color: transparent; border: none;\n"
"}\n"
"\n"
"\n"
"QToolButton#accountLoginButton:checked{\n"
"	color: rgb(0, 65, 166);\n"
"	border-width:2px;\n"
"	border-style:none none solid none; 	\n"
"	border-color:#0041A6;\n"
"}"));
        accountLoginButton->setCheckable(true);
        dynamicButton = new QToolButton(frame_3);
        dynamicButton->setObjectName(QStringLiteral("dynamicButton"));
        dynamicButton->setGeometry(QRect(230, 90, 100, 35));
        dynamicButton->setFont(font5);
        dynamicButton->setStyleSheet(QLatin1String("\n"
"\n"
"\n"
"\n"
"\n"
"QToolButton#dynamicButton{\n"
"	background-color: transparent; border: none;\n"
"}\n"
"\n"
"QToolButton#dynamicButton:checked{\n"
"	color: rgb(0, 65, 166);\n"
"	border-width:2px;\n"
"	border-style:none none solid none; 	\n"
"	border-color:#0041A6;\n"
"}"));
        dynamicButton->setCheckable(true);
        frame_5->raise();
        label_6->raise();
        label_7->raise();
        ipLabel->raise();
        netWork->raise();
        mcAdminIds->raise();
        mcName->raise();
        mcNumber->raise();
        stackedWidget->raise();
        accountLoginButton->raise();
        dynamicButton->raise();
        qcCodeFrame->raise();
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(720, 1020, 322, 31));
        label_5->setStyleSheet(QString::fromUtf8("*{\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(85, 85, 85);\n"
"}"));
        label_5->setAlignment(Qt::AlignCenter);
        pushButtonShutdown = new QPushButton(centralWidget);
        pushButtonShutdown->setObjectName(QStringLiteral("pushButtonShutdown"));
        pushButtonShutdown->setGeometry(QRect(1760, 1010, 40, 40));
        pushButtonShutMenu = new QPushButton(centralWidget);
        pushButtonShutMenu->setObjectName(QStringLiteral("pushButtonShutMenu"));
        pushButtonShutMenu->setGeometry(QRect(1810, 1010, 40, 40));
        MainWindow->setCentralWidget(centralWidget);
        label_5->raise();
        pushButtonShutdown->raise();
        pushButtonShutMenu->raise();
        frame->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        noticeButton->setText(QApplication::translate("MainWindow", "\344\273\252\345\231\250\345\205\254\345\221\212", Q_NULLPTR));
        makehButton->setText(QApplication::translate("MainWindow", "\351\242\204\347\272\246\350\256\260\345\275\225", Q_NULLPTR));
        noticeTitle->setText(QApplication::translate("MainWindow", "\344\273\252\345\231\250\350\256\276\345\244\207\347\256\241\347\220\206\345\212\236\346\263\225\351\200\232\347\237\245", Q_NULLPTR));
        contentNotice->setPlainText(QApplication::translate("MainWindow", "       \344\270\272\344\272\206\350\247\204\350\214\203\344\273\252\345\231\250\350\256\276\345\244\207\347\232\204\344\275\277\347\224\250\344\270\216\347\256\241\347\220\206\357\274\214\344\275\277\344\273\252\345\231\250\350\256\276\345\244\207\345\217\221\346\214\245\345\205\266\345\272\224\346\234\211\347\232\204\344\275\234\347\224\250\357\274\214\346\240\271\346\215\256\345\205\254\345\217\270\344\273\252\345\231\250\350\256\276\345\244\207\347\256\241\347\220\206\344\270\216\344\275\277\347\224\250\346\226\271\346\263\225\357\274\214\347\273\223\345\220\210\346\210\221\345\215\225\344\275\215\344\273\252\345\231\250\344\275\277\347\224\250\347\232\204\345\205\267\344\275\223\346\203\205\345\206\265\357\274\214\347\216\260\351\200\232\347\237\245\345\246\202\344\270\213:\n"
"1\343\200\201\350\201\214\350\264\243\345\210\222\345\210\206\n"
"\346\211\200\346\234\211\346\226\275\345\267\245\344\273\252\345\231\250\347\273\237\344\270\200\347\224\261\345\205\254\345\217\270\345\267\245\347\250\213\346\212\200"
                        "\346\234\257\351\203\250\347\256\241\347\220\206\357\274\214\351\242\206\347\224\250\343\200\201\345\275\222\350\277\230\344\273\252\345\231\250\345\277\205\351\241\273\345\217\212\346\227\266\345\234\250\351\242\206\347\224\250\347\231\273\350\256\260\350\241\250\347\255\276\345\255\227\357\274\214\347\233\270\345\205\263\350\264\237\350\264\243\344\272\272\347\216\213\347\247\221\346\225\217\343\200\202\n"
"2\343\200\201\347\256\241\347\220\206\345\212\236\346\263\225\n"
"1\357\274\211\346\211\200\346\234\211\344\273\252\345\231\250\347\224\261\345\205\254\345\217\270\345\271\264\345\210\235\345\274\200\345\267\245\344\271\213\345\211\215\347\273\237\344\270\200\350\277\233\350\241\214\345\244\215\346\243\200\n"
"2\357\274\211\345\220\204\351\241\271\347\233\256\351\203\250\351\242\206\347\224\250\344\273\252\345\231\250\345\277\205\351\241\273\345\201\232\345\210\260\344\270\200\345\257\271\344\270\200\350\264\243\344\273\273\345\210\266\357\274\214\350\260\201\345\200\237\347\224\250\350\260\201\345\275\222"
                        "\350\277\230\357\274\214\344\270\255\351\200\224\345\207\272\347\216\260\345\244\232\344\270\252\351\241\271\347\233\256\351\203\250\344\272\222\347\233\270\350\275\254\345\200\237\345\205\254\345\217\270\344\270\215\344\272\210\350\256\244\345\217\257\343\200\202\n"
"3\357\274\211\344\273\252\345\231\250\344\275\277\347\224\250\344\272\272\345\272\224\347\210\261\346\212\244\344\273\252\345\231\250\350\256\276\345\244\207\357\274\214\345\217\212\346\227\266\350\277\233\350\241\214\347\273\264\346\212\244\343\200\201\344\277\235\345\205\273\357\274\214\344\277\235\350\257\201\344\273\252\345\231\250\347\232\204\345\256\214\346\225\264\346\200\247(\345\214\205\346\213\254\351\231\204\345\261\236\351\205\215\344\273\266)\343\200\202\345\246\202\345\234\250\344\275\277\347\224\250\350\277\207\347\250\213\344\270\255\345\207\272\347\216\260\344\270\242\345\244\261\343\200\201\346\215\237\345\235\217\346\203\205\345\206\265\357\274\214\345\272\224\345\217\212\346\227\266\351\200\232\347\237\245\345\205\254\345\217\270"
                        "\347\256\241\347\220\206\344\272\272\345\221\230\357\274\214\345\271\266\346\214\211\344\273\252\345\231\250\345\216\237\344\273\267\346\210\226\347\273\264\344\277\256\344\273\267\350\277\233\350\241\214\350\265\224\345\201\277\343\200\202\n"
"4\357\274\211\351\242\206\347\224\250\344\273\252\345\231\250\346\227\266\351\242\206\347\224\250\344\272\272\345\277\205\351\241\273\346\243\200\346\237\245\345\245\275\344\273\252\345\231\250\347\232\204\345\256\214\345\245\275\344\270\216\346\215\237\345\235\217\347\250\213\345\272\246\357\274\214\345\217\221\347\216\260\351\227\256\351\242\230\345\217\212\346\227\266\350\256\251\345\205\254\345\217\270\350\277\233\350\241\214\345\244\215\346\243\200\357\274\214\344\270\200\344\275\206\351\242\206\347\224\250\345\205\254\345\217\270\344\270\215\344\272\210\350\264\237\350\264\243\343\200\202\n"
"6\357\274\211\344\270\272\344\275\277\344\273\252\345\231\250\345\217\221\346\214\245\345\272\224\346\234\211\344\275\234\347\224\250\357\274\214\346\211\200\346\234\211\345\276"
                        "\205\344\275\277\347\224\250\345\256\214\346\257\225\345\220\216\345\217\212\346\227\266\345\275\222\350\277\230\345\271\266\345\201\232\345\275\222\350\277\230\347\231\273\350\256\260\357\274\214\344\270\215\345\276\227\346\213\226\345\273\266\345\275\222\350\277\230\346\227\266\351\227\264\357\274\214\345\246\202\346\234\211\344\273\252\345\231\250\344\270\215\350\203\275\345\275\222\350\277\230\344\271\237\350\246\201\345\233\236\345\205\254\345\217\270\345\201\232\347\273\247\347\273\255\344\275\277\347\224\250\347\231\273\350\256\260\347\233\270\345\205\263\346\211\213\347\273\255\344\270\216\347\255\276\345\255\227\343\200\202\345\246\202\351\241\271\347\233\256\351\203\250\346\234\211\350\207\252\350\264\255\347\232\204\344\273\252\345\231\250\344\270\215\345\234\250\345\205\254\345\217\270\346\214\202\345\217\260\345\270\220\347\232\204\357\274\214\345\217\221\347\224\237\347\232\204\345\244\215\346\243\200\343\200\201\346\215\237\345\235\217\343\200\201\347\273\264\344\277\256\343\200\201\344\270\242\345"
                        "\244\261\347\255\211\346\203\205\345\206\265\357\274\214\345\205\254\345\217\270\344\270\215\344\272\210\350\264\237\350\264\243\343\200\202\n"
"\n"
"", Q_NULLPTR));
        author->setText(QApplication::translate("MainWindow", "\345\267\245\347\250\213\346\212\200\346\234\257\351\203\250", Q_NULLPTR));
        publishtime->setText(QApplication::translate("MainWindow", "2014\345\271\2642\346\234\21015\346\227\245 ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\351\242\204\347\272\246\344\272\272", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\346\211\200\345\261\236\345\215\225\344\275\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\351\242\204\347\272\246\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\345\274\240\344\270\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\346\270\205\345\215\216\345\244\247\345\255\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "07/03 15:30 - 07/03 16:30", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(1, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\346\235\216\345\233\233", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(1, 1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\346\270\205\345\215\216\345\244\247\345\255\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(1, 2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "07/03 15:30 - 07/03 16:30", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(2, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\347\216\213\344\272\224", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(2, 1);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\346\270\205\345\215\216\345\244\247\345\255\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(2, 2);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "07/03 15:30 - 07/03 16:30", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(3, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\350\265\265\345\205\255", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(3, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\346\270\205\345\215\216\345\244\247\345\255\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(3, 2);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "07/03 15:30 - 07/03 16:30", Q_NULLPTR));
        tableWidget->setSortingEnabled(__sortingEnabled);

        qrCodeButton->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "\346\211\253\347\240\201\347\231\273\345\275\225\346\233\264\345\277\253\346\215\267", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\350\201\224\347\275\221\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        ipLabel->setText(QApplication::translate("MainWindow", "ip\345\234\260\345\235\200\357\274\232192.168.1.1", Q_NULLPTR));
        netWork->setText(QApplication::translate("MainWindow", "\342\226\240 \347\246\273\347\272\277", Q_NULLPTR));
        qcCodeLabel->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\345\276\256\344\277\241\346\211\253\344\270\200\346\211\253\351\251\254\344\270\212\347\231\273\345\275\225", Q_NULLPTR));
        mcAdminIds->setText(QApplication::translate("MainWindow", "\344\273\252\345\231\250\347\256\241\347\220\206\345\221\230\357\274\232\351\231\210\350\200\201\345\270\210\357\274\21013800138000\357\274\211\357\274\233\347\216\213\350\200\201\345\270\210\357\274\21013800138000\357\274\211", Q_NULLPTR));
        mcName->setText(QApplication::translate("MainWindow", "\344\273\252\345\231\250\345\220\215\347\247\260\357\274\232test\344\273\252\345\231\250", Q_NULLPTR));
        mcNumber->setText(QApplication::translate("MainWindow", "\344\273\252\345\231\250\347\274\226\345\217\267\357\274\232num89798973", Q_NULLPTR));
        accountEdit->setPlaceholderText(QApplication::translate("MainWindow", " \350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\350\264\246\345\217\267", Q_NULLPTR));
        passwordEdit->setPlaceholderText(QApplication::translate("MainWindow", " \350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\345\257\206\347\240\201", Q_NULLPTR));
        loginButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        dynamicLoginButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        dynamicEdit->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\212\250\346\200\201\345\257\206\347\240\201", Q_NULLPTR));
        accountLoginButton->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267\347\231\273\345\275\225", Q_NULLPTR));
        dynamicButton->setText(QApplication::translate("MainWindow", "\345\212\250\346\200\201\347\231\273\345\275\225", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\346\212\200\346\234\257\346\224\257\346\214\201\357\274\232\345\271\277\345\267\236\344\273\252\351\200\237\345\256\211\347\224\265\345\255\220\347\247\221\346\212\200\346\234\211\351\231\220\345\205\254\345\217\270", Q_NULLPTR));
        pushButtonShutdown->setText(QString());
        pushButtonShutMenu->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

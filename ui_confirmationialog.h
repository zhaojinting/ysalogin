/********************************************************************************
** Form generated from reading UI file 'confirmationialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMATIONIALOG_H
#define UI_CONFIRMATIONIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Confirmationialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Confirmationialog)
    {
        if (Confirmationialog->objectName().isEmpty())
            Confirmationialog->setObjectName(QStringLiteral("Confirmationialog"));
        Confirmationialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Confirmationialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Confirmationialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Confirmationialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Confirmationialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Confirmationialog);
    } // setupUi

    void retranslateUi(QDialog *Confirmationialog)
    {
        Confirmationialog->setWindowTitle(QApplication::translate("Confirmationialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Confirmationialog: public Ui_Confirmationialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMATIONIALOG_H

#ifndef CONFIRMATIONIALOG_H
#define CONFIRMATIONIALOG_H

#include <QDialog>
#include "localbit.h"

namespace Ui {
class Confirmationialog;
}

class Confirmationialog : public QDialog
{
    Q_OBJECT

public:
    explicit Confirmationialog(QWidget *parent = 0);
    ~Confirmationialog();

private:
    Ui::Confirmationialog *ui;
};

#endif // CONFIRMATIONIALOG_H

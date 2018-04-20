#ifndef PAY_H
#define PAY_H

#include <QDialog>
#include "user.h"
#include "file.h"

namespace Ui {
class Pay;
}

class Pay : public QDialog
{
    Q_OBJECT

public:
    explicit Pay(QWidget *parent = 0);
    ~Pay();
public:
    char Username [30];
public slots:
    void Paythebill();
    void getthesum();
private slots:
    void on_Cancel_clicked();
private:
    Ui::Pay *ui;
    User u;
    File f;
};

#endif // PAY_H

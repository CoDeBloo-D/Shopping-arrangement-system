#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>
#include "file.h"
#include "users.h"
#include "user.h"

namespace Ui {
class changepassword;
}

class changepassword : public QDialog
{
    Q_OBJECT

public:
    explicit changepassword(QWidget *parent = 0);
    ~changepassword();
public:
    char Username[30];
private slots:
    void change();
    void on_Cancel_clicked();

private:
    Ui::changepassword *ui;
    File f;
    User u;
};

#endif // CHANGEPASSWORD_H

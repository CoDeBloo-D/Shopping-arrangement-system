#ifndef SEARCHITEMBRAND_H
#define SEARCHITEMBRAND_H

#include <QDialog>

namespace Ui {
class SearchItembrand;
}

class SearchItembrand : public QDialog
{
    Q_OBJECT

public:
    explicit SearchItembrand(QWidget *parent = 0);
    ~SearchItembrand();
public slots:
    void send();
signals:
    void senditembrand(QString);
private slots:
    void on_Cancel_clicked();
private:
    Ui::SearchItembrand *ui;
};

#endif // SEARCHITEMBRAND_H

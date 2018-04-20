#ifndef SEARCHITEMNAME_H
#define SEARCHITEMNAME_H

#include <QDialog>

namespace Ui {
class SearchItemname;
}

class SearchItemname : public QDialog
{
    Q_OBJECT

public:
    explicit SearchItemname(QWidget *parent = 0);
    ~SearchItemname();
public slots:
    void send();
signals:
    void senditemname(QString);
private slots:
    void on_Cancel_clicked();

private:
    Ui::SearchItemname *ui;
};

#endif // SEARCHITEMNAME_H

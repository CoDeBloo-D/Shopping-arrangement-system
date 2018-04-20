#ifndef SEARCHITEMVAGUE_H
#define SEARCHITEMVAGUE_H

#include <QDialog>

namespace Ui {
class SearchItemvague;
}

class SearchItemvague : public QDialog
{
    Q_OBJECT

public:
    explicit SearchItemvague(QWidget *parent = 0);
    ~SearchItemvague();
public slots:
    void send();
signals:
    void senditemword(QString);
private slots:
    void on_Cancel_clicked();
private:
    Ui::SearchItemvague *ui;
};

#endif // SEARCHITEMVAGUE_H

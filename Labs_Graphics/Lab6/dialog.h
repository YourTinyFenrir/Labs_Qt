#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMap>
#include <QAbstractButton>
#include <data.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, Data* data = nullptr);
    ~Dialog();
    Data* getData();

public slots:
    void slot_updateData(); // Слот обновления данных

signals:
    void signal_updateData(Data*); // Сигнал обновления данных

private:
    Ui::Dialog *ui;
    QMap<Qt::PenStyle, QString> styles; // Стили пера
};

#endif // DIALOG_H

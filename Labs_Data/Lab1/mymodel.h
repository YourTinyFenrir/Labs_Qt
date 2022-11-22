#ifndef MYMODEL_H
#define MYMODEL_H

#include "QAbstractTableModel"
#include "QVector"
#include "myrect.h"

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MyModel(QAbstractTableModel *parent = nullptr);

    // Заголовки таблицы в виде перечисления
    enum columnNames {PEN_COLOR, PEN_STYLE, PEN_WIDTH, LEFT, TOP, WIDTH, HEIGHT};

    // Наименования стилей пера в виде строк
    const QString styles[7] = {"NoPen", "SolidLine", "DashLine", "DotLine", "DashDotLine", "DashDotDotLine", "CustomDashLine"};
    const int stylesNum = 7;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent  = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool insertRows(int row, int count, const QModelIndex &parent);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void test();

public slots:
    void slot_addData (const MyRect& rect);

private:
    QVector<MyRect> m_vector; // Перечень созданных прямоугольников
    QStringList m_headerData; // Заголовки таблицы
};

#endif // MYMODEL_H

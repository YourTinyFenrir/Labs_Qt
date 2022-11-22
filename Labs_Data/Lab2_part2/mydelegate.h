#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QObject>
#include <QWidget>
#include <QStyledItemDelegate>

class MyDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit MyDelegate(QWidget*) {};

    // Заголовки таблицы в виде перечисления
    enum ColumnNames {ID, PEN_COLOR, PEN_STYLE, PEN_WIDTH, LEFT, TOP, WIDTH, HEIGHT};

    // Наименования стилей пера в виде строк
    const QString styles[7] = {"NoPen", "SolidLine", "DashLine", "DotLine", "DashDotLine", "DashDotDotLine", "CustomDashLine"};
    const int stylesNum = 7;

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);  
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // MYDELEGATE_H

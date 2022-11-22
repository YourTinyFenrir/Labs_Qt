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

    // Наименования стилей пера в виде строк
    const QString styles[7] = {"NoPen", "SolidLine", "DashLine", "DotLine", "DashDotLine", "DashDotDotLine", "CustomDashLine"};
    const int stylesNum = 7;

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

signals:  
};

#endif // MYDELEGATE_H

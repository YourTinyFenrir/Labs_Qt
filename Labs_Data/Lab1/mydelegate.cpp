#include "mydelegate.h"
#include "mymodel.h"
#include <QComboBox>
#include <QEvent>
#include <QMouseEvent>
#include <QColorDialog>

QWidget* MyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // При невыполнении какого-либо условия вызывается метод базового класса

    // Проверяем модельный индекс
    if (!index.isValid()) // Если индекс недействительный
        return QStyledItemDelegate::createEditor(parent, option, index);
    else if (index.column() != MyModel::PEN_STYLE) // Индекс не соответствует колонке «стиля пера»
        return QStyledItemDelegate::createEditor(parent, option, index);

    QComboBox* cb = new QComboBox(parent);

    // Заполняем ComboBox названиями стилей
    for (int i = 0; i < stylesNum; ++i)
        cb->addItem(styles[i], i);

    return cb;
}

void MyDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    // При невыполнении какого-либо условия вызывается метод базового класса

    // Проверяем модельный индекс
    if (!index.isValid()) // Если индекс недействительный
        return QStyledItemDelegate::setEditorData (editor, index);
    else if (index.column() != MyModel::PEN_STYLE) // Индекс не соответствует колонке «стиля пера»
        return QStyledItemDelegate::setEditorData (editor, index);

    QComboBox* cb = static_cast<QComboBox*>(editor); // Явно преобразуем QWidget* в QComboBox*

    const QAbstractItemModel* currentModel = index.model(); // Получим указатель на модель через модельный индекс
    int penStyle = currentModel->data(index, Qt::EditRole).toInt(); // Получаем данные из модели (указываем роль на редактирование)

    int indexCb = cb->findData(penStyle); // Получим индекс, по которому размещены данные
    cb->setCurrentIndex(indexCb); // Устанавливаем текущий индекс
}

void MyDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    // При невыполнении какого-либо условия вызывается метод базового класса

    // Проверяем модельный индекс
    if (!index.isValid()) // Если индекс недействительный
        return QStyledItemDelegate::setModelData(editor, model, index);
    else if (index.column() != MyModel::PEN_STYLE) // Индекс не соответствует колонке «стиля пера»
        return QStyledItemDelegate::setModelData(editor, model, index);

    QComboBox* cb = static_cast<QComboBox*>(editor); // Явно преобразуем QWidget* в QComboBox*
    QVariant penStyle = cb->currentData(); // Получаем стиль пера из ComboBox

    model->setData(index, penStyle); // Помещаем данные в модель
}

bool MyDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    // При невыполнении какого-либо условия вызывается метод базового класса

    // Проверяем модельный индекс
    if (!index.isValid()) // Если индекс недействительный
        return QStyledItemDelegate::editorEvent(event, model, option, index);
    else if (index.column() != MyModel::PEN_COLOR) // Индекс не соответствует колонке «стиля пера»
        return QStyledItemDelegate::editorEvent(event, model, option, index);

    if (event->type() == QEvent::MouseButtonDblClick) { // Если тип действия - двойное нажатия кнопки мыши

        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // Преобразуем QEvent* в QMouseEvent*

        if (mouseEvent->button() == Qt::LeftButton) { // Если нажата левая кнопка мыши

            QColor tempColor = QColorDialog::getColor(); // Открываем окно выбора цвета

            // Если цвет выбран успешно, помешаем его в данные модели
            if (tempColor.isValid())
                model->setData(index, tempColor);

            // Иначе просто ничего не меняем, выходим из функции
            return true;
        }
        else
            return QStyledItemDelegate::editorEvent(event, model, option, index);
    }
    else
        return QStyledItemDelegate::editorEvent(event, model, option, index);
}

#include "mymodel.h"
#include "QIcon"

#include "QDebug"

MyModel::MyModel(QAbstractTableModel *parent) : QAbstractTableModel(parent)
{
    // Формирование списка заголовков
    m_headerData.append("Цвет");
    m_headerData.append("Стиль");
    m_headerData.append("Толщина");
    m_headerData.append("Левая");
    m_headerData.append("Верхняя");
    m_headerData.append("Ширина");
    m_headerData.append("Высота");
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_vector.size();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_headerData.size();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    // Проверяем модельный индекс
    if (!index.isValid()) // Если индекс недействительный
        return QVariant ();

    // Получаем из модельного индекса информацию о расположении данного: строку и столбец
    int row = index.row();
    int column = index.column();

    // Знаем, какая информация хранится в каждом столбце,
    // но помимо самих данных в "ячейке" модели может храниться и дополнительная информация,
    // которую можно задать с помощью ролей - Qt::ItemDataRole

    MyRect mr = m_vector.at(row);

    switch (column) {

        case PEN_COLOR: // Cтолбец с цветом

            switch (role) {

                case Qt::DecorationRole: { // Если View хочет отображать иконку, то создаем ее

                    QPixmap px (32,32);
                    px.fill(mr.penColor());

                    return QIcon(px);
                }
                case Qt::DisplayRole:  // View хочет отображать цвет (в виде строки текста)
                    return mr.penColor().name();
                case Qt::EditRole:   // View хочет редактировать значение цвета (строку)
                    return mr.penColor().name().toInt();
                default:
                    return QVariant();
             }

        case PEN_STYLE: // Столбец со стилем

            switch (role) {

                case Qt::DisplayRole: // Отобразим во View название стиля строкой, а не целочисленным значением
                    return styles[mr.penStyle()];
                case Qt::EditRole: // Для редактирования предоставим числовое значение
                    return int(mr.penStyle()); // Явно приведем перечисление к int
                default:
                    return QVariant();
            }

       case PEN_WIDTH: // Толщина пера

            switch (role) {
                case Qt::DisplayRole:
                    return QString::number(mr.penWidth());
                case Qt::EditRole:
                    return mr.penWidth();
                default:
                    return QVariant();
            }

       case LEFT: // Абсцисса левой верхней точки прямоугольника

            switch (role) {
                case Qt::DisplayRole:
                    return QString::number(mr.rectLeft());
                case Qt::EditRole:
                    return mr.rectLeft();
                default:
                    return QVariant();
            }

       case TOP: // Ордината левой верхней точки прямоугольника

            switch (role) {
                case Qt::DisplayRole:
                    return QString::number(mr.rectTop());
                case Qt::EditRole:
                    return mr.rectTop();
                default:
                    return QVariant();
            }

       case WIDTH: // Ширина прямоугольника

            switch (role) {
                case Qt::DisplayRole:
                    return QString::number(mr.rectWidth());
                case Qt::EditRole:
                    return mr.rectWidth();
                default:
                    return QVariant();
            }

       case HEIGHT: // Высота прямоугольника

            switch (role) {
                case Qt::DisplayRole:
                    return QString::number(mr.rectHeight());
                case Qt::EditRole:
                    return mr.rectHeight();
                default:
                    return QVariant();
            }

       default:
            return QVariant(); // Возвращаем недействительный индекс во всех остальных случаях

    }

}

bool MyModel::insertRows(int row, int count, const QModelIndex &parent = QModelIndex())
{
    Q_UNUSED(parent);

    // beginInsertRows и endInsertRows используем для сохранения целостности модели
    // и возможности оповещения представлений об изменениях

    beginInsertRows(QModelIndex(), row, row+count-1); ; // Диапазон вставляемых строк

    m_vector.insert(row, count, MyRect()); // Вставляем count «пустых» строк

    endInsertRows();

    return true;
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role!= Qt::DisplayRole) // Заголовки нужны только в режиме отображения и изменяться не будут
        return QVariant ();

    if (orientation == Qt::Horizontal)
        return m_headerData.at(section); // Заголовки столбцов
    else
        return QString::number(section); // Возвращаем номера строк
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid()) // Проверка корректности модельного индекса
        return false;

    // Получаем из модельного индекса информацию о расположении данного (строку и столбец)
    int row = index.row();
    int column = index.column();

    if (role == Qt::EditRole) // Работаем только с данными, которые можно редактировать
    {
        // Записываем данные в соответствующий столбец, сохраняем в векторе
        switch (column) {

            case PEN_COLOR:
                m_vector[row].setPenColor(QColor(value.toString()));
            break;

            case PEN_STYLE:
                m_vector[row].setPenStyle(Qt::PenStyle(value.toInt()));
            break;

            case PEN_WIDTH:
                m_vector[row].setPenWidth(value.toReal());
            break;

            case LEFT:
                m_vector[row].setRectLeft(value.toInt());
            break;

            case TOP:
                m_vector[row].setRectTop(value.toInt());
            break;

            case WIDTH:
                m_vector[row].setRectWidth(value.toInt());
            break;

            case HEIGHT:
                m_vector[row].setRectHeight(value.toInt());
            break;

        }

        // После того, как данные установлены, модель должна сообщить представлениям, что некоторые данные изменены.
        emit(dataChanged(index, index));

        return true;
    }

    return false;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) // Проверка корректности модельного индекса
        return Qt::ItemFlags();

    // Добавляем флаг "Редактирование данных"
    Qt::ItemFlags itF = this->QAbstractTableModel::flags(index).setFlag(Qt::ItemIsEditable); // Для получения текущего значения флагов следует вызывать метод базового класса, иначе - рекурсия

    return itF;
}

void MyModel::slot_addData(const MyRect &rect)
{
    insertRows(rowCount(), 1); // Добавляем строку
    m_vector.last().setMyRect(rect); // Помещаем данные
}

void MyModel::test() {
    QPen pen(Qt::red); pen.setStyle(Qt::SolidLine); pen.setWidth(2);
    slot_addData(MyRect(pen, QRect(100, 100, 100, 100)));
    pen.setColor(Qt::green); pen.setStyle(Qt::DotLine); pen.setWidth(3);
    slot_addData(MyRect(pen, QRect(10, 10, 100, 200)));
}

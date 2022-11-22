#include "mywidget.h"
#include <QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;

    w.setPixCursor(QFileDialog::getOpenFileName(0, "Значок для курсора")); // Выбор картинки для курсора

    w.show();

    return a.exec();
}

#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;                         //создаем переводчик
    translator.load("Translations/design_ru.qm",    //имя файла  перевода
                    ".");                           //директория - текущая
    QApplication::installTranslator(&translator);   //применяет переводчик ко всему приложению

    MainWindow w;
    w.show();
    return a.exec();
}

#include "spider.h"
#include <QApplication>
#include <QColorDialog>
#include <QFileDialog>
#include <QTranslator>
#include "QObject"
#include "QLibraryInfo"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Перевод "Собственных" строк
    QTranslator translator;
    translator.load("spider_ru.qm", ".");
    QApplication::installTranslator(&translator);

    // Перевод информации в диалоговых окнах
    QString filespec2 = QString("qt_")+ QLocale::system().name();
    QString directory2 = QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    QTranslator translator2;
    translator2.load(filespec2, directory2);
    QApplication::installTranslator(&translator2);

    Spider w;

    // Установка цветов и изображения для фона окна
    w.setActiveClr(QColorDialog::getColor(Qt::white, 0, QObject::tr("Active")));
    w.setInactiveClr(QColorDialog::getColor(Qt::white, 0, QObject::tr("Inactive")));
    w.setPixmap(QFileDialog::getOpenFileName(0, QObject::tr("Picture")));

    w.show();

    return a.exec();
}


#include "spider.h"
#include "QIcon"
#include "QPalette"
#include "QPixmap"
#include "QBrush"
#include "QGuiApplication"
#include "QScreen"
#include "QTranslator"


Spider::Spider(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle(tr("Lab1 - Spider")); // Установка заголовка окна
    this->setWindowIcon(QIcon("icon2.ico")); // Установка иконки окна

    // Установка первоначального фона
    QPalette pal;
    pal.setColor(QPalette::Window,
                 Qt::cyan);
    this->setPalette(pal);

    //this->setWindowOpacity(0.75); // ??? // Прозрачность окна

    // Размещение окна в IV четверти экрана
    QScreen* scr = QGuiApplication::primaryScreen();
    QRect rect = scr->availableGeometry();
    QPoint ctr = rect.center();
    this->setGeometry(ctr.x(), ctr.y(), 800, 600); // Оно будет расположено в IV четверти экрана
                                                   // левый верхний угол в центре экрана

    // Установка предельных размеров окна
    this->setMinimumSize(400, 300);
    this->setMaximumSize(1600, 1200);

    //this->setFixedSize(400, 400); // Установка фиксированного размера окна

    this->setCursor(Qt::CrossCursor); // Установка курсора

    // Установка курсора из ресурса
    //QPixmap pix(“super_spy.bmp”);
    //pix.setMask(QBitmap(“super_spy.bmp”));
    //this->setCursor(QCursor(pix));

}

void Spider::setActiveClr(QColor clr)
{
    activeClr = clr;
}

void Spider::setInactiveClr(QColor clr)
{
    inactiveClr = clr;
}

void Spider::setPixmap(QPixmap pm)
{
    pMap = pm;
}

Spider::~Spider()
{

}

void Spider::changeEvent(QEvent* ev)
{

    QPalette pal;

    if (this->palette().currentColorGroup() == QPalette::Active) { // Если окна активно - установить выбранный цвет фона
        pal.setColor(QPalette::Window,
                     activeClr);
        this->setPalette(pal);
    }
    else {

          // Установить выбранный цвет фона
//        pal.setColor(QPalette::Window,
//                     inactiveClr);

          // Установить фоновое изображние
//        QPixmap pix("home/dgnezdilov/LvovDV/Labs/Lab1/WomanAndDog.jpg");  // ???
//        pal.setBrush(QPalette::Window,
//                     QBrush(pix));

          // Установить фоновое изображние
          pal.setBrush(QPalette::Window,
                       QBrush(pMap));

          // Установить фоновый паттерн заданного цвета
//        QBrush brush (Qt::red,
//                      Qt::CrossPattern);
//        pal.setBrush(QPalette::Window,
//                     brush);

        this->setPalette(pal);
    }

}

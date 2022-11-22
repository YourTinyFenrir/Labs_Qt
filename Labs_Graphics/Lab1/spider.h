#ifndef SPIDER_H
#define SPIDER_H

#include <QWidget>
#include "QCursor"

class Spider : public QWidget
{
    Q_OBJECT

public:
    Spider(QWidget *parent = 0);
    void setActiveClr(QColor);
    void setInactiveClr(QColor);
    void setPixmap(QPixmap);
    ~Spider();

protected:
    void changeEvent(QEvent*);

private:
    QColor activeClr;
    QColor inactiveClr;
    QPixmap pMap;

};

#endif // SPIDER_H

#include "clock.h"

Clock::Clock()
{
    time = 30;
    setPlainText(QString("Time:"+QString::number(time)));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",30));
    QTimer* clo = new QTimer();
    clo->start(1000);
    connect(clo,SIGNAL(timeout()),this,SLOT(decrease()));

}

void Clock::decrease()
{

    if(time>0)
    {
        time--;
        setPlainText(QString("Time:"+QString::number(time)));
    }
    if(time==0)
    {
        time=0;
    }
}

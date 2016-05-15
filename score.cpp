#include "score.h"

Score::Score()
{
    score = 0;
    setPlainText(QString("Score:"+QString::number(score)));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",30));
    QTimer* sco = new QTimer();
    sco->start(1000);
    increase();

}

void Score::increase()
{

    if(score++)
    {
       setPlainText(QString("Score:"+QString::number(score)));
    }
}


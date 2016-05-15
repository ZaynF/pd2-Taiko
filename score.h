#ifndef SCORE_H
#define SCORE_H

#include <QFont>
#include <QGraphicsScene>
#include <QTimer>
#include <QString>
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score();
    int score;
public slots:
    void increase();


};

#endif // SCORE_H

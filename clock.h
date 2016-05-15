#ifndef CLOCK_H
#define CLOCK_H

#include <QFont>
#include <QTimer>
#include <QGraphicsScene>
#include <QString>
#include <QGraphicsTextItem>
class Clock : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Clock();

    int time;
public slots:
    void decrease();
};

#endif // CLOCK_H

#ifndef DRUM_H
#define DRUM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

using namespace std;

class Drum : public QGraphicsPixmapItem
{
public:
    Drum();
    int x_speed=0;
    void setSpeed(int speed);
    void advance(int phase);
};

#endif // DRUM_H

#include "drum.h"

Drum::Drum()
{
    setSpeed(0);
}

void Drum::setSpeed(int speed)
{
    x_speed = -speed;
}

void Drum::advance(int phase)
{
    this->setPos(this->pos().x()+x_speed,this->pos().y());
}

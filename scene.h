#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QSound>
#include <QString>
#include <QList>
#include <QKeyEvent>
#include <QFont>
#include <QGraphicsTextItem>
#include "btn.h"
#include "drum.h"
#include "point.h"
#include "clock.h"
#include "score.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    /* function */
    Scene();
    void Init(int x_start ); // For screen initialize
    void bgChange(); // For background change from start to game
    void bgRecover(); // For background change back to start page
    void gameInit(); // Start the game page
    void movingBlock(); // Moving block down
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse);
    void keyPressEvent(QKeyEvent *event);
    void geneDrum();
    void bgclose();
    /* Variable */
    // For button
    Btn *btn_start;
    Btn *btn_close;
    Btn *btn_change_ball;
    Btn *btn_pause;
    Btn *btn_conti;
    Btn *btn_back;
    Point *pt;
    int btn_w;
    int btn_h;
    int btn_small_w;
    int btn_small_h;
    int pt_w;
    int pt_h;
    QList<Drum *> drum_list;
    QList<int> rand_list;
    Clock *clo;
    int clo_time;
    Score *sco;
    // For game item
    int ch_y_pos;
    // For sound
    QSound *bgm;
    // For timer
    QTimer *timer;
    /* Use to control the scene page */
    int screenMode;
    // For scene boundary
    int upperBound;
    int lowerBound;
    int leftBound;
    int rightBound;

public slots:

};

#endif // SCENE_H

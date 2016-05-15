#include "scene.h"

Scene::Scene()
{
    screenMode = 0;
}

void Scene::Init(int x_start)
{
    // start
    btn_start = new Btn();
    QPixmap start;
    start.load(":/image/img/begin.png");
    start = start.scaled(start.width()*3/2,start.height()*3/2,Qt::KeepAspectRatio);
    btn_w = (start.width()*3)/2 - 60;
    btn_h = (start.height()*3)/2 - 30;
    btn_start->setPixmap(start);
    btn_start->setPos(890,440);
    addItem(btn_start);
    //
    btn_close= new Btn();
    QPixmap close;
    close.load(":/image/img/quit.png");
    close = close.scaled((close.width()*3)/2,(close.height()*3)/2,Qt::KeepAspectRatio);
    btn_close->setPixmap(close);
    btn_close->setPos(0,440);
    addItem(btn_close);



    //  setting the boundary , only lowerBound has a little different
    leftBound = x_start-25.6;
    rightBound = leftBound+512;
    upperBound = 33;


}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouse)//改change ball
{
    if(screenMode == 0)
    {
        // Beginning page
        if(mouse->scenePos().x() > btn_start->pos().x() && mouse->scenePos().x() <= btn_start->pos().x()+btn_w)
        {
            // Now x is in range , judge y
            if(mouse->scenePos().y() > btn_start->pos().y() && mouse->scenePos().y() <= btn_start->pos().y()+btn_h)
            {
                // x , y both in button area
                cout<< "Start Game"<< endl;
                // Clear original background
                bgChange();
                screenMode = 1;
            }
        }
        // or click on close
        if(mouse->scenePos().x() > btn_close->pos().x() && mouse->scenePos().x() <= btn_close->pos().x()+btn_w)
        {
            // Now x is in range , judge y
            if(mouse->scenePos().y() > btn_close->pos().y() && mouse->scenePos().y() <= btn_close->pos().y()+btn_h)
            {
                // x , y both in button area

                screenMode = 2; // mode to change ball
            }
        }
    }
    else if(screenMode == 1)//restart the game
    {
        // Starting Page
        if(mouse->scenePos().x() > btn_back->pos().x() && mouse->scenePos().x() <= btn_back->pos().x()+btn_small_w)
        {
            // Now x is in range , judge y
            if(mouse->scenePos().y() > btn_back->pos().y() && mouse->scenePos().y() <= btn_back->pos().y()+btn_small_h)
            {
                // x , y both in back button area
                removeItem(clo);
                for(int i=0;i<75;i++)
                {
                    removeItem(drum_list[i]);
                    drum_list[i]->setSpeed(1);
                }

                bgm->stop();
                removeItem(pt);
                bgChange();
                screenMode = 0;
            }
        }
        // Starting Page setting - shooting point

        // Goto setting the game initial
        gameInit();
        screenMode = 3;

    }
    else if(screenMode == 2)
    {

        if(mouse->scenePos().x() > btn_back->pos().x() && mouse->scenePos().x() <= btn_back->pos().x()+btn_small_w)
        {
            // Now x is in range , judge y
            if(mouse->scenePos().y() > btn_back->pos().y() && mouse->scenePos().y() <= btn_back->pos().y()+btn_small_h)
            {
                // x , y both in back button area
                bgRecover();
                screenMode = 0;
            }
        }

    }
    else if(screenMode == 3)//restart the game
    {
        if(mouse->scenePos().x() > btn_back->pos().x() && mouse->scenePos().x() <= btn_back->pos().x()+btn_small_w)
        {
            // Now x is in range , judge y
            if(mouse->scenePos().y() > btn_back->pos().y() && mouse->scenePos().y() <= btn_back->pos().y()+btn_small_h)
            {
                // x , y both in back button area
                removeItem(clo);
                for(int i=0;i<75;i++)
                {
                    removeItem(drum_list[i]);
                    drum_list[i]->setSpeed(1);
                }

                bgm->stop();
                removeItem(pt);
                bgChange();
                //bgRecover();
                screenMode = 1;
            }
        }

    }
    /* For debugging */
    //cout << "btn start x: " << btn_start->pos().x()<< " btn start y: " << btn_start->pos().y() << endl;
    //cout << "Now event x: " << event->scenePos().x()<< " event y: " << event->scenePos().y() << endl;
}


void Scene::bgChange()
{
    /* first , change background picture */
    QImage bg;
    bg.load(":/image/img/gamepage.jpg");
    bg = bg.scaled(1000,563);
    this->setBackgroundBrush(bg);
    /* second , remove btn - start and close */
    this->removeItem(btn_start);
    this->removeItem(btn_close);

    // Back buttom setting
    btn_back = new Btn();
    QPixmap bk;
    bk.load(":/image/img/return.png");
    btn_small_w = bk.width()*2/3;
    btn_small_h = bk.height()*2/3;
    bk = bk.scaled(btn_small_w , btn_small_h ,Qt::KeepAspectRatio);
    btn_back->setPixmap(bk);
    btn_back->setPos(0,5);
    addItem(btn_back);

    pt = new Point();//creat the point to hit the drum
    QPixmap pit;
    pit.load(":/image/img/point.png");
    pit = pit.scaled(pit.width(),pit.height(),Qt::KeepAspectRatio);
    pt_w = pit.width();
    pt_h = pit.height();
    pt->setPixmap(pit);
    pt->setPos(0,300);
    addItem(pt);

    clo = new Clock();//set the timer for count down
    clo->setPos(800,100);
    addItem(clo);
    clo_time=clo->time;
    if(clo_time==0)
    {
        for(int i=0;i<75;i++)
        {
            removeItem(drum_list[i]);
        }
    }

    sco = new Score();
    sco->setPos(800,50);
    addItem(sco);

    // Setting the sound
    bgm = new QSound(":/sound/sound/The Beginning1.wav");
    bgm->play();

    // save the initial position
    ch_y_pos = 450;
    // save the initial lowerBoundary
    lowerBound = 450+50; // 50 is the bias (every picture's have it's original boundary)

    // Setting the ball on it

    // Setting the character on it

    geneDrum();
    for(int i=0;i<75;i++)
    {
        drum_list[i]->setPos(1050+200*i,320);
        this->addItem(drum_list[i]);
    }
    gameInit();

}

void Scene::bgRecover()
{
    // remove item here
    removeItem(btn_back);
    for(int i=0;i<75;i++)
    {
        removeItem(drum_list[i]);
        drum_list[i]->setSpeed(1);
    }

    bgm->stop();

    removeItem(pt);
    removeItem(clo);

    // add back initial page
    addItem(btn_start);
    addItem(btn_close);
    QImage bg;
    bg.load(":/image/img/startpage.jpg");
    bg = bg.scaled(1000,563);
    this->setBackgroundBrush(bg);


    // Setting the sound => Play again the sound
    //bgm->play();
}

void Scene::gameInit()
{
    // Set up timer to control each item
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(advance()));
    timer->start(10);


}

void Scene::geneDrum()
{
    for(int i=0;i<75;i++)
    {
        rand_list.push_back(qrand()%2+1);
    }

    for(int i=0;i<75;i++)
    {
        if(rand_list[i]==1)
        {
            Drum *dr1 = new Drum();
            QPixmap dr1_pic;
            dr1_pic.load(":/image/img/pullo-1.png");
            dr1_pic = dr1_pic.scaled(80,80,Qt::KeepAspectRatio);
            dr1->setPixmap(dr1_pic);
            dr1->setSpeed(1);
            drum_list.push_back(dr1);
        }

        else if(rand_list[i]==2)
        {
            Drum *dr2 = new Drum();
            QPixmap dr2_pic;
            dr2_pic.load(":/image/img/pullo-2.png");
            dr2_pic = dr2_pic.scaled(80,80,Qt::KeepAspectRatio);
            dr2->setPixmap(dr2_pic);
            dr2->setSpeed(1);
            addItem(dr2);
            drum_list.push_back(dr2);
        }
    }
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    for(int i=0;i<75;i++)
    {
        if(rand_list[i]==1)
        {
            if(event->key()==Qt::Key_J)
            {
                if(this->drum_list[i]->x()>pt->pos().x()-20&&this->drum_list[i]->x()<= pt->pos().x()+pt_w)
                    removeItem(drum_list[i]);
                    sco->score++;
                    //setPlainText(QString("Score:"+QString::number(sco->score)));
            }
        }
        else if(rand_list[i]==2)
        {
            if(event->key()==Qt::Key_K)
            {
                if(this->drum_list[i]->x()>pt->pos().x()&&this->drum_list[i]->x()<= pt->pos().x()+pt_w)
                    removeItem(drum_list[i]);
                    sco->score++;
                            //setPlainText(QString("Score:"+QString::number(sco->score)));
            }
        }
    }
}



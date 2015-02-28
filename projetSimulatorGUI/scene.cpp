#include "scene.h"
//#include <QGraphicsProxyWidget>
//#include <QImage>
//#include <QPainter>
//#include <QPushButton>
#include "escaliers.h"
#include "zonedepart.h"
#include "centreterrain.h"
#include "distributeurpopcorne.h"
#include "robot.h"
#include "math.h"
#include "exemplerobot.h"
Scene::Scene(): QGraphicsScene()
{
    // size to scene
    setSceneRect(0,0, 900, 600);
    setBackgroundBrush(Qt::white);
    QLineF lineTop(sceneRect().topLeft(),
                    sceneRect().topRight());
     QLineF lineBottom(sceneRect().bottomLeft(),
                       sceneRect().bottomRight());
     QLineF lineLeft(sceneRect().topLeft(),
                     sceneRect().bottomLeft());
     QLineF lineRight(sceneRect().topRight(),
                      sceneRect().bottomRight());
     QPen pen(Qt::red);

     addLine(lineTop, pen);
     addLine(lineBottom, pen);
     addLine(lineLeft, pen);
     addLine(lineRight, pen);
   // QPushButton *bouton = new QPushButton("Mon bouton entre en scène !");
   // QGraphicsRectItem *rect = new QGraphicsRectItem(100,0,300,100);
   // rect->setBrush(QBrush(Qt::red));
   //addItem(rect);
    // escaliers
    myescaliersdroit = new Escaliers();
    addItem(myescaliersdroit);
    myescaliersgauche = new Escaliers();
    myescaliersgauche->setX(150);
    myescaliersgauche->setBrush(QBrush(Qt::green));
    addItem(myescaliersgauche);
    //zone de depart
    departMurAgauche =  new zoneDepart();
    addItem(departMurAgauche);
    departMurAdroite = new zoneDepart();
    departMurAdroite->setY(150);
    addItem(departMurAdroite);
    // zone de depart adversaire
        //a gauche
    departMurAgaucheAdversaire = new zoneDepart();
    departMurAgaucheAdversaire->setX(800);
    departMurAgaucheAdversaire->setBrush(QBrush(Qt::green));
    addItem(departMurAgaucheAdversaire);
        //a droite
    departMurADroiteAdversaire = new zoneDepart();
    departMurADroiteAdversaire->setX(800);
    departMurADroiteAdversaire->setY(150);
    departMurADroiteAdversaire->setBrush(QBrush(Qt::green));
    addItem(departMurADroiteAdversaire);
    // centre du terrain
    centre = new centreTerrain();
    centre->setX(300);
    addItem(centre);
    // distributeur a gauche
    distributeurGauche = new DistributeurPopCorne();
    addItem(distributeurGauche);
    //distributeur à droite
    distributeurDroite = new DistributeurPopCorne();
    distributeurDroite->setX(600);
    addItem(distributeurDroite);
    //spot et balle de tennis

    //les claps

    //claps1
    claps1 = new claps();
    addItem(claps1);
    //claps2
    claps2 = new claps();
    claps2->setX(50);
    claps2->setBrush(QBrush(Qt::yellow));
    addItem(claps2);
    //claps3
    claps3 = new claps();
    claps3->setX(100);
    addItem(claps3);

    //claps4
    claps4 = new claps();
    claps4->setX(500);
    addItem(claps4);
    //claps2
    claps5 = new claps();
    claps5->setX(550);
    claps5->setBrush(QBrush(Qt::yellow));
    addItem(claps5);
    //claps3
    claps6 = new claps();
    claps6->setX(600);
    addItem(claps6);

    //robot
    Robot *myrobot = new Robot();
    addItem(myrobot);
    robot *myrobot2 = new robot();
    addItem(myrobot2);
}

Scene::~Scene()
{

}

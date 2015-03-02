#include "Scene.h"
#include "Parameters.h"
//#include <QDebug>
#include <QGraphicsRectItem>
#include <iostream>
using namespace std;
using namespace Parameters;


Scene::Scene() : QGraphicsScene()
{
    /*SimpleTower * simpleTower = new SimpleTower();
    simpleTower->setPos(200.0, 100.0);
    addItem(simpleTower);
    ...*/

    setSceneRect(0, 0, SIMULATOR_SCREEN_WIDTH, SIMULATOR_SCREEN_HEIGHT);
    setBackgroundBrush(Qt::blue);
    QLineF lineTop(sceneRect().topLeft(),
                    sceneRect().topRight());
    QLineF lineBottom(sceneRect().bottomLeft(),
                       sceneRect().bottomRight());
    QLineF lineLeft(sceneRect().topLeft(),
                     sceneRect().bottomLeft());
    QLineF lineRight(sceneRect().topRight(),
                      sceneRect().bottomRight());
    QPen pen(Qt::red);
    //QBrush brush(Qt::red);

    addLine(lineTop, pen);
    addLine(lineBottom, pen);
    addLine(lineLeft, pen);
    addLine(lineRight, pen);

    pen.setColor(black);
    cout << "Scene created..." << endl;
}

Scene::~Scene()
{
    cout << "...Scene destroyed." << endl;
}

void Scene::bindPlayingArea(PlayingArea* area)
{
    p_playingArea = area;
}

// Called only once after constructing.
void Scene::initDrawFixedObjects()
{
    QPen pen(Qt::black);
    QBrush brush(Qt::black);

    vector<FixedObject*> fixedObjects = p_playingArea->getAllFixedObjects();
    for(unsigned int idx = 0; idx < fixedObjects.size(); idx++)
    {
        FixedObject* obj = fixedObjects[idx];
        int x = obj->getXStart();
        int y = obj->getYStart();
        int w = obj->getWidth();
        int h = obj->getHeight();
        int xScaled,
            yScaled,
            widthScaled,
            heightScaled;
        scaleCoordinatesOfRectangle(x, y, w, h, &xScaled, &yScaled, &widthScaled, &heightScaled);
        obj->showObjectInfo();
        //cout << "SCALED x,y,w,h: " << xScaled << ", " << yScaled << ", " << widthScaled << ", " << heightScaled << endl;
        brush.setColor(obj->getColor());
        addRect(xScaled, yScaled, widthScaled, heightScaled, pen, brush);
    }
}

// Called once after the constructor.
void Scene::initDrawRobot()
{
    QPen pen(Qt::black);
    QBrush brush(Qt::black);
    Robot* robot = p_playingArea->getTheOnlyRobot();
    int x = robot->getX() - 0.5*robot->getLength();
    int y = robot->getY() - 0.5*robot->getWidth();
    int w = robot->getLength();
    int h = robot->getWidth();
    int xScaled,
        yScaled,
        widthScaled,
        heightScaled;
    scaleCoordinatesOfRectangle(x, y, w, h, &xScaled, &yScaled, &widthScaled, &heightScaled);
    brush.setColor(Qt::black);
    addRect(xScaled, yScaled, widthScaled, heightScaled, pen, brush);
}

void Scene::redrawScene()
{
    cout << "REFRESHING SCENE!" << endl;
    initDrawRobot();
}

// Coordinates translation between PlayingArea (3000x2000) and Simulator GUI swindow (900x600)
void Scene::scaleCoordinatesOfRectangle(int x, int y, int w, int h, int* xScaled, int* yScaled, int* widthScaled, int* heightScaled)
{
    double scaleFactorX = 1.0 * SIMULATOR_SCREEN_WIDTH / TABLE_WIDTH;
    double scaleFactorY = 1.0 * SIMULATOR_SCREEN_HEIGHT / TABLE_HEIGHT;
    *xScaled = x * scaleFactorX;
    *yScaled = y * scaleFactorY;
    *widthScaled = w * scaleFactorX;
    *heightScaled = h * scaleFactorY;
}


/*
void Scene::advance()
{
    //   m_TicTacTime++;

    while (i<items().count())
    {
        item=items().at(i);
        unit=dynamic_cast<MobileUnit* > (item);
        if ( ( unit!=NULL) && (unit->isFinished()==true))
        {
            removeItem(item);
            delete unit;
        }
        else ++i;
    }

    // Add new units every 20 tictacs
    if(m_TicTacTime % 20==0)
    {
        // qDebug() << "add unit";
        MobileUnit * mobileUnit = new MobileUnit();
        qreal h = static_cast<qreal>( qrand() % static_cast<int>(height()) );
        mobileUnit->setPos(width(), h);
        addItem(mobileUnit);
    }

    QGraphicsScene::advance();
    update();
}
*/

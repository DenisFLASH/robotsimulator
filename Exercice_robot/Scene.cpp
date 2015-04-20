#include "Scene.h"
#include "MathUtils.h"
#include "Parameters.h"
//#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <iostream>
using namespace std;
using namespace Parameters;
using namespace MathUtils;


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
    pen.setWidth(5);
    //QBrush brush(Qt::red);

    addLine(lineTop, pen);
    addLine(lineBottom, pen);
    addLine(lineLeft, pen);
    addLine(lineRight, pen);

    pen.setColor(black);
    cout << "Scene created..." << endl;
    // adding robot's copy
    // p_sceneRobot = new Robot("scaled",400,400,10,10,0);
    //addItem(p_sceneRobot);
}

Scene::~Scene()
{
    cout << "...Scene destroyed." << endl;
}

void Scene::bindPlayingArea(PlayingArea* area)
{
    p_playingArea = area;
    setP_sceneRobot(p_playingArea->getTheOnlyRobot());
    addItem(p_sceneRobot);
}

void Scene::advance()
{
    QGraphicsScene::advance();
    update();
}
Robot *Scene::getP_sceneRobot() const
{
    return p_sceneRobot;
}

void Scene::setP_sceneRobot(Robot *value)
{
    p_sceneRobot = value;
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

void Scene::redrawScene()
{

}

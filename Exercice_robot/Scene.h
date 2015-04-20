#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "PlayingArea.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene();
    ~Scene();
    void bindPlayingArea(PlayingArea* area);
    void initDrawFixedObjects();
    void initDrawRobot();
    Robot *getP_sceneRobot() const;
    void setP_sceneRobot(Robot *value);

public slots:
    void advance();

private:
    PlayingArea* p_playingArea;
    Robot* p_sceneRobot;

public slots:
    void redrawScene();

};

#endif // SCENE_H

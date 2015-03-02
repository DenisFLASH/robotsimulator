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

private:
    PlayingArea* p_playingArea;
    void scaleCoordinatesOfRectangle(int x, int y, int w, int h, int* xScaled, int* yScaled, int* widthScaled, int* heightScaled);

public slots:
    void redrawScene();

};

#endif // SCENE_H

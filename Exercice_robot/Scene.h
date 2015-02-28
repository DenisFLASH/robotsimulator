#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "PlayingArea.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(PlayingArea* area);
    ~Scene();
private:
    PlayingArea* p_playingArea;

    void scaleCoordinatesOfFixedObject(FixedObject* obj, int* xScaled, int* yScaled, int* widhtScaled, int* heightScaled);

/*public slots:
    void advance();
private:
    int m_TicTacTime;*/
};

#endif // SCENE_H

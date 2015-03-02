#ifndef SIMULATORENGINE_H
#define SIMULATORENGINE_H

#include "PlayingArea.h"
#include <QObject>

class SimulatorEngine : public QObject
{
    Q_OBJECT

public:
    SimulatorEngine();
    ~SimulatorEngine();
    void bindPlayingArea(PlayingArea* area);
    PlayingArea* getPlayingArea();
    //void run();

public slots:
    void step();


private:
    PlayingArea* p_playingArea;
    QTimer* p_simulatorStepTimer;

private:
    void refreshRobotCoordinates(Robot* robot);
    bool isRobotOutsideTable(Robot* robot);
    bool isCollisionBetweenRobotAndFixedObject(Robot* robot, FixedObject* fixedObject);
    bool areRectanglesColliding(int Ax1,int Ay1,int Ax2,int Ay2,int Ax3,int Ay3,int Ax4,int Ay4,int Bx1,int By1,int Bx2,int By2,int Bx3,int By3,int Bx4,int By4);
    bool isPointInsideRectangle(int x, int y, int xMin, int xMax, int yMin, int yMax);
};



#endif // SIMULATORENGINE_H

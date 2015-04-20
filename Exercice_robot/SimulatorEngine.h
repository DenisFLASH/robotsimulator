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

    Robot* getRobot() const;
    void setRobot(Robot* value);

public slots:
    void step();


private:
    PlayingArea* p_playingArea;
    Robot* p_robot;
    QTimer* p_simulatorStepTimer;

private:
    void refreshRobotCoordinates(Robot* robot);
    bool isRobotOutsideTable(Robot* robot);
    bool isCollisionBetweenRobotAndFixedObject(Robot* robot, FixedObject* fixedObject);
};



#endif // SIMULATORENGINE_H

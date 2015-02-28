#ifndef SIMULATORENGINE_H
#define SIMULATORENGINE_H

#include "PlayingArea.h"
#include <QtCore>

class SimulatorEngine : public QThread
{
private:
    PlayingArea* p_playingArea;

public:
    SimulatorEngine();
    ~SimulatorEngine();
    void bindPlayingArea(PlayingArea* area);
    PlayingArea* getPlayingArea();
    void run();

private:
    void refreshRobotCoordinates(Robot* robot);
    bool isRobotOutsideTable(Robot* robot);
};



#endif // SIMULATORENGINE_H

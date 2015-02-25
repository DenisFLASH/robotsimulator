#ifndef SIMULATORENGINE_H
#define SIMULATORENGINE_H

#include "PlayingArea.h"


class SimulatorEngine
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
    void refreshCoordinates();
};



#endif // SIMULATORENGINE_H

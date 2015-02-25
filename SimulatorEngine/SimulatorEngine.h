#ifndef SIMULATORENGINE_H
#define SIMULATORENGINE_H

#include "PlayingArea.h"

class SimulatorEngine
{
private:
    PlayingArea* p_playingArea;

public:
    SimulatorEngine(PlayingArea* playingArea);

    void step();
};

#endif // SIMULATORENGINE_H

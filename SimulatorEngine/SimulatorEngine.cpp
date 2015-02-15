#include "SimulatorEngine.h"
#include <iostream>
//#include <unistd.h>
using namespace std;


/* --- PRIVATE METHODS --- */
void showFixedObjects(PlayingArea* playingArea)
{
    vector<FixedObject*> allFixedObjects = playingArea->getAllFixedObjects();
    cout << "Showing " << allFixedObjects.size() << " fixed objects:" << endl;
    for(unsigned int i = 0; i < allFixedObjects.size(); i++)
    {
        allFixedObjects[i]->showObjectInfo();
    }
}

void showMobileObjects(PlayingArea* playingArea)
{
    vector<MobileObject*> allMobileObjects = playingArea->getAllMobileObjects();
    cout << "Showing " << allMobileObjects.size() << " mobile objects:" << endl;
    for(unsigned int i = 0; i < allMobileObjects.size(); i++)
    {
        allMobileObjects[i]->showObjectInfo();
    }
}


/* --- PUBLIC METHODS --- */
SimulatorEngine::SimulatorEngine(PlayingArea* playingArea)
{
    p_playingArea = playingArea;
    showFixedObjects(p_playingArea);
    showMobileObjects(p_playingArea);

/*
    Robot * robot1 = new Robot(Parameters::TEAM_A_MAIN_ROBOT_INIT_X, Parameters::TEAM_A_MAIN_ROBOT_INIT_Y,
                               Parameters::TEAM_A_MAIN_ROBOT_RADIUS, Parameters::TEAM_A_MAIN_ROBOT_SPEED,
                               Parameters::EAST);
    m_robots.push_back(robot1);


    for ( int i = 0; i < m_robots.size(); i++ )
    {
        m_robots[i]->init();
    }

    while(1)
    {
        usleep(Parameters::STEP_DURATION_MICROSECONDS);
        for ( int i = 0; i < m_robots.size(); i++ )
        {
            m_robots[i]->step();
        }
    }
    */

}

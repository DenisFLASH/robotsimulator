#ifndef PLAYINGAREA_H
#define PLAYINGAREA_H

#include "FixedObject.h"
//#include "MobileObject.h"
#include "Robot.h"
#include <vector>
using namespace std;

class PlayingArea
{
private:
    int m_width,
        m_height;
    vector<FixedObject*> p_allFixedObjects;
    Robot* p_theOnlyRobot;
    //vector<MobileObject*> p_allMobileObjects;


private:
    void createFixedWorld();

public:
    PlayingArea();
    ~PlayingArea();
    vector<FixedObject*> getAllFixedObjects();
    //vector<MobileObject*> getAllMobileObjects();
    Robot* getTheOnlyRobot();
    void setTheOnlyRobot(Robot* robot);

    int getWidth();
    int getHeight();
};

#endif // PLAYINGAREA_H


#ifndef PLAYINGAREA_H
#define PLAYINGAREA_H

#include "FixedObject.h"
#include "MobileObject.h"
#include <vector>
using namespace std;

class PlayingArea
{
private:
    int m_width,
        m_height;
    vector<FixedObject*> p_allFixedObjects;
    vector<MobileObject*> p_allMobileObjects;

private:
    void createWorld();

public:
    PlayingArea();
    int getWidth();
    int getHeight();
    vector<FixedObject*> getAllFixedObjects();
    vector<MobileObject*> getAllMobileObjects();
};

#endif // PLAYINGAREA_H


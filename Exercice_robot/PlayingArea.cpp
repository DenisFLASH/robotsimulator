#include "PlayingArea.h"
#include "Parameters.h"
#include "Robot.h"
#include <iostream>
using namespace std;
using namespace Parameters;


PlayingArea::PlayingArea()
{
    m_width = Parameters::TABLE_WIDTH;
    m_height = Parameters::TABLE_HEIGHT;
    createFixedWorld();
    cout << "PlayingArea created (" << p_allFixedObjects.size() << " fixed objects)..." << endl;
}

PlayingArea::~PlayingArea()
{
    cout << "...PlayingArea destroyed." << endl;
}

void PlayingArea::createFixedWorld()
{
    FixedObject* zoneATasseauHorizontal1 = new FixedObject("zoneATasseauHorizontal1", 0,788,400,22,22); // 800-22
    FixedObject* zoneATasseauHorizontal2 = new FixedObject("zoneATasseauHorizontal2", 0,1222,400,22,22); // 1200+22
    FixedObject* zoneATasseauVertical1 = new FixedObject("zoneATasseauVertical1", 48,800,22,165,22); // 70-22
    FixedObject* zoneATasseauVertical2 = new FixedObject("zoneATasseauVertical2", 48,1035,22,165,22); // 70-22
    FixedObject* zoneAEstrade = new FixedObject("zoneAEstrade", 0,965,70,70,22); // 1000-35

    FixedObject* zoneBTasseauHorizontal1 = new FixedObject("zoneBTasseauHorizontal1", 1600,788,400,22,22); // 800-22
    FixedObject* zoneBTasseauHorizontal2 = new FixedObject("zoneBTasseauHorizontal2", 1600,1222,400,22,22);// 1200+22
    FixedObject* zoneBTasseauVertical1 = new FixedObject("zoneBTasseauVertical1", 1930,800,22,165,22); // 2000-70
    FixedObject* zoneBTasseauVertical2 = new FixedObject("zoneBTasseauVertical2", 1930,1035,22,165,22);// 2000-70
    FixedObject* zoneBEstrade = new FixedObject("zoneBEstrade", 1930,965,70,70,22); // 2000-70

    //FixedGameObject* escalierAMarche1 = new FixedGameObject(1100,0,400,500,22);
    FixedObject* estrade = new FixedObject("estrade", 1200,1900,600,100,22);

    p_allFixedObjects.push_back(zoneATasseauHorizontal1);
    p_allFixedObjects.push_back(zoneATasseauHorizontal2);
    p_allFixedObjects.push_back(zoneATasseauVertical1);
    p_allFixedObjects.push_back(zoneATasseauVertical2);
    p_allFixedObjects.push_back(zoneAEstrade);
    p_allFixedObjects.push_back(zoneBTasseauHorizontal1);
    p_allFixedObjects.push_back(zoneBTasseauHorizontal2);
    p_allFixedObjects.push_back(zoneBTasseauVertical1);
    p_allFixedObjects.push_back(zoneBTasseauVertical2);
    p_allFixedObjects.push_back(zoneBEstrade);
    p_allFixedObjects.push_back(estrade);
}

int PlayingArea::getWidth()
{
    return m_width;
}

int PlayingArea::getHeight()
{
    return m_height;
}

vector<FixedObject*> PlayingArea::getAllFixedObjects()
{
    return p_allFixedObjects;
}

/*vector<MobileObject*> PlayingArea::getAllMobileObjects()
{
    return p_allMobileObjects;
}*/

Robot* PlayingArea::getTheOnlyRobot()
{
    return p_theOnlyRobot;
}

void PlayingArea::setTheOnlyRobot(Robot* robot)
{
    p_theOnlyRobot = robot;
}

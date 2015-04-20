#include "PlayingArea.h"
#include "Parameters.h"
#include "Robot.h"
#include <iostream>
using namespace std;
using namespace Qt;
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
    for (unsigned int i = 0; i < p_allFixedObjects.size(); i++)
    {
        delete p_allFixedObjects[i];
    }
    cout << "...PlayingArea destroyed." << endl;
}

void PlayingArea::createFixedWorld()
{
    FixedObject* zoneATasseauHorizontal1 = new FixedObject("zoneATasseauHorizontal1", yellow, 0,788,400,22,22); // 800-22
    FixedObject* zoneATasseauHorizontal2 = new FixedObject("zoneATasseauHorizontal2", yellow, 0,1222,400,22,22); // 1200+22
    FixedObject* zoneATasseauVertical1 = new FixedObject("zoneATasseauVertical1", yellow, 48,800,22,165,22); // 70-22
    FixedObject* zoneATasseauVertical2 = new FixedObject("zoneATasseauVertical2", yellow, 48,1035,22,165,22); // 70-22
    FixedObject* zoneAEstrade = new FixedObject("zoneAEstrade", yellow, 0,965,70,70,22); // 1000-35

    FixedObject* zoneBTasseauHorizontal1 = new FixedObject("zoneBTasseauHorizontal1", green, 2600,788,400,22,22); // 800-22
    FixedObject* zoneBTasseauHorizontal2 = new FixedObject("zoneBTasseauHorizontal2", green, 2600,1222,400,22,22);// 1200+22
    FixedObject* zoneBTasseauVertical1 = new FixedObject("zoneBTasseauVertical1", green, 2930,800,22,165,22); // 3000-70
    FixedObject* zoneBTasseauVertical2 = new FixedObject("zoneBTasseauVertical2", green, 2930,1035,22,165,22);// 3000-70
    FixedObject* zoneBEstrade = new FixedObject("zoneBEstrade", green, 2930,965,70,70,22); // 3000-70

    FixedObject* estrade = new FixedObject("estrade", red, 1200,1900,600,100,22);

    FixedObject* escalierAMarche1 = new FixedObject("escalierAMarche1", yellow, 989,510,500,70,22); //967+22
    FixedObject* escalierAMarche2 = new FixedObject("escalierAMarche2", yellow, 989,440,500,70,44);
    FixedObject* escalierAMarche3 = new FixedObject("escalierAMarche3", yellow, 989,370,500,70,66);
    FixedObject* escalierAMarche4 = new FixedObject("escalierAMarche4", yellow, 989,22,500,348,88);
    FixedObject* escalierBMarche1 = new FixedObject("escalierAMarche1", green, 1511,510,500,70,22); //967+22+500+22
    FixedObject* escalierBMarche2 = new FixedObject("escalierAMarche2", green, 1511,440,500,70,44);
    FixedObject* escalierBMarche3 = new FixedObject("escalierAMarche3", green, 1511,370,500,70,66);
    FixedObject* escalierBMarche4 = new FixedObject("escalierAMarche4", green, 1511,22,500,348,88);
    FixedObject* escalierBordureGauche = new FixedObject("escalierBordureGauche", black, 967,0,22,580,110);
    FixedObject* escalierBordureCenter = new FixedObject("escalierBordureCenter", black, 1489,0,22,580,110); //967+22+500
    FixedObject* escalierBordureDroite = new FixedObject("escalierBordureDroite", black, 2011,0,22,580,110); //1489+22+500
    FixedObject* escalierABordureDerriere = new FixedObject("escalierABordureDerriere", black, 989,0,500,22,110);
    FixedObject* escalierBBordureDerriere = new FixedObject("escalierBBordureDerriere", black, 1511,0,500,22,110);//989+500+22

    FixedObject* claps1 = new FixedObject("claps1", yellow, 250,2000,160,30,108);
    FixedObject* claps2 = new FixedObject("claps2", green, 540,2000,160,30,108);
    FixedObject* claps3 = new FixedObject("claps3", yellow, 870,2000,160,30,108);
    FixedObject* claps4 = new FixedObject("claps4", green, 2000,2000,160,30,108);
    FixedObject* claps5 = new FixedObject("claps5", yellow, 2300,2000,160,30,108);
    FixedObject* claps6 = new FixedObject("claps6", green, 2600,2000,160,30,108);

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
    p_allFixedObjects.push_back(escalierAMarche1);
    p_allFixedObjects.push_back(escalierAMarche2);
    p_allFixedObjects.push_back(escalierAMarche3);
    p_allFixedObjects.push_back(escalierAMarche4);
    p_allFixedObjects.push_back(escalierBMarche1);
    p_allFixedObjects.push_back(escalierBMarche2);
    p_allFixedObjects.push_back(escalierBMarche3);
    p_allFixedObjects.push_back(escalierBMarche4);
    p_allFixedObjects.push_back(escalierBordureGauche);
    p_allFixedObjects.push_back(escalierBordureCenter);
    p_allFixedObjects.push_back(escalierBordureDroite);
    p_allFixedObjects.push_back(escalierABordureDerriere);
    p_allFixedObjects.push_back(escalierBBordureDerriere);
    p_allFixedObjects.push_back(claps1);
    p_allFixedObjects.push_back(claps2);
    p_allFixedObjects.push_back(claps3);
    p_allFixedObjects.push_back(claps4);
    p_allFixedObjects.push_back(claps5);
    p_allFixedObjects.push_back(claps6);
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

#ifndef SCENE_H
#define SCENE_H
#include"claps.h"
#include"distributeurpopcorne.h"
#include "centreterrain.h"
#include "escaliers.h"
#include "zonedepart.h"
#include <QGraphicsScene>

class Scene: public QGraphicsScene
{
public:
    Scene();
    ~Scene();
private:
    Escaliers *myescaliersdroit;
    Escaliers *myescaliersgauche;
    zoneDepart *departMurAgauche;
    zoneDepart *departMurAdroite;
    zoneDepart *departMurAgaucheAdversaire;
    zoneDepart *departMurADroiteAdversaire;
    centreTerrain *centre;
    DistributeurPopCorne *distributeurGauche;
    DistributeurPopCorne *distributeurDroite;
    claps * claps1;
    claps * claps2;
    claps * claps3;
    claps * claps4;
    claps * claps5;
    claps * claps6;
};

#endif // SCENE_H

#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include "ston.h"



//---COMPOSANT DEPLACEMENT---//
class Deplacement: public ServiceActionMoteur
{
private:
    /*PwmOut* pwmgauche;
    DigitalOut* dirgauche0;
    DigitalOut* dirgauche1;
    PwmOut* pwmdroite;
    DigitalOut* dirdroite0;
    DigitalOut* dirdroite1;*/


public:
    Deplacement();
    void avancer();
    void reculer();
    void arreterMoteur();
    void tournerAGauche();
    void tournerADroite();
};



#endif // DEPLACEMENT_H

#include "StrategieGlobale.h"
#include "Deplacement.h"
//#include "Pince.h"
//#include "Capteur.h"
#include <iostream>
using namespace std;



int StrategieGlobale::getCompteur() const
{
    return Compteur;
}

void StrategieGlobale::setCompteur(int value)
{
    Compteur = value;
}
StrategieGlobale::StrategieGlobale()
{
    /*Deplacement* deplacement = new Deplacement();
    Pince* pince = new Pince();
    Capteur* capteur = new Capteur();

    bindServiceActionMoteur(deplacement);
    bindServiceActionBras(pince);
    bindServiceCapteur(capteur);*/
    Compteur = 1;

    cout << "StrategieGlobale created..." << endl;
}

StrategieGlobale::~StrategieGlobale()
{
    cout << "...StrategieGlobale destroyed." << endl;
}

void StrategieGlobale::init()
{

}


void StrategieGlobale::step()
{


    // TOUJOURS AVANCER
    //p_actionMoteur->avancer(1.0); // puissance 1.0 = 100% de la speed_max
    if (getCompteur() < 80) {
        p_actionMoteur->avancer(1.0);
    } else if (getCompteur() < 110) {
        p_actionMoteur->tournerADroite();
    } else if (getCompteur() < 120) {
        p_actionMoteur->reculer(1.0);
    } else if (getCompteur() < 140) {
        p_actionMoteur->tournerAGauche();
    } else {
        if (getCompteur() % 4 == 0 )
        {
            p_actionMoteur->tournerADroite();
        } else {
            p_actionMoteur->avancer(1.0);
        }
    }

    setCompteur(getCompteur() + 1);
    /*
    p_capteur->refreshAllDetectors();
    p_actionMoteur->arreterMoteur();

    // Avancer
    if (p_capteur->getPresenceNE() && p_capteur->getPresenceNO())
    {
      p_actionMoteur->avancer();
      return;
    }

    // Reculer
    if (p_capteur->getPresenceSE() || p_capteur->getPresenceSO())
    {
      p_actionMoteur->reculer();
      return;
    }

    // Tourner à gauche
    if (p_capteur->getPresenceNO())
    {
      p_actionMoteur->tournerAGauche();
      return;
    }

    // Tourner à droite
    if (p_capteur->getPresenceNE())
    {
      p_actionMoteur->tournerADroite();
      return;
    }*/
}


void StrategieGlobale::bindServiceActionMoteur(ServiceActionMoteur* service)
{
    p_actionMoteur = service;
}


void StrategieGlobale::bindServiceActionPince(ServiceActionPince* service)
{
    p_actionPince = service;
}


void StrategieGlobale::bindServiceCapteur(ServiceCapteur* service)
{
    p_capteur = service;
}

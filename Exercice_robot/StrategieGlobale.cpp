#include "StrategieGlobale.h"
#include "Deplacement.h"
//#include "Pince.h"
//#include "Capteur.h"
#include <iostream>
using namespace std;


StrategieGlobale::StrategieGlobale()
{
    /*Deplacement* deplacement = new Deplacement();
    Pince* pince = new Pince();
    Capteur* capteur = new Capteur();

    bindServiceActionMoteur(deplacement);
    bindServiceActionBras(pince);
    bindServiceCapteur(capteur);*/

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
    p_actionMoteur->avancer();


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

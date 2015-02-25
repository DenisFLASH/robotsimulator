#include "StrategieGlobale.h"
#include "Deplacement.h"
#include "Pince.h"
#include "Capteur.h"


StrategieGlobale::StrategieGlobale()
{
    Deplacement* deplacement = new Deplacement();
    Pince* pince = new Pince();
    Capteur* capteur = new Capteur();

    bindServiceActionMoteur(deplacement);
    bindServiceActionBras(pince);
    bindServiceCapteur(capteur);
}


void StrategieGlobale::init()
{
    action_pince = false;
}


void StrategieGlobale::step()
{
    if (action_pince)
    {
        p_actionBras->grapper();
    }

    p_capteur->refreshAllDetectors();

    p_actionMoteur->arreterMoteur();
    p_actionBras->stopGrapper();
    action_pince=false;

    /* Avancer */
    if (p_capteur->getPresenceNE() && p_capteur->getPresenceNO())
    {
      p_actionMoteur->avancer();
      action_pince = true;
      return;
    }

    /* Reculer */
    if (p_capteur->getPresenceSE() || p_capteur->getPresenceSO())
    {
      p_actionMoteur->reculer();
      action_pince = true;
      return;
    }

    /* Tourner à gauche */
    if (p_capteur->getPresenceNO())
    {
      p_actionMoteur->tournerAGauche();
      return;
    }

    /* Tourner à droite */
    if (p_capteur->getPresenceNE())
    {
      p_actionMoteur->tournerADroite();
      return;
    }
}


void StrategieGlobale::bindServiceActionMoteur(ServiceActionMoteur* service)
{
    p_actionMoteur = service;
}


void StrategieGlobale::bindServiceActionBras(ServiceActionBras* service)
{
    p_actionBras = service;
}


void StrategieGlobale::bindServiceCapteur(ServiceCapteur* service)
{
    p_capteur = service;
}

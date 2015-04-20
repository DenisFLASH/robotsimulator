#ifndef STRATEGIEGLOBALE_H
#define STRATEGIEGLOBALE_H

#include "ston.h"


//---COMPOSANT STRATEGIE GLOBALE---//
class StrategieGlobale: public ServiceRequisActionMoteur,
                        public ServiceRequisActionPince,
                        public ServiceRequisCapteur,
                        public ServiceInitialisation,
                        public ServicePasAPas

{
private:
    ServiceActionMoteur* p_actionMoteur;
    ServiceActionPince* p_actionPince;
    ServiceCapteur* p_capteur;
    int Compteur;

public:
    StrategieGlobale();
    virtual ~StrategieGlobale();
    void init();
    void step();
    void bindServiceActionMoteur(ServiceActionMoteur* service);
    void bindServiceActionPince(ServiceActionPince* service);
    void bindServiceCapteur(ServiceCapteur* service);
    int getCompteur() const;
    void setCompteur(int value);
};




#endif // STRATEGIEGLOBALE_H

#ifndef STRATEGIEGLOBALE_H
#define STRATEGIEGLOBALE_H

#include "ston.h"


//---COMPOSANT STRATEGIE GLOBALE---//
class StrategieGlobale: public ServiceRequisActionMoteur,
                        public ServiceRequisActionBras,
                        public ServiceRequisCapteur,
                        public ServiceInitialisation,
                        public ServiceActionPasAPas

{
private:
    ServiceActionMoteur* p_actionMoteur;
    ServiceActionBras* p_actionBras;
    ServiceCapteur* p_capteur;

    bool action_pince;

public:
    StrategieGlobale();
    void init();
    void step();
    void bindServiceActionMoteur(ServiceActionMoteur* service);
    void bindServiceActionBras(ServiceActionBras* service);
    void bindServiceCapteur(ServiceCapteur* service);
};




#endif // STRATEGIEGLOBALE_H

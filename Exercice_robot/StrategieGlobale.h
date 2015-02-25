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

public:
    StrategieGlobale();
    virtual ~StrategieGlobale();
    void init();
    void step();
    void bindServiceActionMoteur(ServiceActionMoteur* service);
    void bindServiceActionPince(ServiceActionPince* service);
    void bindServiceCapteur(ServiceCapteur* service);
};




#endif // STRATEGIEGLOBALE_H

#include "Cerveau.h"
#include "StrategieGlobale.h"


Cerveau::Cerveau()
{
    StrategieGlobale* strategieGlobale = new StrategieGlobale();
    bindServiceInitialisation(strategieGlobale);
    bindServicePasAPas(strategieGlobale);

    p_serviceInit->init();
    while(1) {
        p_servicePasAPas->step();
    }
}

void Cerveau::bindServiceInitialisation(ServiceInitialisation* serviceInitialisation)
{
    p_serviceInit = serviceInitialisation;
}

void Cerveau::bindServicePasAPas(ServicePasAPas* servicePasAPas)
{
    p_servicePasAPas = servicePasAPas;
}

#include "Cerveau.h"
#include "StrategieGlobale.h"


Cerveau::Cerveau()
{
    StrategieGlobale* strategieGlobale = new StrategieGlobale();
    bindServiceInitialisation(strategieGlobale);
    bindServiceActionPasAPas(strategieGlobale);

    p_serviceInit->init();
    while(1) {
        p_serviceActionPasAPas->step();
    }
}

void Cerveau::bindServiceInitialisation(ServiceInitialisation* serviceInitialisation)
{
    p_serviceInit = serviceInitialisation;
}

void Cerveau::bindServiceActionPasAPas(ServiceActionPasAPas* servicePasAPas)
{
    p_serviceActionPasAPas = servicePasAPas;
}

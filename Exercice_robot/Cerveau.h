#ifndef CERVEAU_H
#define CERVEAU_H

#include "ston.h"

class Cerveau: public ServiceRequisInitialisation,
               public ServiceRequisPasAPas
{
private:
    ServiceInitialisation* p_serviceInit;
    ServicePasAPas* p_servicePasAPas;
public:
    Cerveau();
    void bindServiceInitialisation(ServiceInitialisation* serviceInitialisation);
    void bindServicePasAPas(ServicePasAPas* servicePasAPas);
};


#endif // CERVEAU_H

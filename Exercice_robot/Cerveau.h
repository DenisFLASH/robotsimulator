#ifndef CERVEAU_H
#define CERVEAU_H

#include "ston.h"

class Cerveau: public ServiceRequisInitialisation,
               public ServiceRequisActionPasAPas
{
private:
    ServiceInitialisation* p_serviceInit;
    ServiceActionPasAPas* p_serviceActionPasAPas;
public:
    Cerveau();
    void bindServiceInitialisation(ServiceInitialisation* serviceInitialisation);
    void bindServiceActionPasAPas(ServiceActionPasAPas* servicePasAPas);
};


#endif // CERVEAU_H

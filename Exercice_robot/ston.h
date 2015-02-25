#ifndef STON_H
#define STON_H

#include "mbed.h" 

//---SERVICES---//
class ServiceCapteur
{
public:
    virtual void refreshAllDetectors()=0;
    virtual bool getPresenceNE()=0;
    virtual bool getPresenceNO()=0;
    virtual bool getPresenceSE()=0;
    virtual bool getPresenceSO()=0;
};
class ServiceRequisCapteur
{
public:
    virtual void bindServiceCapteur(ServiceCapteur* service)=0;
};


class ServiceActionMoteur
{
public:
    virtual void avancer()=0;
    virtual void reculer()=0;
    virtual void arreterMoteur()=0;
    virtual void tournerAGauche()=0;
    virtual void tournerADroite()=0;
};
class ServiceRequisActionMoteur
{
public:
    virtual void bindServiceActionMoteur(ServiceActionMoteur* service)=0;
};


class ServiceActionBras
{
public:
    virtual void grapper()=0;
    virtual void stopGrapper()=0;
};
class ServiceRequisActionBras
{
public:
    virtual void bindServiceActionBras(ServiceActionBras* service)=0;
};


class ServiceInitialisation
{
public:
    virtual void init()=0;
};
class ServiceRequisInitialisation
{
public:
    virtual void bindServiceInitialisation(ServiceInitialisation* service)=0;
};

class ServiceActionPasAPas
{
public:
    virtual void step()=0;
};
class ServiceRequisActionPasAPas
{
public:
    virtual void bindServiceActionPasAPas(ServiceActionPasAPas* service)=0;
};



#endif // STON_H

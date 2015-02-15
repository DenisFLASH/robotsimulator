#ifndef STON_H
#define STON_H

#define PWMGAUCHE D10
#define DIRGAUCHE D9
#define PWMDROITE D8
#define DIRDROITE D7

#define SUCCESS 1
#define FAILED 0

//---SERVICES---//
class ServiceActionMoteur
{
public:
    virtual void forward(int puissance)=0;
    virtual void stop()=0;
};
class ServiceRequisActionMoteur
{
public:
    virtual void bindServiceActionMoteur(ServiceActionMoteur* service)=0;
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



//---COMPOSANTS---//
class Hardware: public ServiceActionMoteur
{
public:
    Hardware();
    void forward(int puissance);
    void stop();
};

class Simulateur: public ServiceActionMoteur,
                         ServiceRequisInitialisation,
                         ServiceRequisActionPasAPas
{
private:
    ServiceInitialisation* serviceInit;
    ServiceActionPasAPas* serviceStep;
public:
    Simulateur();
    void forward(int puissance);
    void stop();
    void bindServiceInitialisation(ServiceInitialisation* serviceInitialisation);
    void bindServiceActionPasAPas(ServiceActionPasAPas* servicePasAPas);
};

class StrategieGlobale: public ServiceRequisActionMoteur,
                        public ServiceInitialisation,
                        public ServiceActionPasAPas
{
private:
    ServiceActionMoteur* actionMoteur;
public:
    StrategieGlobale();
    void init();
    void step();
    void bindServiceActionMoteur(ServiceActionMoteur* service);
};


#endif // STON_H

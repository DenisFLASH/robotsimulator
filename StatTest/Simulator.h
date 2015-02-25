#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>

//---SERVICES---//
class ServiceReadGameState
{
public:
    virtual vector<FixedGameObject> getFixedGameObjects()=0;
    virtual vector<MobileGameObject> getMobileGameObjects()=0;
};

class ServiceRequisReadGameState
{
public:
    virtual void bindServiceReadGameState(ServiceReadGameState* service)=0;
};

class ServiceUpdateGameState
{
public:
    virtual void createWorld()=0;
    virtual void updateWorld()=0;
};

class ServiceRequisUpdateGameState
{
public:
    virtual void bindServiceUpdateGameState(ServiceUpdateGameState* service)=0;
};


//---COMPOSANTS---//
class PlayingArea: public ServiceReadGameState
{
public:
    PlayingArea();
    //vector<FixedGameObject> getFixedGameObjects();
    //vector<MobileGameObject> getMobileGameObjects();
};

class SimulatorEngine: public ServiceRequisReadGameState,
                       public ServiceRequisUpdateGameState
{
private:
    ServiceReadGameState* readGameState;
    ServiceUpdateGameState* updateGameState;
public:
    SimulatorEngine();
    void startSimulator();
    void bindServiceReadGameState(ServiceReadGameState* service);
    void bindServiceUpdateGameState(ServiceUpdateGameState* service);
};

/* TO DO with Liban
 *
class SupportGUI:  public ServiceRequisReadGameState
{
private:
    ServiceReadGameState* readGameState;
public:
    SupportGUI();
    void startSimulator();
    void bindServiceReadGameState(ServiceReadGameState* service);
    void bindServiceUpdateGameState(ServiceUpdateGameState* service);
};
*/

#endif // SIMULATOR_H

#ifndef PINCE_H
#define PINCE_H

//#include "mbed.h"
#include "ston.h"



//---COMPOSANT PINCE---//
class Pince: public ServiceActionPince
{
private:
    /*PwmOut* pwmpince;
    DigitalOut* dirpince;*/

    int pince;

public:
    Pince();
    void grapper();
    void stopGrapper();
};



#endif // PINCE_H

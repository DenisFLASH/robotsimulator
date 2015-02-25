#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "ston.h"


//---COMPOSANT CAPTEUR---//
class Capteur: public ServiceCapteur
{

public:
    Capteur();
    void refreshAllDetectors();

    bool getPresenceNE();
    bool getPresenceNO();
    bool getPresenceSE();
    bool getPresenceSO();


private:
    uint16_t meas_NE, meas_NO, meas_SO, meas_SE;
    DigitalOut* ir_NE;
    DigitalOut* ir_NO;
    DigitalOut* ir_SO;
    DigitalOut* ir_SE;
    AnalogIn* irval_NE;
    AnalogIn* irval_NO;
    AnalogIn* irval_SO;
    AnalogIn* irval_SE;

private:
    void startSendingIR();
    void stopSendingIR();

    uint16_t getMeas_NE() const;
    uint16_t getMeas_NO() const;
    uint16_t getMeas_SE() const;
    uint16_t getMeas_SO() const;

    void setMeas_NE(const uint16_t &value);
    void setMeas_NO(const uint16_t &value);
    void setMeas_SE(const uint16_t &value);
    void setMeas_SO(const uint16_t &value);

    uint16_t readIrval_NE();
    uint16_t readIrval_NO();
    uint16_t readIrval_SE();
    uint16_t readIrval_SO();
};


#endif // CAPTEUR_H

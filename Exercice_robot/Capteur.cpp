#include "Capteur.h"
#include "mbed.h" 



#define VALMAGIC 13750

// Calculate the corresponding acquisition measure for a given value in mV
#define MV(x) ((0xFFF*x)/3300)



//  PUBLIC METHODS

Capteur::Capteur()
{
    ir_NE = new DigitalOut(PA_13);
    ir_NO = new DigitalOut(PA_14);
    ir_SO = new DigitalOut(PA_15);
    ir_SE = new DigitalOut(PB_7);
    irval_NE = new AnalogIn(PC_4);
    irval_NO = new AnalogIn(PB_1);
    irval_SO = new AnalogIn(D11);
    irval_SE = new AnalogIn(PC_5);
}

/* Refreshes the values of measurements of ALL 4 DETECTORS. Called every step. */
void Capteur::refreshAllDetectors()
{
    startSendingIR();
    wait(0.05);
    setMeas_NE(readIrval_NE());
    setMeas_NO(readIrval_NO());
    setMeas_SE(readIrval_SE());
    setMeas_SO(readIrval_SO());

    stopSendingIR();
    wait(0.05);
    setMeas_NE(getMeas_NE() - readIrval_NE());
    setMeas_NO(getMeas_NO() - readIrval_NO());
    setMeas_SE(getMeas_SE() - readIrval_SE());
    setMeas_SO(getMeas_SO() - readIrval_SO());
}

/* Returns true if an object is present ahead of a detector.*/

bool Capteur::getPresenceNE()
{
    return meas_NE > VALMAGIC;
}
bool Capteur::getPresenceNO()
{
    return meas_NO > VALMAGIC;
}
bool Capteur::getPresenceSE()
{
    return meas_SE > VALMAGIC;
}
bool Capteur::getPresenceSO()
{
    return meas_SO > VALMAGIC;
}



//  PRIVATE METHODS

/* Getters and setters */

uint16_t Capteur::getMeas_NE() const
{
    return meas_NE;
}
uint16_t Capteur::getMeas_NO() const
{
    return meas_NO;
}
uint16_t Capteur::getMeas_SE() const
{
    return meas_SE;
}
uint16_t Capteur::getMeas_SO() const
{
    return meas_SO;
}


void Capteur::setMeas_NE(const uint16_t &value)
{
    meas_NE = value;
}
void Capteur::setMeas_NO(const uint16_t &value)
{
    meas_NO = value;
}
void Capteur::setMeas_SE(const uint16_t &value)
{
    meas_SE = value;
}
void Capteur::setMeas_SO(const uint16_t &value)
{
    meas_SO = value;
}


/* Read infrared detector values.*/
uint16_t Capteur::readIrval_NE()
{
    return irval_NE->read_u16();
}
uint16_t Capteur::readIrval_NO()
{
    return irval_NO->read_u16();
}
uint16_t Capteur::readIrval_SE()
{
    return irval_SE->read_u16();
}
uint16_t Capteur::readIrval_SO()
{
    return irval_SO->read_u16();
}


/* Start sending infrared signals from all four emittors. */
void Capteur::startSendingIR()
{
    *ir_NE = 1;
    *ir_NO = 1;
    *ir_SO = 1;
    *ir_SE = 1;
}

/* Stop sending infrared signals from all four emittors. */
void Capteur::stopSendingIR()
{
    *ir_NE = 0;
    *ir_NO = 0;
    *ir_SO = 0;
    *ir_SE = 0;
}

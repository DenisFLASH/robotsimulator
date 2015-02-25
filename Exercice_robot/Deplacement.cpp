#include "Deplacement.h"


Deplacement::Deplacement()
{
    pwmgauche = new PwmOut(D9);
    dirgauche0 = new DigitalOut(D2);
    dirgauche1 = new DigitalOut(D4);
    pwmdroite = new PwmOut(D10);
    dirdroite0 = new DigitalOut(D7);
    dirdroite1 = new DigitalOut(D8);

    pwmgauche->period_us(1000);
    pwmdroite->period_us(1000);
}

void Deplacement::avancer()
{
    *dirgauche0 = 1;
    *dirgauche1 = 0;
    *dirdroite0 = 0;
    *dirdroite1 = 1;
    pwmgauche->pulsewidth_us(250);
    pwmdroite->pulsewidth_us(250);
}

void Deplacement::reculer()
{
    *dirgauche0 = 0;
    *dirgauche1 = 1;
    *dirdroite0 = 1;
    *dirdroite1 = 0;
    pwmgauche->pulsewidth_us(250);
    pwmdroite->pulsewidth_us(250);
}

void Deplacement::arreterMoteur()
{
    pwmgauche->pulsewidth_us(0);
    pwmdroite->pulsewidth_us(0);
    *dirgauche0 = 1;
    *dirgauche1 = 0;
    *dirdroite0 = 0;
    *dirdroite1 = 1;
}

void Deplacement::tournerAGauche()
{    
    *dirgauche0 = 1;
    *dirgauche1 = 0;
    *dirdroite0 = 1;
    *dirdroite1 = 0;
    pwmgauche->pulsewidth_us(500);
    pwmdroite->pulsewidth_us(500);
}

void Deplacement::tournerADroite()
{
    *dirgauche0 = 0;
    *dirgauche1 = 1;
    *dirdroite0 = 0;
    *dirdroite1 = 1;
    pwmgauche->pulsewidth_us(500);
    pwmdroite->pulsewidth_us(500);
}

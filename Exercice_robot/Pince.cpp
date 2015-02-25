#include "Pince.h"


Pince::Pince()
{
    pwmpince = new PwmOut(D3);
    dirpince = new DigitalOut(D5);

    pwmpince->period_us(1000);
    *dirpince = 1;
    pince = 0;
}

void Pince::grapper()
{
    pwmpince->pulsewidth_us(300);
    pince++;
    if (pince == 8) {
      *dirpince = !(*dirpince);
      pince = 0;
    }
}


void Pince::stopGrapper()
{
    pwmpince->pulsewidth_us(0);
}

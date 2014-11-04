#include "mbed.h"
#include "rtos.h"

DigitalOut myled(PA_0);

void OnTimeout(void const *arg)
{
    volatile int x;

    x = 0;
}

int main() {
    RtosTimer MyTimer(OnTimeout, osTimerPeriodic, NULL);

    MyTimer.start(3000);

    while(1) {
        myled = 1;
        osDelay(500);
        myled = 0;
        osDelay(500);
    }
}

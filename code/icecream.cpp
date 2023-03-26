#include "mbed.h"
#define BLINKING_RATE   100ms

int main()
{
    DigitalOut led1(LED1);

    while (true) {
        led1 = !led1;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}


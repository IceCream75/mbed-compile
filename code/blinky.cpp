#include "mbed.h"
#define BLINKING_RATE   100ms

int main()
{
    DigitalOut led1(LED1);
    DigitalOut led2(LED2);
    DigitalOut led3(LED3);

    while (true) {
        led1 = !led1;
        ThisThread::sleep_for(BLINKING_RATE);
        led2 = !led2;
        ThisThread::sleep_for(BLINKING_RATE);
        led3 = !led3;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}

#include "mbed.h"

InterruptIn button(SW2);
DigitalOut led(LED1);

void ISR1(void)
{
    led = !led;
}

int main(void)
{
    button.rise(&ISR1);
    while(1) {
    }
}
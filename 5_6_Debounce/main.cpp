#include "mbed.h"

Timer debounce;
InterruptIn button(SW2);
DigitalOut redLED(LED1);

void toggle(void)
{
    if (debounce.read_ms() > 1000) {
        redLED = !redLED;
        debounce.reset();
    }
}

int main(void)
{
    debounce.start();
    button.rise(&toggle);
    while (1);
}
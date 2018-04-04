#include "mbed.h"

DigitalOut green_led(LED1);
DigitalOut red_led(LED2);

int main() {
    while (1) {

        // LEDs ON
        green_led = 1;
        red_led = 1;

        wait(0.2); // wait 200 ms

        // LEDs OFF
        green_led = 0;
        red_led = 0;

        wait(0.8); // wait 800 ms
    }
}

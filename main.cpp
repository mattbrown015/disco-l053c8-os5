#include <mbed.h>
#include <mbed_mem_trace.h>
#include <mbed_stats.h>

namespace
{

DigitalOut green_led(LED1);
DigitalOut red_led(LED2);

}

int main() {
    mbed_mem_trace_set_callback(mbed_mem_trace_default_callback);

    puts("disco-l053c8-os5");

    mbed_stats_heap_t heap_stats;
    mbed_stats_heap_get(&heap_stats);
    printf("Current heap: %lu\r\n", heap_stats.current_size);
    printf("Max heap size: %lu\r\n", heap_stats.max_size);

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

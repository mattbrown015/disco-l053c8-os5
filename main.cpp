#include <mbed.h>
#include <mbed_mem_trace.h>
#include <mbed_stats.h>

namespace
{

DigitalOut green_led(LED1);
DigitalOut red_led(LED2);

EventQueue eventQueue;

void toggleLeds() {
    green_led = !green_led;
    red_led = !red_led;
}

void checkHeap() {
    mbed_stats_heap_t heap_stats;
    mbed_stats_heap_get(&heap_stats);
    printf("heap: current %lu max %lu\n", heap_stats.current_size, heap_stats.max_size);
}

}

int main() {
    mbed_mem_trace_set_callback(mbed_mem_trace_default_callback);

    puts("disco-l053c8-os5");

    puts("before creating events");
    checkHeap();

    eventQueue.call_every(1000, toggleLeds);
    eventQueue.call_every(10000, checkHeap);

    puts("dispatch_forever");
    eventQueue.dispatch_forever();
}

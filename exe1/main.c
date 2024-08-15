#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN = 5;
const int LED_PIN_Y = 28;

int main() {
    stdio_init_all();
    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(LED_PIN_Y);
    gpio_set_dir(LED_PIN_Y, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, 1);
        gpio_put(LED_PIN_Y, 1);
        sleep_ms(250);
        
        gpio_put(LED_PIN, 0);
        gpio_put(LED_PIN_Y, 0);     
        sleep_ms(250);
    }
}
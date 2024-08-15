#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN_R = 28; 
const int BTN_PIN_G = 26; 

const int LED_PIN_R = 4; 
const int LED_PIN_G = 6; 

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  int r = 0;
  int g = 0;
  while (true) {

    gpio_put(LED_PIN_G, g);
    gpio_put(LED_PIN_R, r);

    if (!gpio_get(BTN_PIN_G)) {
      while (!gpio_get(BTN_PIN_G)){}
      g = !g;
    }

    if (!gpio_get(BTN_PIN_R)) {
      while (!gpio_get(BTN_PIN_R)){}
      r = !r;
    }
  }
}

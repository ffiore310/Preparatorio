#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_RED = 28;
const int BTN_GREEN = 26;
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
int push_pull_r = 0;
int push_pull_g = 0;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_R); //inicia led vermelho
  gpio_set_dir(LED_PIN_R, GPIO_OUT); //define led vermelho como saida

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  gpio_init(BTN_RED);
  gpio_init(BTN_GREEN);
  gpio_set_dir(BTN_RED, GPIO_IN);
  gpio_set_dir(BTN_GREEN, GPIO_IN);
  gpio_pull_up(BTN_RED);
  gpio_pull_up(BTN_GREEN);

  while (true) {
    if (!gpio_get(BTN_RED)) {
      if (push_pull_r == 0){
        gpio_put(LED_PIN_R, 1); // controla led vermelho
        push_pull_r = 1;
      } else {
        gpio_put(LED_PIN_R, 0);
        push_pull_r = 0;
      }
      while (!gpio_get(BTN_RED)) {
      };
    }
    if (!gpio_get(BTN_GREEN)) {
      if (push_pull_g == 0){
        gpio_put(LED_PIN_G, 1); // controla led verde
        push_pull_g = 1;
      } else {
        gpio_put(LED_PIN_G, 0);
        push_pull_g = 0;
      }
      while (!gpio_get(BTN_GREEN)) {
      };
    }
  }
}

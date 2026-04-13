 #include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

/**
 * @brief Programa principal
*/
int main(void) {
  // Inicializo el USB
  stdio_init_all();
  cyw43_arch_init();

  // Mensaje por USB
  printf("\nHola mundo!\n");

  int x=0;
  int y=0;

  while (true) {
    // Prendo LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    // Mensaje por USB
    printf("LED prendido\n");
    x=x+1;
    printf("encendidos %d\n",x);
    // Demora
    sleep_ms(5000);
    // Apago LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    // Mensaje por USB
    printf("LED apagado\n");
    y=y+1;
    printf("apagados %d\n",y);
    // Demora
    sleep_ms(500);
  }
  return 0;
}
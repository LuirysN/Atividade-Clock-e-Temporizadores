//ATIVIDADE 1: Temporizador periódico 
//ALUNO: LUIRYS DO NASCIMENTO SILVA


#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#define RED_LED 13
#define YELLOW_LED 12
#define GREEN_LED 11

// Definindo o estado atual do semáforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} traffic_light_state;

volatile traffic_light_state current_state = RED;

// Função de callback para alterar o estado dos LEDs
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (current_state) {
        case RED:
            gpio_put(RED_LED, 1);
            gpio_put(YELLOW_LED, 0);
            gpio_put(GREEN_LED, 0);
            current_state = YELLOW;
            printf("Sinal Vermelho ativo\n");
            break;

        case YELLOW:
            gpio_put(RED_LED, 0);
            gpio_put(YELLOW_LED, 1);
            gpio_put(GREEN_LED, 0);
            current_state = GREEN;
            printf("Sinal Amarelo ativo\n");
            break;

        case GREEN:
            gpio_put(RED_LED, 0);
            gpio_put(YELLOW_LED, 0);
            gpio_put(GREEN_LED, 1);
            current_state = RED;
            printf("Sinal Verde ativo\n");
            break;
    }
    return true; // Mantém o temporizador ativo
}

void init() {
    stdio_init_all();
    gpio_init(RED_LED);
    gpio_init(YELLOW_LED);
    gpio_init(GREEN_LED);

    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
}

int main() {
    init();

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (1) {
        printf("Semáforo em operação...\n");
        sleep_ms(1000);
    }
}

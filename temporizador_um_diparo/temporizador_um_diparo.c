//ATIVIDADE 2: Temporizador de um disparo 
//ALUNO: LUIRYS DO NASCIMENTO SILVA


#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

#define BLUE_LED 13
#define GREEN_LED 11
#define RED_LED 12
#define BUTTON 5
#define DEBOUNCE_DELAY 50  // 50 ms para debounce

volatile bool timer_active = false;

// Função para desligar o último LED e liberar o botão
int64_t turn_off_last_led_callback(alarm_id_t id, void *user_data) {
    gpio_put(GREEN_LED, 0);
    printf("LED Verde desligado.\n");
    timer_active = false;
    return 0;
}

// Função para desligar o segundo LED e programar o próximo callback
int64_t turn_off_second_led_callback(alarm_id_t id, void *user_data) {
    gpio_put(RED_LED, 0);
    printf("LED Vermelho desligado.\n");
    add_alarm_in_ms(3000, turn_off_last_led_callback, NULL, false);
    return 0;
}

// Função para desligar o primeiro LED e programar o próximo callback
int64_t turn_off_first_led_callback(alarm_id_t id, void *user_data) {
    gpio_put(BLUE_LED, 0);
    printf("LED Azul desligado.\n");
    add_alarm_in_ms(3000, turn_off_second_led_callback, NULL, false);
    return 0;
}

// Callback do botão com debounce
void button_callback(uint gpio, uint32_t events) {
    static absolute_time_t last_interrupt_time = {0};
    absolute_time_t current_time = get_absolute_time();

    if (absolute_time_diff_us(last_interrupt_time, current_time) < DEBOUNCE_DELAY * 1000) {
        return; // Ignora se o intervalo for menor que o tempo de debounce
    }

    last_interrupt_time = current_time;

    if (gpio == BUTTON && !timer_active) {
        timer_active = true;

        gpio_put(BLUE_LED, 1);
        gpio_put(GREEN_LED, 1);
        gpio_put(RED_LED, 1);
        printf("Todos os LEDs acesos.\n");

        add_alarm_in_ms(3000, turn_off_first_led_callback, NULL, false);
    }
}

// Função para configurar LEDs
void config_led(uint gpio_pin) {
    gpio_init(gpio_pin);
    gpio_set_dir(gpio_pin, GPIO_OUT);
    gpio_put(gpio_pin, 0);  // Garante que o LED inicia desligado
}

void init() {
    stdio_init_all();
    config_led(BLUE_LED);
    config_led(RED_LED);
    config_led(GREEN_LED);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, button_callback);
}

int main() {
    init();
    while (1) {
        sleep_ms(1000);
    }
}

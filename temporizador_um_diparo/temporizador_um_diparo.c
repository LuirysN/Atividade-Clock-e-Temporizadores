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

volatile bool timer_active = false;

// Função para desligar o último LED e liberar o botão
int64_t turn_off_last_led_callback(alarm_id_t id, void *user_data) 
{
    gpio_put(GREEN_LED, 0);
    timer_active = false; 
    return 0;
}

// Função para desligar o segundo LED e programar o próximo callback
int64_t turn_off_second_led_callback(alarm_id_t id, void *user_data) 
{
    gpio_put(RED_LED, 0);
    add_alarm_in_ms(3000, turn_off_last_led_callback, NULL, false);
    return 0;
}

// Função para desligar o primeiro LED e programar o próximo callback
int64_t turn_off_first_led_callback(alarm_id_t id, void *user_data) 
{
    gpio_put(BLUE_LED, 0);
    add_alarm_in_ms(3000, turn_off_second_led_callback, NULL, false);
    return 0;
}

// Callback do botão
void button_callback(uint gpio, uint32_t events) 
{
    if (gpio == BUTTON && !timer_active) 
    { 
        timer_active = true;

        gpio_put(BLUE_LED, 1);
        gpio_put(GREEN_LED, 1);
        gpio_put(RED_LED, 1);
        printf("Iniciando com todos os LEDs acesos.\n");

        add_alarm_in_ms(3000, turn_off_first_led_callback, NULL, false);
    }
}

void init() 
{
    stdio_init_all();
    gpio_init(BLUE_LED);
    gpio_init(RED_LED);
    gpio_init(GREEN_LED);
    gpio_init(BUTTON);

    gpio_set_dir(BLUE_LED, GPIO_OUT);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    // Configura interrupção para o botão corretamente
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, button_callback);
}

int main() 
{
    init();
    while (1) 
    {
        sleep_ms(1000);
    }
}

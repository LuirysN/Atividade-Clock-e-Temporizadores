# Semáforo Periódico com Raspberry Pi Pico W

## Descrição

Este projeto implementa um semáforo periódico utilizando o microcontrolador Raspberry Pi Pico W e a função add_repeating_timer_ms() do Pico SDK. O semáforo alterna entre os LEDs vermelho, amarelo e verde com um intervalo de 3 segundos entre cada mudança de estado.

## Componentes Utilizados

    - Microcontrolador: Raspberry Pi Pico W

    - LEDs: 1 Vermelho, 1 Amarelo e 1 Verde

    - Resistores: 3 resistores de 330 Ω

## Funcionamento

    - O semáforo inicia com o LED vermelho aceso.

    - Após 3 segundos, muda para o LED amarelo.

    - Depois de mais 3 segundos, muda para o LED verde.

    - O ciclo se repete indefinidamente.

## Requisitos

    - O temporizador é configurado com um atraso de 3.000 ms.

    - O controle dos LEDs é realizado por meio de funções de callback do temporizador.

    - A cada segundo, uma mensagem é impressa na porta serial indicando que o semáforo está em operação.

## Pinagem

    - LED Vermelho: GPIO 13

    - LED Amarelo: GPIO 12

    - LED Verde: GPIO 11

## Autor: Luirys do Nascimento Silva
# Temporizador de Um Disparo (One Shot) com Raspberry Pi Pico W

## Descrição

Este projeto implementa um sistema de temporização utilizando a função add_alarm_in_ms() do Pico SDK. O sistema aciona três LEDs (azul, vermelho e verde) a partir do clique em um botão (pushbutton). O código é projetado para ser simulado no Wokwi e testado com a Ferramenta Educacional BitDogLab.

## Componentes Utilizados

    - Microcontrolador: Raspberry Pi Pico W

    - LEDs: Azul (GPIO 13), Vermelho (GPIO 12), Verde (GPIO 11)

    - Resistores: 3x de 330 Ω

    - Pushbutton: GPIO 5

## Funcionalidades

    - Acionamento dos LEDs: Ao pressionar o botão, todos os LEDs são ligados simultaneamente.

    - Sequência de Desligamento:

        - Após 3 segundos, o LED azul é desligado.

        - Após mais 3 segundos, o LED vermelho é desligado.

        - Por fim, após mais 3 segundos, o LED verde é desligado.

    - Controle de Estado: O botão só pode acionar novamente o sistema após o LED verde estar desligado.

    - Debounce: Implementação de debounce por software para evitar leituras falsas do botão.

## Autor: Luirys do Nascimento Silva.
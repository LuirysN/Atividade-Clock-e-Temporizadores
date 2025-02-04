# Atividade-Clock-e-Temporizadores

Este repositório contém atividades de simulação utilizando o microcontrolador Raspberry Pi Pico W no ambiente Wokwi. O objetivo é explorar o uso de temporizadores periódicos e de um disparo (One Shot) com a ferramenta Pico SDK, focando no controle de LEDs e na interação com botões.

## Atividades

  1. Temporizador de Um Disparo (One Shot)

  Nesta atividade, um sistema de temporização é projetado para acionar três LEDs (azul, vermelho e verde) a partir do clique em um pushbutton. O comportamento é o seguinte:
  
  Acionamento dos LEDs: Ao pressionar o botão, todos os LEDs são acesos simultaneamente.
  
  Sequência de Desligamento: A cada 3 segundos, um LED é desligado em sequência até que todos estejam apagados.
  
  Controle do Botão: O botão só é responsivo após o ciclo completo de desligamento.
  
  BitDogLab: Inclui um experimento utilizando um LED RGB e o Botão A.

2. Temporizador Periódico (Semáforo)

Nesta atividade, é implementado um semáforo com LEDs (vermelho, amarelo e verde), simulando um ciclo de trânsito:

Ciclo do Semáforo: O LED vermelho acende primeiro, seguido pelo amarelo e depois o verde, com um intervalo de 3 segundos entre cada transição.

Mensagens Seriais: O código imprime mensagens na porta serial a cada segundo, informando o status do sistema.

BitDogLab: Inclui um experimento com o LED RGB para representar o ciclo do semáforo.

Tecnologias Utilizadas

Microcontrolador: Raspberry Pi Pico W

Simulador: Wokwi

SDK: Pico SDK (para manipulação dos temporizadores)

BitDogLab: Para experimentos adicionais com o LED RGB

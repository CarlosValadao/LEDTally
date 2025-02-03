# LEDTally ✨ -> [Assita ao vídeo de apresentação](https://youtu.be/8yrpM5dyOrQ)


**LEDTally** é um contador implementado para a **Raspberry Pi Pico** ou **Pico W**, utilizando a placa **BitDogLab**. O programa exibe números de 0 a 9 em uma matriz 5x5 de LEDs (WS2812), com controles de incremento e decremento feitos por dois botões (A e B), e com variação da intensidade e das cores dos LEDs.

## 🚀 Requisitos

O código foi desenvolvido e testado na **Plataforma BitDogLab** versão 6.3, com os seguintes requisitos:

![bitdoglab_v6 3](https://github.com/user-attachments/assets/318f12c5-0f62-4fe4-b99b-2ba74aee626e)

- **Raspberry Pi Pico** ou **Pico W** 🛒
- **BitDogLab** versão 6.3 🔧
- Linguagem: **C** (Versão 11) 💻
- Pico SDK (Versão 2.1.0) 🛠️
- Utiliza **pico-sdk**, **extensões do CMake** e **VS Code** para desenvolvimento 🛠️
- Compilador: **GNU ARM Embedded Toolchain** (`gcc-arm-eabi`) ⚙️

## 🧑‍💻 Funcionalidades

1. O **LED RGB** da placa pisca continuamente **5 vezes por segundo** com a cor **vermelha** 🔴.
2. O **botão A** (GPIO 5) **incrementa** o número exibido na matriz de LEDs a cada pressionamento ⬆️.
3. O **botão B** (GPIO 6) **decrementa** o número exibido na matriz de LEDs a cada pressionamento ⬇️.
4. O número exibido na **matriz de LEDs WS2812** varia de 0 a 9 e é representado por **ícones numéricos** ou **estilo digital**.
5. A **intensidade dos LEDs** é incrementada ou decrementada em **10%** a cada incremento ou decremento do número (totalizando 100% ao alcançar o número 9) 🔆.
6. A **cor dos números** exibidos na matriz de LEDs alterna entre **vermelho, verde, azul, azul marinho, lilás, branco e amarelo** 🌈.
7. Ao **decrementar** a partir do número 9, o valor exibido **"volta" para o 9**, e ao **incrementar** a partir do número 9, o número **"volta" para 0** 🔄.
8. **Interrupção de GPIO** para tratar o efeito **bounce** nos botões, com **delay de 200ms** após cada pressionamento ⏱️.

## 🧩 Componentes

- **Matriz 5x5 de LEDs WS2812** conectada à **GPIO 7** 💡.
- **LED RGB** com pinos conectados à **GPIOs 11, 12 e 13** 🌈.
- **Botão A** conectado à **GPIO 5** 🔘.
- **Botão B** conectado à **GPIO 6** 🔘.

## ⚙️ Como Funciona

1. **LED RGB**: O LED pisca constantemente em vermelho, e sua intensidade e cor variam com a interação dos botões.
2. **Matriz de LEDs**: Cada número de 0 a 9 é exibido na matriz de 5x5 LEDs, com diferentes cores e intensidades de brilho. A intensidade aumenta/decrease conforme o número é incrementado ou decrementado.
3. **Botões A e B**: Cada vez que o botão A é pressionado, o número na matriz é incrementado, e com o botão B, o número é decrementado. O valor do número é representado de forma visível na matriz de LEDs.

[Demonstração do programa em pleno funcionamento](https://github.com/user-attachments/assets/78de6d97-c7d9-4d1d-8f14-d0112b2f61aa)

## 📥 Como Usar

1. **Conectar a Raspberry Pi Pico** à plataforma BitDogLab.
2. **Compilar o código** utilizando o **VS Code** e a **extensão Raspberry Pi Pico** com a ferramenta **CMake**.
3. **Carregar o código** na Raspberry Pi Pico e observar a execução no display LED.
4. **Pressionar os botões** para aumentar ou diminuir o número exibido.

## 🛠️ Instalação

1. Clone o repositório em sua máquina local:

    ```bash
    git clone https://github.com/CarlosValadao/LEDTally.git
    ```

2. Navegue até o diretório do projeto:

    ```bash
    cd LEDTally
    ```

3. Abra o projeto no **VS Code** com a **extensão Raspberry Pi Pico** instalada.
4. Compile e faça o **upload** do código na Raspberry Pi Pico.

## 📜 Licença

Este projeto está licenciado sob a **MIT License**.

## 💬 Contribuição

Sinta-se à vontade para abrir *issues* e *pull requests* para melhorias ou correções.

---

**Carlos Valadao**  
Data: 31/01/2025

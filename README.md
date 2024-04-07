# pico-template

Este es un proyecto de plantilla básica para empezar a trabajar con [pico](https://github.com/raspberrypi/pico), la plataforma de desarrollo para microcontroladores Raspberry Pi Pico.

## Requisitos previos

Asegúrate de tener instalado [Git](https://git-scm.com/) y [CMake](https://cmake.org/) en tu sistema antes de comenzar.

## Instrucciones de uso

1. Clona este repositorio:

    ```bash
    git clone https://github.com/tu_usuario/pico-template.git
    ```

2. Inicializa los submódulos de Git:

    ```bash
    git submodule init
    ```

3. Configura el proyecto con CMake:

    ```bash
    cmake . -B build/
    ```

4. Navega al directorio de construcción:

    ```bash
    cd build
    ```

5. Compila el proyecto:

    ```bash
    make
    ```


# AVR Atmega32 Drivers
![393889da92596683ee914103420ae1d3](https://github.com/the7ag/AVR_DRIVERS/assets/95578914/0f3678e6-0033-48d5-95e1-7e62e2865516)


## Overview

The AVR Atmega32 Drivers and HAL Library is a comprehensive collection of device drivers and hardware abstraction layer (HAL) modules for the Atmel AVR Atmega32 microcontroller. This repository provides efficient and easy-to-use drivers to interact with various peripherals such as ADC, DIO, external interrupts, global interrupts, SPI, Timer0, Timer1, TWI (I2C), UART, and Watchdog Timer.

The HAL layer includes support for a wide range of devices and sensors, making it easy to interface with components like Buzzer, DC motor, EEPROM, IR sensor, Keypad, LCD, LED, Pushbutton, Servo motor, and Seven Segments display.

Furthermore, this library also includes OS support with an implementation of the FreeRTOS real-time operating system.

## Features

### MCAL Layer:

- **ADC Driver:** Enables reading analog signals from sensors using the Analog-to-Digital Converter.
- **DIO Driver:** Facilitates control and configuration of General Purpose Input/Output pins.
- **External Interrupts:** Allows setting up interrupts on external pins to respond to external events.
- **Global Interrupts:** Manages the global interrupt settings of the microcontroller.
- **SPI Driver:** Provides communication with SPI devices using the Serial Peripheral Interface protocol.
- **Timer0 and Timer1 Drivers:** Utilizes timer/counters for precise timing and pulse generation in applications.
- **TWI (I2C) Driver:** Allows communication with I2C/TWI devices like EEPROMs, sensors, and displays.
- **UART Driver:** Enables UART communication with peripherals and other microcontrollers or computers.
- **Watchdog Timer Driver:** Utilizes the Watchdog Timer for system reset and fault recovery.

### HAL Layer:

- **Buzzer:** Control a buzzer or piezo speaker for generating audio tones and alerts.
- **DC Motor:** Drive and control DC motors for robotic and automation projects.
- **EEPROM:** Provides functions to store and retrieve non-volatile data in the AVR's internal EEPROM memory.
- **IR Sensor:** Interfacing with infrared sensors for object detection and proximity sensing.
- **Keypad:** Interface with a matrix keypad for user input.
- **LCD:** Interact with standard character-based LCD modules for displaying information.
- **LED:** Control LEDs for visual feedback or display purposes.
- **Pushbutton:** Handle pushbutton input for various applications.
- **Servo Motor:** Control servo motors for precise angle positioning.
- **Seven Segments Display:** Interface with common anode/cathode seven segments displays for numerical output.

### OS Support:

- **FreeRTOS:** Implementation of the FreeRTOS real-time operating system for task scheduling and management.

## Algorithms and Data Structures

The library includes some useful algorithms and data structures:

- **Reverse a String:** Function to reverse a given string in-place.
- **Stack:** Implementation of a stack data structure for efficient last-in-first-out (LIFO) operations.

## Getting Started

1. Clone the repository to your local machine using `git clone`.
2. Choose the required drivers and HAL modules based on your project requirements.
3. Include the necessary header files in your project.
4. Configure the drivers and HAL modules with your desired settings.
5. Call the provided functions to interact with the peripherals and devices.

## Contribution

Contributions to the project are highly appreciated! If you find any bugs, have ideas for improvements, or wish to add support for additional features, feel free to open an issue or submit a pull request. The project follows a clear coding style and documentation guidelines to ensure consistency and ease of maintenance.

## License

This project is distributed under the MIT License, allowing you to freely use, modify, and distribute the code for both personal and commercial projects.

## Community and Support

For discussions, support, and general interaction with other developers using these drivers and HAL modules, join our active community on [GitHub Discussions](link-to-discussions) or the [developer forum](link-to-forum).

Let's build exciting projects with the AVR Atmega32 Drivers and HAL Library and take embedded systems development to the next level! Happy coding!

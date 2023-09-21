/***********************************************************************
 * 
 * Blink a LED in Arduino-style and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2022 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#define LED_GREEN PB5   // PB5 is AVR pin where green on-board LED 
                        // is connected
#define LED_BOARD PB8
#define LED_BOARD2 PB10   
#define SHORT_DELAY 750 // Delay in milliseconds
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops


// -----
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
#include "Arduino.h"
#define PB5 13          // In Arduino world, PB5 is called "13"
#define PB8 8          // In Arduino world, PB5 is called "8"
#define PB10 10          // In Arduino world, PB5 is called "10"
// -----


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    uint8_t led_value = 0;  // Local variable to keep LED status

    // Set pin where on-board LED is connected as output
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BOARD, OUTPUT);
    pinMode(LED_BOARD2, OUTPUT);

    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(SHORT_DELAY);

        // Change LED value
        if (led_value == 0) {
            led_value = 1;
            // Set pin to HIGH
            digitalWrite(LED_GREEN, HIGH);
            digitalWrite(LED_BOARD, HIGH);
            digitalWrite(LED_BOARD2, LOW);
        }
        else {
            led_value = 0;
            // Clear pin to LOW
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_BOARD, LOW);
            digitalWrite(LED_BOARD2, HIGH);
        }
    }

    // Will never reach this
    return 0;
}

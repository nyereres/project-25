#ifndef PINS_HPP
#define PINS_HPP
#include "pico/stdlib.h"
#include <cstdint>

//all the pins required for the functions

const uint8_t Forward = 1;
const uint8_t Backward = 2;
const uint8_t Turn_Left = 3;
const uint8_t Turn_Right = 4;
const uint8_t Top_Left = 5;
const uint8_t Bottom_Left = 6;
const uint8_t Top_Right = 7;
const uint8_t Bottom_Right = 8;
const uint8_t Stop = 0;
const uint8_t Contrarotate = 9;
const uint8_t Clockwise = 10;
const uint8_t StearRightt = 11;
const uint8_t StearLeft = 12;
inline void delay_ms(uint32_t ms) { sleep_ms(ms); }

const uint Trig = 14; // GPIO14
const uint Echo = 15; // GPIO15

// Servo control
const uint ServoPin = 16; // GPIO16
#endif
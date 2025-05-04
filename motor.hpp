#ifndef MOTOR_HPP
#define MOTOR_HPP
#include "pins.hpp"
#include "test.h"
#include "lib/Devices/MotorDriver.h"

#include <stdint.h>
/**
 * Runs the given motor with given speed
 * 
 * @param Dir: Motor
 * @param Speed: Speed.
 *
 * Example:
 * Motor(MOTORA, 100)
 * sleep_ms(20000) //for keeping the movement
 */
void Motor(uint8_t Dir, uint8_t Speed);

#endif // MOTOR_HPP
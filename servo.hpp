#ifndef SERVO_HPP
#define SERVO_HPP

#include <stdint.h>
#include "pins.hpp"
/**
 * Sets the degree of servo using PWM cycles
 * 
 * @param angle: Angle.
 *
 * Example:
 * set_degree(120);
 */
void set_degree(uint angle);

#endif // SERVO_HPP
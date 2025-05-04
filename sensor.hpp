#ifndef SENSOR_HPP
#define SENSOR_HPP
#include "pins.hpp"


#include <stdint.h>

// @brief distance between obstacle and the car
/**
 * Distance between car and the obstcale in cm
 * 
 * @param Trig: Trigger pin.
 * @param Echo: Echo Pin.
 *
 * Example:
 * distance(Trigger_PIN(16), Echo_PIN(17))
 */
float distance(uint Trig, uint Echo);

#endif // SENSOR_HPP
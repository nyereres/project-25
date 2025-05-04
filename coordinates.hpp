#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <stdint.h>
#include "pins.hpp"
/**
 * Exports coordinates to output file
 * 
 *
 */
void export_coordinates();
/**
 * Updates coordinates
 * 
 * @param Dir: The move being made (FORWAD, BACKWARD exc...).
 * @param Speed: The speed it makes the move.
 *
 * Example:
 * cordinates(FORWARD, 80)
 */
void cordinates(uint8_t Dir, uint8_t Speed);

#endif // COORDINATES_HPP
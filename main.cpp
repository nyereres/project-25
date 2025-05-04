#include "motor.hpp"
#include "coordinates.hpp"
#include "sensor.hpp"
#include "servo.hpp"
#include "obstacle.hpp"
#include <iostream>
#include <fstream>
#include "test.h"

std::ofstream coordinate_file;

int main(void) {
  stdio_init_all();

  sleep_ms(3000);
  printf("Obstacle Avoidance Robot\n");

  // Motor Initialization
  Motor_Init();
  printf("Motor_Init\n");

  // Open coordinate file
  coordinate_file.open("coordinates_map.csv");
  if (!coordinate_file.is_open()) {
    std::cerr << "Error: Unable to open file for writing coordinates.\n";
    exit(1);
  }
  coordinate_file << "X,Y\n"; // Write CSV header

  // Initialize ultrasonic sensor
  gpio_init(Trig);
  gpio_init(Echo);
  gpio_set_dir(Trig, GPIO_OUT);
  gpio_set_dir(Echo, GPIO_IN);

  // Initialize servo
  gpio_set_function(ServoPin, GPIO_FUNC_PWM);
  set_degree(90); // Center position

  while (1) {
    obstacle_avoidance();
  }

  if (coordinate_file.is_open()) {
    coordinate_file.close();
  }

  return 0;
}
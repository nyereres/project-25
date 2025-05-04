#include "sensor.hpp"
#include "hardware/gpio.h"
#include "pico/stdlib.h"

float distance(uint Trig, uint Echo) {
  gpio_put(Trig, false);
  sleep_us(2);
  gpio_put(Trig, true);
  sleep_us(10);
  gpio_put(Trig, false);

  uint32_t start_time = time_us_32();
  while (!gpio_get(Echo)) {
    if (time_us_32() - start_time > 100000)
      return 0;
  }
  start_time = time_us_32();
  while (gpio_get(Echo)) {
    if (time_us_32() - start_time > 100000)
      return 0;
  }
  uint32_t pulse_time = time_us_32() - start_time;
  float distance = pulse_time * 0.343 * 2;
  sleep_ms(10);
  return distance;
}
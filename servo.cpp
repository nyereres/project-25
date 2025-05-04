#include "servo.hpp"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

void set_degree(uint angle) {
  // Convert(0-180) degree to PWM(500-2500us)
  uint slice_num = pwm_gpio_to_slice_num(ServoPin);
  uint channel = pwm_gpio_to_channel(ServoPin);

  // Set PWM frequency to 50Hz (20ms period)
  pwm_set_clkdiv(slice_num, 256.0f);
  pwm_set_wrap(slice_num, 19500);

  // Map angle to pulse width (500-2500us)
  uint16_t pulse_width = 500 + (angle * 2000 / 180);
  pwm_set_chan_level(slice_num, channel, pulse_width);
  pwm_set_enabled(slice_num, true);
}
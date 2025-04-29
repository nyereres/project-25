#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "test.h" // Examples
#include <stdio.h>

// Movement constants
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

const uint Trig = 14; // GPIO14
const uint Echo = 15; // GPIO15

// Servo control
const uint ServoPin = 16; // GPIO16

int rightDistance = 0, leftDistance = 0, middleDistance = 0;

// Delay helper
void delay_ms(uint32_t ms) { sleep_ms(ms); }

// Motor control function for 4 motors
void Motor(uint8_t Dir, uint8_t Speed) {
  switch (Dir) {
  case Forward:
    Motor_Run(MOTORA, FORWARD, Speed);
    Motor_Run(MOTORB, FORWARD, Speed);
    Motor_Run(MOTORC, FORWARD, Speed);
    Motor_Run(MOTORD, FORWARD, Speed);
    break;
  case StearRightt:
    Motor_Run(MOTORA, FORWARD, Speed);
    Motor_Run(MOTORB, BACKWARD, Speed);
    Motor_Run(MOTORC, FORWARD, Speed);
    Motor_Run(MOTORD, BACKWARD, Speed);
    break;
  case StearLeft:
    Motor_Run(MOTORA, BACKWARD, Speed);
    Motor_Run(MOTORB, FORWARD, Speed);
    Motor_Run(MOTORC, BACKWARD, Speed);
    Motor_Run(MOTORD, FORWARD, Speed);
    break;
  case Backward:
    Motor_Run(MOTORA, BACKWARD, Speed);
    Motor_Run(MOTORB, BACKWARD, Speed);
    Motor_Run(MOTORC, BACKWARD, Speed);
    Motor_Run(MOTORD, BACKWARD, Speed);
    break;
  case Turn_Left:
    Motor_Run(MOTORA, BACKWARD, Speed);
    Motor_Run(MOTORB, BACKWARD, Speed);
    Motor_Run(MOTORC, FORWARD, Speed);
    Motor_Run(MOTORD, FORWARD, Speed);
    break;
  case Turn_Right:
    Motor_Run(MOTORA, FORWARD, Speed);
    Motor_Run(MOTORB, FORWARD, Speed);
    Motor_Run(MOTORC, BACKWARD, Speed);
    Motor_Run(MOTORD, BACKWARD, Speed);
    break;
  case Top_Left:
    Motor_Run(MOTORA, FORWARD, Speed / 2);
    Motor_Run(MOTORB, FORWARD, Speed);
    Motor_Run(MOTORC, FORWARD, Speed);
    Motor_Run(MOTORD, FORWARD, Speed / 2);
    break;
  case Bottom_Left:
    Motor_Run(MOTORA, BACKWARD, Speed / 2);
    Motor_Run(MOTORB, BACKWARD, Speed);
    Motor_Run(MOTORC, BACKWARD, Speed);
    Motor_Run(MOTORD, BACKWARD, Speed / 2);
    break;
  case Top_Right:
    Motor_Run(MOTORA, FORWARD, Speed);
    Motor_Run(MOTORB, FORWARD, Speed / 2);
    Motor_Run(MOTORC, FORWARD, Speed / 2);
    Motor_Run(MOTORD, FORWARD, Speed);
    break;
  case Bottom_Right:
    Motor_Run(MOTORA, BACKWARD, Speed);
    Motor_Run(MOTORB, BACKWARD, Speed / 2);
    Motor_Run(MOTORC, BACKWARD, Speed / 2);
    Motor_Run(MOTORD, BACKWARD, Speed);
    break;
  case Clockwise:
    Motor_Run(MOTORA, FORWARD, Speed);
    Motor_Run(MOTORB, FORWARD, Speed);
    Motor_Run(MOTORC, BACKWARD, Speed);
    Motor_Run(MOTORD, BACKWARD, Speed);
    break;
  case Contrarotate:
    Motor_Run(MOTORA, BACKWARD, Speed);
    Motor_Run(MOTORB, BACKWARD, Speed);
    Motor_Run(MOTORC, FORWARD, Speed);
    Motor_Run(MOTORD, FORWARD, Speed);
    break;
  case Stop:
  default:
    Motor_Stop(MOTORA);
    Motor_Stop(MOTORB);
    Motor_Stop(MOTORC);
    Motor_Stop(MOTORD);
    break;
  }
}

float distance(uint Trig, uint Echo) {
  // prepare the trigger
  gpio_put(Trig, false);
  sleep_us(2);
  gpio_put(Trig, true);
  sleep_us(10);
  gpio_put(Trig, false);

  uint32_t start_time =
      time_us_32(); 
  while (!gpio_get(Echo)) {
    if (time_us_32() - start_time > 100000)
      return 0; // to after 100ms
  }
  start_time = time_us_32();
  // 3. wait for echo
  while (gpio_get(Echo)) {
    if (time_us_32() - start_time > 100000)
      return 0; // to after 100ms
  }
  uint32_t pulse_time = time_us_32() - start_time;

  float distance = pulse_time / 58.00f; // distance in cm
  delay_ms(10);
  return distance;
}


///this part is just copy-paste from internet but I will write it on my own later, this is just to test if it works.
// Servo control using PWM
void servo_write(uint angle) {
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

void obstacle_avoidance() {
  middleDistance = distance(Trig, Echo);
  printf("Distance: %d cm\n", middleDistance);

  if (middleDistance <= 25 && middleDistance > 0) {
    Motor(Stop, 0);
    delay_ms(500);

    // Look right
    servo_write(10);
    delay_ms(500);
    rightDistance = distance(Trig, Echo);

    // Look center
    servo_write(90);
    delay_ms(500);

    // Look left
    servo_write(170);
    delay_ms(500);
    leftDistance = distance(Trig, Echo);

    // Return to center
    servo_write(90);
    delay_ms(500);

    printf("Left: %d cm, Right: %d cm\n", leftDistance, rightDistance);

    if (rightDistance > leftDistance) {
      Motor(Stop, 0);
      delay_ms(100);
      Motor(Backward, 70);
      delay_ms(1000);
      Motor(StearRightt, 70);
      delay_ms(600);
    } else if (rightDistance < leftDistance) {
      Motor(Stop, 0);
      delay_ms(100);
      Motor(Backward, 70);
      delay_ms(1000);
      Motor(StearLeft, 70);
      delay_ms(600);
    } else if ((rightDistance < 20) || (leftDistance < 20)) {
      Motor(Backward, 70);
      delay_ms(1000);
      Motor(StearLeft, 70);
      delay_ms(600);
    } else {
      Motor(Backward, 70);
      delay_ms(1000);
      Motor(StearRightt, 70);
      delay_ms(600);
    }
  } else {
    Motor(Forward, 70);
  }
}

int main(void) {
  stdio_init_all();

  DEV_Delay_ms(3000);
  printf("Obstacle Avoidance Robot\n");

  // 2. Motor Initialization
  Motor_Init();
  printf("Motor_Init\n");

  // Initialize ultrasonic sensor
  gpio_init(Trig);
  gpio_init(Echo);
  gpio_set_dir(Trig, GPIO_OUT);
  gpio_set_dir(Echo, GPIO_IN);

  // Initialize servo
  gpio_set_function(ServoPin, GPIO_FUNC_PWM);
  servo_write(90); // Center position

  while (1) {
    obstacle_avoidance();
  }

  return 0;
}
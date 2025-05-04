#include "pico/stdlib.h"
#include "test.h" //Examples
#include <stdio.h>

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

// Delay function cuz why not
void delay_ms(uint32_t ms) {
     sleep_ms(ms); 
}

// Motor control function for 4 motors
void Motor(uint8_t Direction, uint8_t Speed) {
  switch (Direction) {
  case Forward:
    // All motors forward at same speed
    Motor_Run(MOTORA, FORWARD, Speed);
    Motor_Run(MOTORB, FORWARD, Speed);
    Motor_Run(MOTORC, FORWARD, Speed);
    Motor_Run(MOTORD, FORWARD, Speed);
    break;
  case StearRightt:
    // stear to right, top side forwad bottom side backward
    Motor_Run(MOTORA, FORWARD, Speed);
    Motor_Run(MOTORB, BACKWARD, Speed);
    Motor_Run(MOTORC, FORWARD, Speed);
    Motor_Run(MOTORD, BACKWARD, Speed);
    break;
  case StearLeft:
    // stear to left, bottom side forwad top side backward
    Motor_Run(MOTORA, BACKWARD, Speed);
    Motor_Run(MOTORB, FORWARD, Speed);
    Motor_Run(MOTORC, BACKWARD, Speed);
    Motor_Run(MOTORD, FORWARD, Speed);

    break;
  case Backward:
    // All motors backward at same speed
    Motor_Run(MOTORA, BACKWARD, Speed);
    Motor_Run(MOTORB, BACKWARD, Speed);
    Motor_Run(MOTORC, BACKWARD, Speed);
    Motor_Run(MOTORD, BACKWARD, Speed);
    break;
  case Turn_Left:
    // Left side back, right side forward
    Motor_Run(MOTORA, BACKWARD, Speed);
    Motor_Run(MOTORB, BACKWARD, Speed);
    Motor_Run(MOTORC, FORWARD, Speed);
    Motor_Run(MOTORD, FORWARD, Speed);
    break;
  case Turn_Right:
    // Left side forward, right side back
    Motor_Run(MOTORA, FORWARD, Speed);
    Motor_Run(MOTORB, FORWARD, Speed);
    Motor_Run(MOTORC, BACKWARD, Speed);
    Motor_Run(MOTORD, BACKWARD, Speed);
    break;
  case Top_Left:
    // Diagonal movement - front right and back left forward
    Motor_Run(MOTORA, FORWARD, Speed / 2);
    Motor_Run(MOTORB, FORWARD, Speed);
    Motor_Run(MOTORC, FORWARD, Speed);
    Motor_Run(MOTORD, FORWARD, Speed / 2);
    break;
  case Bottom_Left:
    // Diagonal movement - front left and back right backward
    Motor_Run(MOTORA, BACKWARD, Speed / 2);
    Motor_Run(MOTORB, BACKWARD, Speed);
    Motor_Run(MOTORC, BACKWARD, Speed);
    Motor_Run(MOTORD, BACKWARD, Speed / 2);
    break;
  case Top_Right:
    // Diagonal movement - front left and back right forward
    Motor_Run(MOTORA, FORWARD, Speed);
    Motor_Run(MOTORB, FORWARD, Speed / 2);
    Motor_Run(MOTORC, FORWARD, Speed / 2);
    Motor_Run(MOTORD, FORWARD, Speed);
    break;
  case Bottom_Right:
    // Diagonal movement - front right and back left backward
    Motor_Run(MOTORA, BACKWARD, Speed);
    Motor_Run(MOTORB, BACKWARD, Speed / 2);
    Motor_Run(MOTORC, BACKWARD, Speed / 2);
    Motor_Run(MOTORD, BACKWARD, Speed);
    break;
  case Clockwise:
    // Rotate clockwise - left side forward, right side backward
    Motor_Run(MOTORA, FORWARD, Speed);
    Motor_Run(MOTORB, FORWARD, Speed);
    Motor_Run(MOTORC, BACKWARD, Speed);
    Motor_Run(MOTORD, BACKWARD, Speed);
    break;
  case Contrarotate:
    // Rotate counter-clockwise - left side backward, right side forward
    Motor_Run(MOTORA, BACKWARD, Speed);
    Motor_Run(MOTORB, BACKWARD, Speed);
    Motor_Run(MOTORC, FORWARD, Speed);
    Motor_Run(MOTORD, FORWARD, Speed);
    break;
  case Stop:
  default:
    // Stop all motors
    Motor_Stop(MOTORA);
    Motor_Stop(MOTORB);
    Motor_Stop(MOTORC);
    Motor_Stop(MOTORD);
    break;
  }
}

int main(void) {
  #define SPEED = 80;
  stdio_init_all();
  DEV_Delay_ms(3000);
  printf("MOTOR TEST"); // serial monitor functions for debugging
  // 2.Motor Initialization
  Motor_Init();
  printf("Motor_Init\r\n"); // serial monitor functions for debugging

  printf("Motor_Run\r\n");
  // function to move with a designated move and a designated speed.
  Motor(Forward, SPEED);
  // delay_ms (which is just sleep_ms) for 2000 ms to continue moving for that
  // long.
  delay_ms(2000);
  Motor(StearRightt, SPEED);
  delay_ms(2000);
  Motor(StearLeft, SPEED);
  delay_ms(2000);
  Motor(Backward, SPEED);
  delay_ms(2000);
  Motor(Turn_Left, SPEED);
  delay_ms(2000);
  Motor(Turn_Right, SPEED);
  delay_ms(2000);
  Motor(Top_Left, SPEED);
  delay_ms(2000);
  Motor(Bottom_Right, SPEED);
  delay_ms(2000);
  Motor(Bottom_Left, SPEED);
  delay_ms(2000);
  Motor(Top_Right, SPEED);
  delay_ms(2000);
  Motor(Clockwise, SPEED);
  delay_ms(2000);
  Motor(Contrarotate, SPEED);
  delay_ms(2000);
  Motor(Stop, 0);
  delay_ms(2000);

  // Motor_Run(MOTORB, BACKWARD, 100);
  return 0;
}
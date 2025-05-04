#include "motor.hpp"
#include "coordinates.hpp"
#include "hardware/gpio.h"
#include "lib/Devices/MotorDriver.h"

void Motor(uint8_t Dir, uint8_t Speed) {
  Motor_Init();
  cordinates(Dir, Speed); // Update coordinates based on direction
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
    case Stop:
    default:
      Motor_Stop(MOTORA);
      Motor_Stop(MOTORB);
      Motor_Stop(MOTORC);
      Motor_Stop(MOTORD);
      break;
  }
}
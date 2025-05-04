#include "obstacle.hpp"
#include "motor.hpp"
#include "sensor.hpp"
#include "servo.hpp"
#include <stdio.h>

int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void obstacle_avoidance() {
  middleDistance = distance(Trig, Echo);
  printf("Distance: %d cm\n", middleDistance);

  if (middleDistance <= 25 && middleDistance > 0) {
    Motor(Stop, 0);
    delay_ms(500);

    // Look right
    set_degree(10);
    delay_ms(500);
    rightDistance = distance(Trig, Echo);

    // Look center
    set_degree(90);
    delay_ms(500);

    // Look left
    set_degree(170);
    delay_ms(500);
    leftDistance = distance(Trig, Echo);

    // Return to center
    set_degree(90);
    delay_ms(500);

    printf("Left: %d cm, Right: %d cm\n", leftDistance, rightDistance);

    if (rightDistance > leftDistance) {
      Motor(Backward, 70);
      delay_ms(1000);
      Motor(StearRightt, 70);
      delay_ms(600);
    } else if (rightDistance < leftDistance) {
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
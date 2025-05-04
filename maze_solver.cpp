#include "maze_solver.hpp"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "motor.hpp"
#include <stdio.h>

extern int rightDistance, middleDistance;

void right_hand_rule() {
    set_degree(90);
    delay_ms(500);
    middleDistance = distance(Trig, Echo); // front distance

    set_degree(10);
    delay_ms(500);
    rightDistance = distance(Trig, Echo); // right distance

    if (rightDistance > 10) {
        // right is open, go right
        Motor(StearRightt, 70);
        delay_ms(500);
    } else if (middleDistance > 10) {
        // middle is open, go straight
        Motor(Forward, 70);
    } else {
        // middle and right are closed, go left
        Motor(StearLeft, 70);
        delay_ms(500);
    }
}
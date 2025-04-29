#include <iostream>
#include "pico/stdlib.h"
#include "test.h" // Examples

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

// Delay function
void delay_ms(uint32_t ms) {
    sleep_ms(ms);
}

// Motor control function for 4 motors
void Motor(uint8_t Direction, uint8_t Speed) {
    switch (Direction) {
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

int main() {
    constexpr uint8_t SPEED = 80;
    stdio_init_all();
    DEV_Delay_ms(3000);
    std::cout << "MOTOR TEST" << std::endl;

    Motor_Init();
    std::cout << "Motor_Init" << std::endl;

    std::cout << "Motor_Run" << std::endl;
    Motor(Forward, SPEED);
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

    return 0;
}
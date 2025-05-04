#include <iostream>
#include <utility> // For std::pair
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

// Coordinates
std::pair<int, int> coordinate = {0, 0};

// send coordinates to putty
void send_coordinates() {
    printf("Coordinates: (%d, %d)\n", coordinate.first, coordinate.second);
}


void cordinates(uint8_t Dir, uint8_t Speed) {
    switch (Dir) {
        case Forward:
            coordinate.second += Speed / 10; // Move forward (increase Y)
            break;
        case Backward:
            coordinate.second -= Speed / 10; // Move backward (decrease Y)
            break;
        case Turn_Left:
            coordinate.first -= Speed / 10; // Turn left (decrease X)
            break;
        case Turn_Right:
            coordinate.first += Speed / 10; // Turn right (increase X)
            break;
        case StearRightt:
            coordinate.first += Speed / 20; // Increase X
            coordinate.second += Speed / 20; // Increase Y
            break;
        case StearLeft:
            coordinate.first -= Speed / 20; // Decrease X
            coordinate.second += Speed / 20; // Increase Y
            break;
        case Top_Left:
            coordinate.first -= Speed / 20; // Diagonal top-left
            coordinate.second += Speed / 20;
            break;
        case Top_Right:
            coordinate.first += Speed / 20; // Diagonal top-right
            coordinate.second += Speed / 20;
            break;
        case Bottom_Left:
            coordinate.first -= Speed / 20; // Diagonal bottom-left
            coordinate.second -= Speed / 20;
            break;
        case Bottom_Right:
            coordinate.first += Speed / 20; // Diagonal bottom-right
            coordinate.second -= Speed / 20;
            break;
        default:
            break;
    }
    send_coordinates();
}

// Motor control function for 4 motors
void Motor(uint8_t Direction, uint8_t Speed) {
    cordinates(Direction, Speed); // Update coordinates based on direction
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
    stdio_init_all(); // Initialize serial communication
    DEV_Delay_ms(3000);
    printf("MOTOR TEST WITH SERIAL COMMUNICATION\n");

    Motor_Init();
    printf("Motor_Init\n");

    printf("Motor_Run\n");
    Motor(Forward, SPEED);
    delay_ms(20000);
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
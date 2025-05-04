#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../examples/kivu.cpp"

// Mock functions for hardware-dependent operations
MOCK_FUNCTION(void, Motor_Run, (int motor, int direction, int speed), ());
MOCK_FUNCTION(void, Motor_Stop, (int motor), ());
MOCK_FUNCTION(void, gpio_put, (uint gpio, bool value), ());
MOCK_FUNCTION(bool, gpio_get, (uint gpio), ());
MOCK_FUNCTION(uint32_t, time_us_32, (), ());
MOCK_FUNCTION(void, sleep_us, (uint32_t us), ());
MOCK_FUNCTION(void, sleep_ms, (uint32_t ms), ());

// Test `cordinates` function
TEST(CordinatesTest, UpdatesCoordinatesCorrectly) {
    coordinate = {0, 0}; // Reset coordinates

    cordinates(Forward, 50);
    EXPECT_EQ(coordinate.first, 0);
    EXPECT_EQ(coordinate.second, 5);

    cordinates(Backward, 30);
    EXPECT_EQ(coordinate.first, 0);
    EXPECT_EQ(coordinate.second, 2);

    cordinates(Turn_Left, 40);
    EXPECT_EQ(coordinate.first, -4);
    EXPECT_EQ(coordinate.second, 2);

    cordinates(Turn_Right, 20);
    EXPECT_EQ(coordinate.first, -2);
    EXPECT_EQ(coordinate.second, 2);
}

// Test `distance` function
TEST(DistanceTest, MeasuresDistanceCorrectly) {
    EXPECT_CALL(gpio_put(Trig, false)).Times(1);
    EXPECT_CALL(gpio_put(Trig, true)).Times(1);
    EXPECT_CALL(gpio_put(Trig, false)).Times(1);

    EXPECT_CALL(time_us_32()).WillOnce(::testing::Return(1000))
                             .WillOnce(::testing::Return(2000))
                             .WillOnce(::testing::Return(3000));

    EXPECT_CALL(gpio_get(Echo)).WillOnce(::testing::Return(false))
                               .WillOnce(::testing::Return(true))
                               .WillOnce(::testing::Return(false));

    float result = distance(Trig, Echo);
    EXPECT_NEAR(result, 34.48, 0.01); // Expected distance in cm
}

// Test `Motor` function
TEST(MotorTest, RunsMotorsCorrectly) {
    EXPECT_CALL(Motor_Run(MOTORA, FORWARD, 50)).Times(1);
    EXPECT_CALL(Motor_Run(MOTORB, FORWARD, 50)).Times(1);
    EXPECT_CALL(Motor_Run(MOTORC, FORWARD, 50)).Times(1);
    EXPECT_CALL(Motor_Run(MOTORD, FORWARD, 50)).Times(1);

    Motor(Forward, 50);
}

// Test `obstacle_avoidance` function
TEST(ObstacleAvoidanceTest, AvoidsObstaclesCorrectly) {
    EXPECT_CALL(distance(Trig, Echo)).WillOnce(::testing::Return(20))
                                     .WillOnce(::testing::Return(30))
                                     .WillOnce(::testing::Return(10));

    EXPECT_CALL(servo_write(10)).Times(1);
    EXPECT_CALL(servo_write(90)).Times(2);
    EXPECT_CALL(servo_write(170)).Times(1);

    EXPECT_CALL(Motor(Stop, 0)).Times(1);
    EXPECT_CALL(Motor(Backward, 70)).Times(1);
    EXPECT_CALL(Motor(StearRightt, 70)).Times(1);

    obstacle_avoidance();
}
#include "pico/stdlib.h"
#include <stdio.h>
#include <math.h>

// Pins
#define TRIG_PIN 0  // GP0
#define ECHO_PIN 1  // GP1

// Speed of sound in cm/us (approx. at 20°C)
#define SOUND_SPEED_CM_US 0.0343

// Initialize Ultrasonic Sensor
void init_ultrasonic() {
    gpio_init(TRIG_PIN);
    gpio_init(ECHO_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
}

// Measure distance in cm
float measure_distance_cm() {
    // Send a 10us trigger pulse
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);

    // Wait for echo to go high (start of pulse)
    while (!gpio_get(ECHO_PIN));

    // Measure pulse duration (in microseconds)
    uint32_t start_time = time_us_32();
    while (gpio_get(ECHO_PIN));
    uint32_t pulse_duration = time_us_32() - start_time;

    // Calculate distance (cm)
    float distance = (pulse_duration * SOUND_SPEED_CM_US) / 2;
    return distance;
}

int main() {
    // Initialize USB serial (for printf)
    stdio_init_all();

    // Initialize ultrasonic sensor
    init_ultrasonic();

    printf("Ultrasonic Sensor Test\n");

    while (true) {
        float distance = measure_distance_cm();
        printf("Distance: %.2f cm\n", distance);  // Print to serial
        sleep_ms(500);  // Delay between readings
    }

    return 0;
}
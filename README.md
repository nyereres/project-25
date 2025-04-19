# Treasure Hunt Robot Car

Welcome to the **Treasure Hunt Robot Car** project, developed by a fearless crew of four pirates for a school project. Our autonomous robot car navigates a dangerous labyrinth in the Inca region to find the treasure room, avoiding hidden traps and outsmarting rival pirate teams. Built using a Raspberry Pi Pico, C++, and a provided car kit, this project follows Scrum methodology and meets all "must have" requirements while incorporating advanced features.

## Project Overview

The robot car autonomously traverses a maze, avoiding walls with ultrasonic sensors, making precise movements (forward, backward, lateral, 90°/180° turns), and stopping at the treasure room. It optimizes routes, records paths, and communicates data to a laptop, ensuring efficiency and reliability. The project was developed over 7 weeks using agile practices, with a focus on teamwork, robust code, and thorough documentation.

## Features

### Must Have
- Autonomous movement: Drives straight (forward/backward), laterally, and makes 90°/180° turns.
- Wall avoidance: Uses ultrasonic sensors to prevent collisions with maze walls.
- Maze traversal: Navigates from origin to destination and stops at the treasure room.

### Should Have
- Route optimization: Improves path efficiency using a flood-fill algorithm after initial traversal.
- Data recording: Logs distance and time taken to traverse the maze.
- Communication: Sends route data to a laptop via serial communication.
- Path storage: Records traversed paths for efficient maze-solving.

### Could Have (Planned/Implemented)
- Obstacle avoidance: Detects and navigates around unexpected obstacles (if implemented).
- Treasure detection: Identifies treasure in the room (pending teacher approval).
- Live camera feed: Displays maze traversal on a laptop (if hardware supports).

## Hardware Requirements
- **Car Kit**: Provided chassis, motors, and wheels.
- **Raspberry Pi Pico**: Programmed with the Pico SDK.
- **Sensors**: 
  - Ultrasonic sensor (HC-SR04) for wall detection.
  - Optional: Wheel encoders for distance tracking.
- **Power**: Batteries supporting at least 30 minutes of operation.
- **Dimensions**: Fits within 400mm x 250mm x 200mm.

## Software Requirements
- **Language**: C++ with Raspberry Pi Pico SDK.
- **Tools**: 
  - CMake for building the project.
  - Git for version control.
  - Serial monitor (e.g., PuTTY or Arduino Serial Monitor) for laptop communication.
- **Dependencies**: Pico SDK libraries (included in setup).

## Setup Instructions

1. **Clone the Repository**
   ```bash
   git clone https://github.com/nyereres/project-25.git
   cd PROJECT-25
   ```

2. **Install Pico SDK**
   - Follow the [Raspberry Pi Pico SDK setup guide](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html).
   - Set the `PICO_SDK_PATH` environment variable to the SDK location.

3. **Connect Hardware**
   - Assemble the car kit as per the provided schematic (see `docs/design_report.pdf`).
   - Connect:
     - Motors to GPIO pins 12-15 (PWM and direction).
     - Ultrasonic sensor to GPIO pins 16 (TRIG) and 17 (ECHO).
     - Battery pack to power the Pico and motors.

4. **Build and Flash Code**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
   - Copy the generated `.uf2` file to the Pico (mounted as a USB drive).

5. **Run the Robot**
   - Place the robot at the maze origin.
   - Power on the Pico and motors.
   - Monitor serial output (if enabled) using a serial monitor at 115200 baud rate.

## Repository Structure
```
PROJECT-25/
├── src/                  # C++ source code
│   ├── main.cpp          # Main program with navigation logic
│   ├── motor_control.cpp # Motor movement functions
│   ├── sensors.cpp       # Sensor reading and processing
│   └── navigation.cpp    # Maze-solving algorithms
├── include/              # Header files
├── docs/                 # Documentation
│   ├── project_plan.pdf  # Project timeline and roles
│   ├── design_report.pdf # Hardware and software design
│   └── test_report.pdf   # Test cases and results
├── scripts/              # Utility scripts (e.g., serial communication)
├── CMakeLists.txt        # Build configuration
└── README.md             # This file
```

## Usage
- **Run Mode**: The robot starts navigating the maze upon power-up, using a right-hand rule algorithm to avoid walls and reach the destination.
- **Debug Mode**: Enable serial output in `main.cpp` to log distance, time, and route data to a laptop.
- **Testing**: Use the test maze (consult teacher for layout) to verify movement, wall avoidance, and stopping behavior.

## Scrum Methodology
- **Sprints**: 7 weekly sprints with planning, development, demo, and retrospective.
- **Artifacts**:
  - Backlog and sprint board managed via Trello (link shared with teacher).
  - Daily stand-ups for progress tracking.
- **Documentation**: Project plan, design report, and test report in `docs/`.

## Team
- **Pirate 1 (Scrum Master / Software Lead)**: Oversees code and GitHub.
- **Pirate 2 (Hardware Lead / Sensor Specialist)**: Manages hardware integration.
- **Pirate 3 (Navigation & Optimization Specialist)**: Develops maze-solving algorithms.
- **Pirate 4 (Documentation & Testing Lead)**: Handles docs and testing.

## Contributing
- Create feature branches (`feature/<name>`) for new development.
- Submit pull requests for code review.
- Follow commit message format: `<type>(<scope>): <description>` (e.g., `feat(motor): add forward movement`).

## License
This project is for educational purposes and not distributed under a public license. Contact the team for usage permissions.

## Acknowledgments
- **Teacher (Product Owner)**: For guidance and requirement clarification.
- **Raspberry Pi Foundation**: For Pico SDK and documentation.
- **Pirate Crew**: For teamwork and dedication to finding the treasure!
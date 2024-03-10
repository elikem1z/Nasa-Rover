# Mars Perseverance Rover Model

![Perseverance_rover_pillars](https://github.com/elikem1z/Nasa-Rover/assets/109632084/43e9f2f6-01f5-420d-8964-1eb871936d51)

[Image reference](https://www.esa.int/ESA_Multimedia/Images/2020/04/Perseverance_rover)

## Project Overview

This repository contains the Arduino code for a model of the NASA Mars Perseverance Rover, designed and built as a school project. The rover model is capable of autonomous movement, obstacle detection, and environmental interaction, showcasing a simplified version of the technology used in the actual Mars rover.

## Motivation

The project was inspired by NASA's Mars 2020 Perseverance rover mission, aiming to educate and inspire students about space exploration, robotics, and programming. This model serves as a hands-on project to understand the basics of robotic movement, sensor integration, and autonomous decision-making processes.

## Features

- **Autonomous Navigation:** Utilizes ultrasonic sensors for obstacle avoidance.
- **Environmental Interaction:** Employs LDR (Light Dependent Resistor) for light sensing and a Sharp sensor for precise distance measurement.
- **Real-time Feedback:** Equipped with an LCD display for real-time status updates.
- **Remote Control:** Features Bluetooth connectivity for remote operation.
- **Photography Capability:** Integrates a camera module for taking pictures.

## Tech/Framework Used

- Arduino IDE
- C/C++ for Arduino
- LiquidCrystal_I2C Library
- Adafruit_VC0706 Library for camera module
- HCSR04 Library for ultrasonic sensor
- SoftwareSerial Library for Bluetooth communication

## Hardware Components

- Arduino Uno/Mega
- HC-SR04 Ultrasonic Sensor
- Sharp GP2Y0A21YK0F IR Range Sensor
- LDR (Light Dependent Resistor)
- Liquid Crystal Display (LCD) with I2C
- DC Motors for movement
- Motor Driver Module (L298N or equivalent)
- Bluetooth Module (HC-05/HC-06)
- SD Card Module for data storage
- Digital Camera Module (VC0706-based)

## Installation

1. **Set up the Arduino environment:** Download and install the Arduino IDE from the [Arduino website](https://www.arduino.cc/en/Main/Software).
2. **Install necessary libraries:** Open the Arduino IDE, go to Sketch > Include Library > Manage Libraries. Search for and install `LiquidCrystal_I2C`, `Adafruit_VC0706`, and `HCSR04`.
3. **Hardware assembly:** Assemble the rover model with the specified components. Ensure all connections are secure.
4. **Upload the code:** Connect the Arduino to your computer, open the provided code in the Arduino IDE, select the correct board and port from the Tools menu, and upload the sketch.

## Usage

After successfully uploading the code to your Arduino board:

1. Power on the rover.
2. The rover will display a "Robot ready to operate." message on the LCD.
3. Use serial communication or Bluetooth commands to control the rover's movements and actions.

## How to Contribute

Contributions are welcome! If you have suggestions for improvements or new features, feel free to fork the repo, make changes, and submit a pull request.

## License

MIT © Elikem Hamenoo

## Acknowledgements

- Thanks to NASA's Mars 2020 Perseverance rover mission for inspiration.

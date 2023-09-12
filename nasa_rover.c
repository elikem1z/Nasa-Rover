#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // Include libraries for LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize LCD with I2C address
#define LDRpin A0  // Define a pin for the Light Dependent Resistor (LDR)
#include <SoftwareSerial.h>
#include <Adafruit_VC0706.h>
#include <SD.h>
#include <SPI.h>
int state = 0;  // Initialize a variable 'state' for robot state
#include <HCSR04.h>

// Motor control pins
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;
int IN2_1 = 6;
int IN2_2 = 7;
int IN2_3 = 8;
int IN2_4 = 9;

// Ultrasonic sensor connections
const int trig = 10;
const int echo = 11;
long duration;
int distance;

// Sharp sensor connections
int vo = A2;

// Sharp connections
int ldrPin = 3;

// Function prototypes
void motorstop();
void motorforward();
void motorbackward();
void motorTurnRight();
void motorTurnLeft();
void auto_mode();
void ultra();
void sharp();
void lcdRead();
void ldr();
void blt();
int LDRValue = 0;
SoftwareSerial bt(0, 1);
SoftwareSerial cameraconnecction(2, 3);

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  
  // Motor control pins setup
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN2_1, OUTPUT);
  pinMode(IN2_2, OUTPUT);
  pinMode(IN2_3, OUTPUT);
  pinMode(IN2_4, OUTPUT);
  
  // Ultrasonic Sensor control pins setup
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  // Sharp sensor control pin setup
  pinMode(vo, OUTPUT);
  
  // LCD control pin setup
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Robot ready ");
  lcd.setCursor(0, 1);
  lcd.print("to operate.");
  delay(1000);
}

void loop() {
  if (Serial.available()) {
    state = Serial.read();  // Read a character from serial communication
  }

  // Check the state and perform corresponding actions
  switch (state) {
    case '0':
      // Stop the robot and perform other actions for state '0'
      break;
    case '1':
      // Move the robot forward for state '1'
      break;
    case '2':
      // Turn the robot right for state '2'
      break;
    case '3':
      // Turn the robot left for state '3'
      break;
    case '4':
      // Move the robot backward for state '4'
      break;
    case '5':
      // Stop the robot for state '5'
      break;
    case '6':
      // Stop the robot, measure distance, and perform other actions for state '6'
      break;
    case '7':
      // Activate autonomous mode for state '7'
      break;
    default:
      // Handle unknown state or other cases
      break;
  }
}

// Function to stop the motors
void motorstop() {
  // Turn off all motor control pins
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN2_3, LOW);
  digitalWrite(IN2_4, LOW);
}

// Function to move the robot forward
void motorforward() {
  // Set motor control pins for forward motion
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN2_1, HIGH);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN2_3, HIGH);
  digitalWrite(IN2_4, LOW);
}

// Function to turn the robot right
void motorTurnRight() {
  // Set motor control pins for right turn
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN2_1, LOW);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN2_3, HIGH);
  digitalWrite(IN2_4, HIGH);
  delay(250);  // Delay for a right turn
}

// Function to turn the robot left
void motorTurnLeft() {
  // Set motor control pins for left turn
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN2_1, HIGH);
  digitalWrite(IN2_2, LOW);
  digitalWrite(IN2_3, HIGH);
  digitalWrite(IN2_4, LOW);
  delay(250);  // Delay for a left turn
}

// Function to perform autonomous mode
void auto_mode() {
  // Implement autonomous mode logic here
  // For example, obstacle avoidance
}

// Function to measure distance using ultrasonic sensor
void ultra() {
  // Clears the trigPin
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Measuring ");
  lcd.setCursor(0, 1);
  lcd.print("distance... ");
  delay(1000);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);
  // Calculating the distance in centimeters
  distance = (duration * 0.034 / 2);
  // Display the distance on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(10, 0);
  lcd.print(distance);
  lcd.setCursor(12, 0);
  lcd.print("cm");
  delay(2000);
}

// Function to handle Sharp sensor
void sharp() {
  // Implement Sharp sensor logic here
}

// Function to read data from the LCD
void lcdRead() {
  // Read data from the LCD
}

// Function to handle LDR (Light Dependent Resistor)
void ldr() {
  // Read LDR sensor data and perform actions
}

// Function to handle Bluetooth communication
void blt() {
  // Read and write data over Bluetooth
}

// Function to move the robot backward
void motorbackward() {
  // Set motor control pins for backward motion
}

// Main program loop
void loop() {
  if (Serial.available()) {
    state = Serial.read();  // Read a character from serial communication
  }

  // Check the state and perform corresponding actions
  switch (state) {
    case '0':
      motorstop();  // Stop the robot
      break;
    case '1':
      motorforward();  // Move the robot forward
      break;
    case '2':
      motorTurnRight();  // Turn the robot right
      break;
    case '3':
      motorTurnLeft();  // Turn the robot left
      break;
    case '4':
      motorbackward();  // Move the robot backward
      break;
    case '5':
      motorstop();  // Stop the robot
      break;
    case '6':
      motorstop();
      ultra();  // Measure distance using the ultrasonic sensor
      break;
    case '7':
      auto_mode();  // Activate autonomous mode
      break;
    default:
      // Handle unknown state or other cases
      break;
  }
}

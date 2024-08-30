#include <LiquidCrystal_I2C.h>

#include <Wire.h>

LiquidCrystal_I2C lcd (0x27,20,2);



//DECLARATON OF VARIABLES

int trig = 9; 
int echo = 10; 

int front_leftIN1 = 2; 
int front_leftIN2 = 3; 
int front_rightIN1 = 4; 
int front_rightIN2 = 5; 
int back_leftIN1 = 6; 
int back_leftIN2 = 7;
int back_rightIN1 = 8; 
int back_rightIN2 = 9; 

int ldr = A0;
int ldrstatus;
int leds = A2;

int duration, distance;

char command;



void setup() {
  Serial.begin(9600);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(front_leftIN1, OUTPUT);
  pinMode(front_leftIN2, OUTPUT);
  pinMode(front_rightIN1, OUTPUT);
  pinMode(front_rightIN2, OUTPUT);
  pinMode(back_leftIN1, OUTPUT);
  pinMode(back_leftIN2, OUTPUT);
  pinMode(back_rightIN1, OUTPUT);
  pinMode(back_rightIN2, OUTPUT);

  pinMode(ldr, INPUT);
  pinMode(leds, OUTPUT);

  lcd.init();           // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Team4 Robot");  
}




void loop() {

lights();                  //calling the function for switching on the lights
 
//ULTRASONIC SENSOR

digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duration = pulseIn(echo, HIGH);
 distance = (duration/2) * 0.0343;

 
// BLUETOOTH 
while (Serial.available () ) {

    command = Serial.read ();    
  }
        if (command == 'F') {
         move_forward();
       
      }
 
      else if (command == 'B') {
          move_backward();
      
      }
            
       else if (command == 'R') {
            move_right();
      
      }
       else if (command == 'L') {
            move_left();
      
      }
      else if (command == 'S') {
            stop_motion();
      }
      else if (command == 'Q') {
        auto_mode();
      }
    
 }



//FUNCTION FOR TURNING THE LIGHTS ON
void lights () {
  ldrstatus = analogRead(ldr);
  if (ldrstatus > 800) {
    digitalWrite(leds, HIGH);
    Serial.println("Lights are on");
  }
  else {
    digitalWrite(leds, LOW);
    Serial.println("Lights are off");
  }
}


//FUNCTION FOR THE AUTOMATIC MODE
void auto_mode() {
  if (distance < 50) {
 
  stop_motion();
  delay (500);
  move_left();
  delay(1000);
  move_right();
  delay(2000);
 }
 
 else {
  move_forward();
 }
 
}



//FUNCTION FOR THE MOVEMENT OF THE ROBOT

void move_forward() {
  // all the wheels are moving  forward
  delay(10);
  digitalWrite(front_leftIN1, HIGH);
  digitalWrite(front_leftIN2, LOW);
  digitalWrite(front_rightIN1, HIGH);
  digitalWrite(front_rightIN2, LOW);
  
  digitalWrite(back_leftIN1, HIGH);
  digitalWrite(back_leftIN2, LOW);
  digitalWrite(back_rightIN1, HIGH);
  digitalWrite(back_rightIN2, LOW);

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.println("Moving forward"); 
  
}


void move_backward() {
  // wheels are moving in an anticlockwise direction
  delay(10);   
  digitalWrite(front_leftIN1, LOW);
  digitalWrite(front_leftIN2, HIGH);
  digitalWrite(front_rightIN1, LOW);
  digitalWrite(front_rightIN2, HIGH);
  
  digitalWrite(back_leftIN1, LOW);
  digitalWrite(back_leftIN2, HIGH);
  digitalWrite(back_rightIN1, LOW);
  digitalWrite(back_rightIN2, HIGH);

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.println("Moving backward");
 
}


void move_right() {
   // right wheels stop and left wheels move
  delay(10);
  digitalWrite(front_leftIN1, HIGH);
  digitalWrite(front_leftIN2, LOW);
  digitalWrite(front_rightIN1, LOW);
  digitalWrite(front_rightIN2, LOW);
  
  digitalWrite(back_leftIN1, HIGH);
  digitalWrite(back_leftIN2, LOW);
  digitalWrite(back_rightIN1, LOW);
  digitalWrite(back_rightIN2, LOW); 

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.println("Moving right");

  
}


void move_left() {
   // left wheels stop and right wheels move
   delay(10);
  digitalWrite(front_leftIN1, LOW);
  digitalWrite(front_leftIN2, LOW);
  digitalWrite(front_rightIN1, HIGH);
  digitalWrite(front_rightIN2, LOW);
  
  digitalWrite(back_leftIN1, LOW);
  digitalWrite(back_leftIN2, LOW);
  digitalWrite(back_rightIN1, HIGH);
  digitalWrite(back_rightIN2, LOW);

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.println("Moving left");

  
  
}

void stop_motion() {

     delay(10);
  digitalWrite(front_leftIN1, LOW);
  digitalWrite(front_leftIN2, LOW);
  digitalWrite(front_rightIN1, LOW);
  digitalWrite(front_rightIN2, LOW);
  
  digitalWrite(back_leftIN1, LOW);
  digitalWrite(back_leftIN2, LOW);
  digitalWrite(back_rightIN1, LOW);
  digitalWrite(back_rightIN2, LOW);

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.println("Robot stopped");

  
}

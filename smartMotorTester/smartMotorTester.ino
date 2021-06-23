/*
    Simple test program for the smart motor. Run it when the servo, light
    sensor, potentiometer, buzzer and button are connected to the Arduino. 
    It will print the sensor's readings to Serial Monitor to check if all 
    those are working and properly connected. 
*/

//The Servo library is required for this program to run.
#include<Servo.h>

/*-------------------------------------------------------------------

CHANGE THE VARIABLES BELOW TO THE PINS YOU ARE USING IN YOUR SETUP.

---------------------------------------------------------------------*/ 

//Defines the pin the servo is connected to.
int servoPin = 7;

//Defines the pin the potentiometer is connected to.
int sensorPin = A0;

//Defines the pin the buzzer is connected to.
int buzzerPin= 5;

//Defines the pin the light sensor is connected to.
int lightPin = A6;

//Defines the pin the button is connected to.
const int button = 6;



Servo Servo1; 
float Rspeed = 0; 
int brightness = 0;
int buttonState = 0;

int turn_angle =0; 
int count=0;
int mini=0;
int pos=0;
int dist=0;

int training[10][2];

void setup() {
    //Setup code
    Serial.begin(9600);
    Servo1.attach(servoPin); 
    pinMode(button, INPUT);
}

void loop() {
  //BRIGHTNESS
  brightness = analogRead(lightPin);
  Serial.print(" brightness: ");
  Serial.print(brightness);

  //BUTTON
  buttonState=digitalRead(button); 
  Serial.print(" button: ");
  Serial.print(buttonState);

  //POTENTIOMETER
  Rspeed = analogRead(sensorPin);
  Serial.print(" potentiometer: ");
  Serial.print(Rspeed);

  Serial.println("");
}

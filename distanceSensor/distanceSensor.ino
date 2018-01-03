
/*
 * The LCD circuit:
 * LCD RS pin to digital pin 5
 * LCD Enable pin to digital pin 6
 * LCD D4 pin to digital pin 7
 * LCD D5 pin to digital pin 8
 * LCD D6 pin to digital pin 9
 * LCD D7 pin to digital pin 10
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor: (pin 3)  This could also be a pententiometer
 * 
 * Utrasonic distance sensor: HC SR04
 * uses this tutorial: http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
 * and based on this code: http://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
 * 
 * Distance sensor Circuit:
 * VCC to arduino 5v 
 * GND to arduino GND
 * Echo to Arduino pin 13 
 * Trig to Arduino pin 12
 * 
 * Servo Motor: 
 * Circuit:
 * VCC to +5v
 * GND to ground
 * last one to digital pin 3
 */

#define trigPin 12
#define echoPin 13
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(5, 6, 7, 8, 9 , 10);
Servo myservo;
int pos = 0;    // variable to store the servo position

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0,1);

  myservo.attach(3);
  myservo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1);
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  lcd.write("Distance: ");
  lcd.print(distance);

  //Range is 0-60 cm
  if(distance <= 60){
    myservo.write(distance * 3);
  }
  delay(500);
  lcd.clear();
}

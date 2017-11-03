/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN takes care
  of use the correct LED pin whatever is the board used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
 
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 
  modified 2 Sep 2016
  by Arturo Guadalupi
*/
#define BLUE 2
#define RED 4
#define YELLOW 6
#define GREEN 8 
#define PURPLE 10
//#define DELAY 100

int DELAY=0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(PURPLE, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  DELAY = analogRead(A0);
  digitalWrite(BLUE, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(DELAY);                       // wait for a second
  digitalWrite(BLUE, LOW);    // turn the LED off by making the voltage LOW
  delay(DELAY);                       // wait for a second
  digitalWrite(RED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(DELAY);                       // wait for a second
  digitalWrite(RED, LOW);    // turn the LED off by making the voltage LOW
  delay(DELAY);                       // wait for a second
  digitalWrite(YELLOW, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(DELAY);                       // wait for a second
  digitalWrite(YELLOW, LOW);    // turn the LED off by making the voltage LOW
  delay(DELAY);                       // wait for a second
  digitalWrite(GREEN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(DELAY);                       // wait for a second
  digitalWrite(GREEN, LOW);    // turn the LED off by making the voltage LOW
  delay(DELAY);                       // wait for a second
  digitalWrite(PURPLE, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(DELAY);                       // wait for a second
  digitalWrite(PURPLE, LOW);    // turn the LED off by making the voltage LOW
  delay(DELAY);                       // wait for a second
  
}

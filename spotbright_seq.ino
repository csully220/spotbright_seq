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

#define GREEN 10 //correct
#define WHITE 11 //correct
#define RED 5 //correct
#define BLUE 6 //correct
#define YELLOW 9 //correct

#define DST_SNSR A0
#define DST_SNSR_MAX 500 // sensor returns "far to near" returns "500 to 0"
#define MAX_DETECT 200 // The sensor return value at which we detect a car is entering the garage
#define KNOB A3 // Knob range is 0-1023


int dist_set=57;
int dist_raw=500;
bool warn_lt = 0;
int raw_pot = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(WHITE, OUTPUT);
  pinMode(GREEN, OUTPUT);

  // White light - we're on
  digitalWrite(WHITE, HIGH);
  
}

// the loop function runs over and over again forever
void loop() {
  
  raw_pot = analogRead( KNOB );
  if (raw_pot < 50) raw_pot = 50;
  dist_set = map( raw_pot, 50, 1023, 0, MAX_DETECT );
  dist_raw = analogRead( DST_SNSR );
  
  //Serial.print("Raw: ");
  //Serial.println( dist_set );
 
  Serial.print( "Set: " );
  Serial.println( dist_set );

  // Not close enough
  if( dist_raw > MAX_DETECT ){
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
  }

  // Close but not close enough
  if ( dist_raw < MAX_DETECT && dist_raw > dist_set ) {
    digitalWrite(GREEN, HIGH);
    warn_lt = !warn_lt;
    if(warn_lt)
        digitalWrite(YELLOW, HIGH);
    else
        digitalWrite(YELLOW, LOW);
  }
  
  // Close enough, STOP!
  if ( dist_raw <= dist_set ) {
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
  }  else {
    digitalWrite(RED, LOW);
  }
  
  delay(500);
  
}

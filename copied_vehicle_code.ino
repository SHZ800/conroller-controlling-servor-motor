#include <Servo.h>

int ch1; // Here's where we'll keep our channel values

int ch2;

int ch3;

int sped;

Servo myservo;


void setup() {

  pinMode(6, INPUT); // Set our input pins as such

  pinMode(7, INPUT); pinMode(8, INPUT);

  Serial.begin(9600); // Pour a bowl of Serial
  myservo.attach(3);

}

void loop() {

  ch1 = pulseIn(6, HIGH, 25000); // Read the pulse width of

  ch2 = pulseIn(7, HIGH, 25000); // each channel

  ch3 = pulseIn(8, HIGH, 25000);

#if 0 //Set to 1 to activate
  Serial.print("Channel 1:"); // Print the value of

  Serial.println(ch1); // each channel
#endif

#if 0 //Set to 1 to activate
  Serial.print("Channel 2:");

  Serial.println(ch2);
#endif

#if 1 //Set to 1 to activate
  Serial.print("Channel 3:");

  Serial.println(ch3);
#endif

  sped = map(ch3, 1100, 2095, 0, 255);
  Serial.println(sped);

  one();
  two();

  delay(500);

}
void one() {

  // CHANNEL 1

  if (ch1 > 1670) {
    //turn left
    myservo.write(170);
    delay(100);
  }
  else if (ch1 < 1350) {
    //turn right
    myservo.write(10);
    delay(100);
  }
  else if (ch1 < 1600 && ch1 > 1400) {
    //re-center
    myservo.write(90);
    delay(100);
  }
//#############################
}

void two() {

  // CHANNEL 2

  if (ch2 > 1620) {
    //up
    myservo.write(170);
    delay(100);
  }
  else if (ch2 < 1420) {
    // down
    myservo.write(10);
    delay(100);
  }
  else if (ch2 < 1590 && ch2 > 1320) {
    //center
    myservo.write(90);
    delay(100);
  }
//#########################
}

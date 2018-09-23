// Arduino pin numbers
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper2(stepsPerRevolution, 8, 9, 10, 11);
Stepper myStepper1(stepsPerRevolution, 4, 5, 6, 7);


int stepCount = 0;         // number of steps the motor has taken
int potPin = 2;    // select the input pin for the potentiometer
int val = 0;  

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 3; // analog pin connected to X output
const int Y_pin = 4; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
    myStepper1.setSpeed(60);
      myStepper2.setSpeed(60);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potPin);
  Serial.print("Pot:  ");
  Serial.print(val);
  Serial.print("\n");
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  if(analogRead(X_pin) > 800){
      myStepper1.step(20);
      myStepper2.step(20);
  }
  if(analogRead(X_pin) < 400){
      myStepper1.step(-20);
      myStepper2.step(-20);
  }
  if(analogRead(Y_pin) > 800){
      myStepper1.step(-20);
      myStepper2.step(20);
  }
  if(analogRead(Y_pin) < 400){
      myStepper1.step(20);
      myStepper2.step(-20);

  }
    Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
    Serial.print("\n");
    Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
    Serial.print("\n");
  delay(500);
}

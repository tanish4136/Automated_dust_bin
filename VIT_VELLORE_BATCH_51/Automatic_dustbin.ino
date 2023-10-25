#include <Servo.h>

Servo myservo;
int trigPin = 7;
int echoPin = 8;
int ledPin = 10;  // Pin for the LED
long duration;
int distance;

void setup() {
  myservo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.println("Lid is open.");

  if (distance < 10) {
    myservo.write(90); // Open the lid
    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("Lid is open.");
    delay(2000);       // Keep the lid open for 2 seconds
    myservo.write(0);  // Close the lid
    digitalWrite(ledPin, LOW); // Turn off the LED
  }
  delay(500); // Adjust this delay as needed
}
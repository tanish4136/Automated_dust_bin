# Automated_dust_bin
Automated Dust Bin:

DESCRIPTION: Develop a simple Arduino UNO-based Automatic Dust Bin system which can open the lid when it senses the object movement nearby

PROBLEM STATEMENT:
Even with technological advancements, ineffective trash collection and management systems continue to plague many urban areas. Littering, overflowing dumpsters, and tardiness in emptying containers are prevalent problems that not only lead to ugly surroundings but also have detrimental effects on the environment and public health. Automated dust bins that can maximize waste collection, minimize overflow, and improve general sanitation practices are desperately needed to solve these issues.

Scope Of Solution:
1.	Efficient Waste Collection: 
The primary goal of automated dust bins is to facilitate more efficient waste collection. These bins can automatically open when a person approaches or when waste is placed in them, reducing the need for manual lid handling.

2.	Capacity Optimization: 
Automated dust bins with compaction mechanisms aim to maximize bin capacity by compressing waste, reducing the frequency of emptying, and lowering operational costs.

3.	Improved Waste Management: 
Smart dust bins can provide real-time data on fill levels, allowing waste management authorities to schedule collections more effectively and reduce instances of overflowing bins.

4.	Hygiene and Odor Control: 
Automated dust bins can include features like odor control systems to maintain a cleaner and more pleasant environment in public spaces.

5.	Waste Sorting: 
Some automated bins offer the option of sorting waste into separate compartments, promoting recycling and environmentally friendly waste disposal practices.

6.	Data Connectivity: 
With IoT capabilities, these bins can connect to central servers or mobile apps, enabling remote monitoring, maintenance alerts, and data analytics for better waste management decisions.

7.	Customization and User Interfaces: 
Many automated dust bins come with user interfaces, allowing users to set preferences, check the status of the bin, and receive notifications about maintenance or fill levels.

8.	Environmental Impact: 
Automated dust bins can contribute to environmental sustainability by promoting responsible waste disposal and recycling, ultimately reducing the ecological footprint of waste management.

9.	Integration into Smart City Solutions: 
Automated dust bins can be integrated into larger smart city initiatives, enhancing overall urban planning and waste management strategies.

10.	Cost Efficiency: 
Through optimization of waste collection schedules and reduced labour costs, automated dust bins can be a cost-effective solution for municipalities and waste management companies.

Hardware Components:
1.	ARDUINO UNO R3
2.	RESISTOR
3.	LED
4.	Ultrasonic distance sensor
5.	Micro servo
6.	BREADBOARD

Software Components:
1.	Arduino IDE
2.	C/C++ for microcontroller programming
3.	TinkerCAD

CODE FOR THE SOLUTION:
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
  delay(500); // Adjust this delay as needed
}

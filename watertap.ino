#include <Servo.h>

Servo servo;
int irSensorPin = 6;  // IR sensor digital output pin
int servoPin = 7;     // Servo pin
int ledPin = 10;      // LED pin on Arduino 

void setup() {
    Serial.begin(9600);
    servo.attach(servoPin);
    pinMode(irSensorPin, INPUT);  // IR sensor as input
    pinMode(ledPin, OUTPUT);      // Optional LED for feedback
    servo.write(0);               // Initial servo position
    delay(100);
    servo.detach();               // Detach the servo initially
}

void loop() {
    int sensorState = digitalRead(irSensorPin); 

    if (sensorState == HIGH) {  // IR sensor detects object (red light blinks)
        Serial.println("No object any detected.");
        digitalWrite(ledPin, LOW);    
    } else {
        Serial.println("Object detected! Rotating servo.");
        digitalWrite(ledPin, HIGH);  
        servo.attach(servoPin);      
        servo.write(0);              // Rotate servo to initial position
        delay(5000);                 // Hold for 5 second
        servo.write(150);            // Rotate servo to open position
        delay(1000);                 // Hold for 1 second
        servo.detach();              /
        digitalWrite(ledPin, LOW);
    }

    delay(100);  // Small delay for stability
}

#include <Servo.h>

Servo myServo;  // Create a servo object
int angle = 0;   // Variable to store the angle value

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  myServo.attach(9);   // Attach the servo to pin 9
}

void loop() {
  // while (Serial.available() > 0) {
  //   char c = Serial.read();  // Read the incoming character
  //   if (c == '\n') {
  //     // If newline character is received, set the servo angle
  //     angle = constrain(angle, 0, 180);  // Limit the angle to 0-180 degrees
  //     myServo.write(angle);  // Set the servo angle
  //     delay(15);  // Allow the servo to reach the desired position
  //     angle = 0;  // Reset the angle for the next command
  //   } else {
  //     // If not newline, append the character to the angle value
  //     angle = angle * 10 + (c - '0');
  //   }
  // }

  myServo.write(90);
}

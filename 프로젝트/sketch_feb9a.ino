#include <Servo.h>

Servo myServo;
const int SERVO_PIN = 6;
bool servoAt180 = false;

void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(0);      // 시작 0도
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    if (cmd == 't') {
      servoAt180 = !servoAt180;

      if (servoAt180) {
        myServo.write(179);
      } else {
        myServo.write(0);
      }
    }
  }
}

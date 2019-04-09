#include "MyStepper.h"

MyStepper stepper1(2, 3, 4, 5, 2 * M_PI / 4.096);
MyStepper stepper2(6, 7, 8, 9, 2 * M_PI / 4.096);


void setup() {
  Serial.begin(115200);
  stepper1.set_angular_velocity(2 * M_PI / 4.096);
  stepper2.set_angular_velocity(2 * M_PI / 4.096);
  stepper2.set_direction(clockwise);

}

void loop() {
  stepper1.drive();
  stepper2.drive();
}

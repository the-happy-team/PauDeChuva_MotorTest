#include <AccelStepper.h>

// AccelStepper(AccelStepper::DRIVER, stepPin, directionPin);
AccelStepper mStepper(AccelStepper::DRIVER, 4, 3);

int target = 1600;  // half of steps/revolution

void setup() {
  mStepper.setCurrentPosition(0);

  mStepper.setMaxSpeed(1600);        // steps per second
  mStepper.setAcceleration(320000);  // steps per second per second

  mStepper.moveTo(target);
}

// stepper.currentPosition() != TARGET
void loop() {
  if (mStepper.distanceToGo() == 0) {
    target *= -1;
    mStepper.moveTo(target);
  }
  mStepper.run();
}

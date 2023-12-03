// Control the servo direction and speed

void servoControl() {

  // Read the Joystick X position
  joyposHorz = analogRead(joyHorz);

  // convert joystick position data to angle for servo
  motorcontrol[2] = map(joyposHorz, 0, 1023, 72, 94);

  Serial.print(" Servo Motor: ");
  Serial.println(motorcontrol[2]);

}
// Control the servo direction and speed

void servoControl() {

  // Read the Joystick X position
  joyposHorz = analogRead(joyHorz);


  // Determine if this is a left or right motion
  // Do this by reading the Horizontal Value
  // Apply results to Servo speed and to Direction

  if (joyposHorz < 460) {

    motorcontrol[3] = 1;

    //Determine Servo Speed
    motorcontrol[2] = map(joyposHorz, 460, 1023, 90, 180);

    // myServo.write(motorcontrol[2]);

  }
  else if (joyposHorz > 564) 
  {

    motorcontrol[3] = 0;

    //Determine Servo Speed
    motorcontrol[2] = map(joyposHorz, 564, 0, 90, 0);

    // myServo.write(motorcontrol[2]);

  }
    else
  {
    // This is Stopped
    motorcontrol[2] = 90;
    motorcontrol[3] = 0; 
 
  }

  Serial.print(" Servo Motor: ");
  Serial.println(motorcontrol[2]);

}
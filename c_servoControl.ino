void servoControl() {


  // Read the Joystick X position
  joyposHorz = analogRead(joyHorz);


  // Determine if this is a left or right motion
  // Do this by reading the Horizontal Value
  // Apply results to Servo speed and to Direction

  if (joyposHorz < 460) {

    servocontrol[1] = 1;

    //Determine Servo Speed
    servocontrol[0] = map(joyposHorz, 460, 1023, 90, 180);

    myServo.write(servocontrol[0]);

    // Serial.print("Joystick values: ");
    // Serial.print(joyposHorz);
    // Serial.print(" Converted values: ");
    // Serial.println(servocontrol[0]);
  }
  else if (joyposHorz > 564) 
  {
    servocontrol[1] = 0;

    //Determine Servo Speed
    servocontrol[0] = map(joyposHorz, 564, 0, 90, 0);

    myServo.write(servocontrol[0]);

    // Serial.print("Joystick values: ");
    // Serial.print(joyposHorz);
    // Serial.print(" Converted values: ");
    // Serial.println(servocontrol[0]);
  }
    else
  {
    // This is Stopped
    servocontrol[0] = 90;
    servocontrol[1] = 90; 
 
  }

  Serial.print(" Servo Motor: ");
  Serial.println(servocontrol[0]);

}
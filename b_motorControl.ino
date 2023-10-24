// Control the motor direction and speed

void motorControl() {

  // Print to Serial Monitor
  Serial.println("control values ");
  
  // Read the Joystick Y position
  joyposVert = analogRead(joyVert); 
 
  // Determine if this is a forward or backward motion
  // Do this by reading the Verticle Value
  // Apply results to MotorSpeed and to Direction
 
  if (joyposVert < 460)
  {
    // This is Backward
    // Set Motors backward
    motorcontrol[1] = 1;
 
    //Determine Motor Speeds
    // As we are going backwards we need to reverse readings
    motorcontrol[0] = map(joyposVert, 460, 0, 0, 255);
 
  }
  else if (joyposVert > 564)
  {
    // This is Forward
    // Set Motors forward
    motorcontrol[1] = 0;
 
    //Determine Motor Speeds
    motorcontrol[0] = map(joyposVert, 564, 1023, 0, 255);
 
  }
  else
  {
    // This is Stopped
    motorcontrol[0] = 0;
    motorcontrol[1] = 0; 
 
  }
 
  // Adjust to prevent "buzzing" at very low speed
  if (motorcontrol[0] < 25)motorcontrol[0] = 0;

 
  //Display the Motor Control values in the serial monitor.
  Serial.print("Rear Motor: ");
  Serial.print(motorcontrol[0]);

}
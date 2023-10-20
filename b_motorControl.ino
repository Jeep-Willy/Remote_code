void motorControl() {

  // Print to Serial Monitor
  Serial.println("Reading motorcontrol values ");
  
  // Read the Joystick Y position
  joyposVert = analogRead(joyVert); 
 
  // Determine if this is a forward or backward motion
  // Do this by reading the Verticle Value
  // Apply results to MotorSpeed and to Direction
 
  if (joyposVert < 460)
  {
    // This is Backward
    // Set Motors backward
    motorcontrol[2] = 1;
 
    //Determine Motor Speeds
    // As we are going backwards we need to reverse readings
    motorcontrol[0] = map(joyposVert, 460, 0, 0, 255);
 
  }
  else if (joyposVert > 564)
  {
    // This is Forward
    // Set Motors forward
    motorcontrol[2] = 0;
 
    //Determine Motor Speeds
    motorcontrol[0] = map(joyposVert, 564, 1023, 0, 255);
 
  }
  else
  {
    // This is Stopped
    motorcontrol[0] = 0;
    motorcontrol[1] = 0;
    motorcontrol[2] = 0; 
 
  }

  // if (joyposHorz < 511) {
  //   motorcontrol[3] = 1;

  //   motorcontrol[1] = map(joyposHorz, 511, 1023, 90, 180);
  // }
  // else if (joyposHorz > 512) {
  //   motorcontrol[3] = 0;

  //   motorcontrol[1] = map(joyposHorz, 512, 1023, 90, 0)
  // }
  
 
  // Adjust to prevent "buzzing" at very low speed
  if (motorcontrol[0] < 8)motorcontrol[0] = 0;
  // if (motorcontrol[1] < 8)motorcontrol[1] = 0;
 
  //Display the Motor Control values in the serial monitor.
  int yValue = analogRead(joyVert);
  Serial.print("Motor: ");
  Serial.print(yValue);
  Serial.println(motorcontrol[0]);
  // Serial.print(" - Motor B: ");
  // Serial.print(motorcontrol[1]);
  // Serial.print(" - Direction: ");
  // Serial.println(motorcontrol[2]);
  
  //Send a message containing Motor Control data to manager_server
  if (RadioManager.sendtoWait(motorcontrol, sizeof(motorcontrol), SERVER_ADDRESS))
  {
    // Now wait for a reply from the server
    uint8_t len = sizeof(buf);
    uint8_t from;
    if (RadioManager.recvfromAckTimeout(buf, &len, 2000, &from))
    {
      Serial.print("got reply from : 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char*)buf);
    }
    else
    {
      Serial.println("No reply, is nrf24_reliable_datagram_server running?");
    }
  }
  else
    Serial.println("sendtoWait failed");
 
  delay(100);  // Wait a bit before next transmission

}
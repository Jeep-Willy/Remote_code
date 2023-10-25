// Transmition of  joystick data to car

void transmitData() {

  //Send a message containing Motor/Servo Control data to manager_server
  if (RadioManager.sendtoWait(motorcontrol, sizeof(motorcontrol), SERVER_ADDRESS))
  {

    Serial.println("RadioManager ACK RCVD");
    
    // Now wait for a reply from the server
    uint8_t len = sizeof(buf);
    uint8_t from;

    if (RadioManager.recvfromAckTimeout(buf, &len, 1000, &from)) {
      Serial.print(": ");
      Serial.println((char*)buf);
    }
    else {
      Serial.println("No reply, is nrf24_reliable_datagram_server running?");
    }

  }
  else
    Serial.println("sendtoWait failed");
 
  delay(10);  // Wait a bit before next transmission

}
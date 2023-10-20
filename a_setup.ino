void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600);
 
  // Initialize RadioManager with defaults - 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!RadioManager.init())
    Serial.println("init failed");
  
  // Set initial motor direction as forward
  motorcontrol[2] = 0;

  motorcontrol[3] = 0;
 
}
 
void loop()
{

motorControl();
servoControl();

}
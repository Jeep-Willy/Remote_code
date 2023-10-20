  /*
  nRF24L01+ Joystick Transmitter
  nrf24l01-joy-xmit-car.ino
  nRF24L01+ Transmitter with Joystick for Robot Car
  Use with Joystick Receiver for Robot Car
  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/
 
// Include RadioHead ReliableDatagram & NRF24 Libraries
#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
 
// Include dependant SPI Library 
#include <SPI.h>
 
// Define Joystick Connections
#define joyVert    A0 
#define joyHorz    A1
 
// Define Joystick Values - Start at 512 (middle position)
int joyposVert = 512;
int joyposHorz = 512;
 
// Define addresses for radio channels
#define CLIENT_ADDRESS 1   
#define SERVER_ADDRESS 2
 
// Create an instance of the radio driver
RH_NRF24 RadioDriver;
 
// Sets the radio driver to NRF24 and the client address to 1
RHReliableDatagram RadioManager(RadioDriver, CLIENT_ADDRESS);
 
// Declare unsigned 8-bit motorcontrol array
// 2 Bytes for motor speeds plus 1 byte for direction control
uint8_t motorcontrol[4]; 
 
// Define the Message Buffer
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
 
// function setup
void motorControl();
void servoControl();
// Info to come

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
// 1 Bytes for motor speeds plus 1 byte for direction control, 1 byte for servo angle
uint8_t motorcontrol[3]; 
 
// Define the Message Buffer
uint8_t buf[RH_NRF24_MAX_MESSAGE_LEN];
 
// function setup
void motorControl();
void servoControl();
void transmitData();
/*

Prints time stamps for 5 seconds using getXXX functions

Based on DS3231_set.pde
by Eric Ayars
4/11

Added printing back of time stamps and increased baud rate
(to better synchronize computer and RTC)
Andy Wickert
5/15/2011

*/
typedef enum dt
#include <DS3231.h>
#include <Wire.h>
#define DO1 17
#define DO2 16
#define DO3 15
#define DO4 14
#define DO5 4
#define DO6 2
#define DI1 6
#define DI2 7
#define DI3 8
#define DI4 9
#define DI5 10
#define DI6 11
#define DI7 12
#define DI8 13



DS3231 myRTC;

bool century = false;
bool h12Flag;
bool pmFlag;

void setup() {
	// Start the serial port
	Serial.begin(57600);
  pinMode(DO1,OUTPUT);
  pinMode(DO2,OUTPUT);
  pinMode(DO3,OUTPUT);
  pinMode(DO4,OUTPUT);
  pinMode(DO5,OUTPUT);
  pinMode(DO6,OUTPUT);
  pinMode(DI1,INPUT);
  pinMode(DI2,INPUT);
  pinMode(DI3,INPUT);
  pinMode(DI4,INPUT);
  pinMode(DI5,INPUT);
  pinMode(DI6,INPUT);
  pinMode(DI7,INPUT);
  pinMode(DI8,INPUT);

	// Start the I2C interface
	Wire.begin();


  for (int i=0; i<5; i++){
      delay(1000);
      Serial.print(myRTC.getYear(), DEC);
      Serial.print("-");
      Serial.print(myRTC.getMonth(century), DEC);
      Serial.print("-");
      Serial.print(myRTC.getDate(), DEC);
      Serial.print(" ");
      Serial.print(myRTC.getHour(h12Flag, pmFlag), DEC); //24-hr
      Serial.print(":");
      Serial.print(myRTC.getMinute(), DEC);
      Serial.print(":");
      Serial.println(myRTC.getSecond(), DEC);
  }
}
uint8_t setDateTime(uint8_t input, uint8_t index){
  myRTC.setClockMode(false);  // set to 24h
        //setClockMode(true); // set to 12h
        
        myRTC.setYear(year);
        myRTC.setMonth(month);
        myRTC.setDate(date);
        myRTC.setDoW(dOW);
        myRTC.setHour(hour);
        myRTC.setMinute(minute);
        myRTC.setSecond(second);
}
void loop() {

  digitalWrite(DO1,!digitalRead(DI1));
  delay(250);
}

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

typedef enum{
  NONE,
  YY,
  MM,
  DD,
  HH,
  mm,
  SEC,
  DW
}DT_Index;

typedef enum{
  Sun=1,
  Mon,
  Tue,
  Wed,
  Thu,
  Fri,
  Sat
}DW_Index;

char DOW[8][4]={"Err","Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

DT_Index ClockSetState;

bool century = false;
bool h12Flag;
bool pmFlag;
uint8_t SerialCharsIn[64];
uint8_t SerialPtr;
void setup() {
	// Start the serial port
	Serial.begin(115200);
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
}
void printTime(){
    Serial.print(myRTC.getMonth(century), DEC);
    Serial.print("/");
    Serial.print(myRTC.getDate());
    Serial.print("/20");
    Serial.print(myRTC.getYear(), DEC);
    Serial.print(" ");
    Serial.print(DOW[myRTC.getDoW()]);
    Serial.print(" ");
    Serial.print(myRTC.getHour(h12Flag, pmFlag), DEC); //24-hr
    Serial.print(":");
    Serial.print(myRTC.getMinute(), DEC);
    Serial.print(":");
    Serial.println(myRTC.getSecond(), DEC);
}

void parseSerial(){
  if(SerialPtr==1){
    switch(SerialCharsIn[0]){
      case 'x':
          if(ClockSetState==NONE){
            ClockSetState=YY;
            Serial.println("Enter Year(YY): ");
          }else{
            Serial.print(ClockSetState);
            Serial.println(" Date Time Set Cancelled");
            ClockSetState=NONE;
            
          }
        break;
      case 't':
          printTime();
      default:
        break;
    }
  }else if(SerialPtr==2){
    switch(ClockSetState){
      case YY:
            myRTC.setYear(atoi(SerialCharsIn));
            Serial.print("Enter Month(MM): ");
            break;
      case MM:
            myRTC.setMonth(atoi(SerialCharsIn));
            Serial.print("Enter Day(DD): ");
            break;
      case DD:
            myRTC.setDate(atoi(SerialCharsIn));
            Serial.print("Enter Hour(24Hr HH): ");
            break;
      case HH:
            myRTC.setHour(atoi(SerialCharsIn));
            Serial.print("Enter Minute(mm):");
            break;
      case mm:
            myRTC.setMinute(atoi(SerialCharsIn));
            Serial.print("Enter Second(SS):");
            break;
      case SEC:
            myRTC.setSecond(atoi(SerialCharsIn));
            Serial.print("Enter Day Of Week(01-07):");
            break;
      case DW:
            myRTC.setDoW(atoi(SerialCharsIn));
            printTime();
            ClockSetState=0;
            break;
      default:
            return;
            break;
    }
    ClockSetState=ClockSetState+1;
    if(ClockSetState>DW){
      ClockSetState=NONE;
    }
  }else{

  }
}
void checkSerial(){
  uint8_t toBeRead=Serial.available();
  String tempString;
  for(int ii=0;ii<toBeRead;ii++){
    SerialCharsIn[SerialPtr]=Serial.read();
    //Carriage return?
    if(SerialCharsIn[SerialPtr]==0x0D || SerialCharsIn[SerialPtr]==0x0A){
      SerialCharsIn[SerialPtr]=0x00;
      //process input
      tempString=SerialCharsIn;
      Serial.println(tempString);
      parseSerial();
      SerialPtr=0;
      SerialCharsIn[0]=0x00;
    }else{
      SerialPtr++;
    }
    
  }
}
void loop() {
  checkSerial();
  if(!digitalRead(DI1)){
    digitalWrite(DO1,1);
  }
  if(!digitalRead(DI2)){
    digitalWrite(DO2,1);
  }
  if(!digitalRead(DI3)){
    digitalWrite(DO3,1);
  }
  if(!digitalRead(DI4)){
    digitalWrite(DO4,1);
  }
  if(!digitalRead(DI5)){
    digitalWrite(DO5,1);
  }
  if(!digitalRead(DI6)){
    digitalWrite(DO6,1);
  }
  if(!digitalRead(DI8)){
    digitalWrite(DO1,0);
    digitalWrite(DO2,0);
    digitalWrite(DO3,0);
    digitalWrite(DO4,0);
    digitalWrite(DO5,0);
    digitalWrite(DO6,0);
  }
  
  delay(250);
}

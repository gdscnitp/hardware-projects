/*************************************************** 
Coronavirus Doorbell
****************************************************/

 // IR Temp sensor SDA A4 SCL A5 GND 5V
 // 7 Seg Display Clock D12 D9 GND 5V
 // Buzzer GND y D4
 // Button GND y D3
 // MP3 Player GND 5V D10 D11
 
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <TM1637Display.h>
#include "SoftwareSerial.h"

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// Mp3 player rx and tx
SoftwareSerial mySerial(10, 11); 

#define CLK 12 
#define DIO 9  
#define buttonPin 3
#define buzzerPin 4

# define Start_Byte 0x7E
# define Version_Byte 0xFF
# define Command_Length 0x06
# define End_Byte 0xEF
# define Acknowledge 0x00 
# define ACTIVATED LOW

int bodyTemperature=0;
int buttonValue=0;

// adjust sensor 
int adjustTemp=3;

// Creates display object  
TM1637Display display(CLK, DIO);

// All - in display
const uint8_t SEG_START[] = {
          SEG_G,            // -
           SEG_G, // -
          SEG_G,   // -
          SEG_G  // -
          };

void setup() {

  // button
  pinMode(buttonPin,INPUT_PULLUP); 

   // Buzzer
  pinMode(buzzerPin, OUTPUT);
        
  Serial.begin(9600);

  Serial.println("Coronavirus doorbell");  
  

   // mp3 player 
    mySerial.begin(9600);        

    // nothing being played, just init        
    playFirst();  
        
   display.setBrightness(0x0f);
             
   display.setSegments(SEG_START); 

   mlx.begin();    

   delay(1000);

    
}

void loop() {

  // read button
  buttonValue = digitalRead(buttonPin);  
               
  if (buttonValue == LOW) {
    
  beep();
  // button has been pressed
          
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  
  bodyTemperature=mlx.readObjectTempC(); 

  bodyTemperature=bodyTemperature+adjustTemp;

  // send to display
  display.showNumberDec(bodyTemperature, false,4);

  execute_CMD(0x0F,0x01,0x01);
          
  
  if (bodyTemperature>38) {
      Serial.println("High fever");     
      execute_CMD(0x0F,0x01,0x02);      
    }

  Serial.println();

  delay(300);
  
  } // button pressed

   display.setSegments(SEG_START); 
    
}



void beep(){
  tone(buzzerPin, 2000);  
  delay(100);         
  noTone(buzzerPin);         
  }

  void playFirst()
{
  execute_CMD(0x3F, 0, 0); // query device
  delay(500);
  setVolume(25);
  delay(500);

}

void pause()
{
  execute_CMD(0x0E,0,0);
  delay(500);
}

void play()
{
  execute_CMD(0x0D,0,1); 
  delay(500);
}

void playNext()
{
  execute_CMD(0x01,0,1);
  delay(500);
}

void playPrevious()
{
  execute_CMD(0x02,0,1);
  delay(500);
}

void setVolume(int volume)
{
  execute_CMD(0x06, 0, volume); 
  delay(2000);
}

void execute_CMD(byte CMD, byte Par1, byte Par2)
// Excecute the command and parameters
{
// Calculate the checksum (2 bytes)
word checksum = -(Version_Byte + Command_Length + CMD + Acknowledge + Par1 + Par2);
// Build the command line
byte Command_line[10] = { Start_Byte, Version_Byte, Command_Length, CMD, Acknowledge,
Par1, Par2, highByte(checksum), lowByte(checksum), End_Byte};
//Send the command line to the module
for (byte k=0; k<10; k++)
{
mySerial.write( Command_line[k]);
}
}

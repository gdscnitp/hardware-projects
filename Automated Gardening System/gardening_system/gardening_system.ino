const int VAL_PROBE = A0; // Analog pin 0
const int MOISTURE_LEVEL = 850; 
#define BLYNK_PRINT Serial        
#include <ESP8266WiFi.h>        
#include <BlynkSimpleEsp8266.h>        
char auth[] = "_______________"; // PASTE YOUR AUTHENTICATION CODE HERE        
// Your WiFi credentials.        
char ssid[] = "__________"; //WIFI NAME        
char pass[] = "___________"; //PASSWORD   
int in1=D2;
int srma = D5;

 
void setup() {
    Serial.begin(9600);
    pinMode(in1, OUTPUT);
  digitalWrite(in1, LOW);

            
 Blynk.begin(auth, ssid, pass);    
}
 

 
void loop() {
    int moisture = analogRead(VAL_PROBE);
   

    if(moisture>MOISTURE_LEVEL){
      Blynk.virtualWrite(V0 ,moisture );
      digitalWrite(in1, HIGH);
      Blynk.virtualWrite(V2 , "OFF" );
  delay(3000);}
      else{
       Blynk.virtualWrite(V0 ,moisture );
      digitalWrite(in1, LOW);
      digitalWrite(srma, HIGH);
      Blynk.virtualWrite(V2 , "ON" );
      
  delay(3000);
     // }
      }
    
 
    
    
    delay(100);
    Blynk.run();     
}

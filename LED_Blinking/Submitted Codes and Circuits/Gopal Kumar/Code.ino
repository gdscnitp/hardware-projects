void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8,OUTPUT);
}
void loop()
{
  digitalWrite(13, HIGH);
  delay(3000); 
   
  digitalWrite(13, LOW);
  
  digitalWrite(12, HIGH);
  delay(3000);
  
  digitalWrite(12, LOW);
  
  digitalWrite(8, HIGH);
  delay(3000);
  
  digitalWrite(8, LOW);
  
 
 
 
}

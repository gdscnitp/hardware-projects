void setup()
{
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(3000);// 1st led will blink for 3 second
  digitalWrite(13, LOW);
  delay(1000);/* after 1st led stop to blink, 2nd led will start 
  to blink after 1 second*/
  
  digitalWrite(11, HIGH);
  delay(3000);
  digitalWrite(11, LOW);
  delay(1000);
  
  digitalWrite(8, HIGH);
  delay(3000);
  digitalWrite(8, LOW);
  delay(1000);
}
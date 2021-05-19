/*
  This program blinks LED connected at pin 13, 12 and 11 
  alternatively.
*/
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop()
{
  // turn the LED on.
  digitalWrite(13, HIGH);
  delay(30000); // Wait for 30 second(s)
  // turn the LED off.
  digitalWrite(13, LOW);
  // turn the LED on.
  digitalWrite(12, HIGH);
  delay(30000); // Wait for 30 second(s)
  // turn the LED off.
  digitalWrite(12, LOW);
  // turn the LED on.
  digitalWrite(11, HIGH);
  delay(30000); // Wait for 30 second(s)
  // turn the LED off.
  digitalWrite(11, LOW);
}

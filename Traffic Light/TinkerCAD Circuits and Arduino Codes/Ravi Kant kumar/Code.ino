#define red 11
#define green 12
#define blue 13
#define delay_in_between_led 1000 //millisecond

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop()
{
  digitalWrite(red, HIGH);
  delay(delay_in_between_led);
  digitalWrite(red,LOW);
  
  digitalWrite(green, HIGH);
  delay(delay_in_between_led);
  digitalWrite(green,LOW);
  
  digitalWrite(blue, HIGH);
  delay(delay_in_between_led);
  digitalWrite(blue,LOW);
}
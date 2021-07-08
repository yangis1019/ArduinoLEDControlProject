int blue = 0;
int green = 0;
int red = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);//Joystick
  pinMode(9, OUTPUT);//LED RED
  pinMode(10, OUTPUT);//LED GREEN
  pinMode(11, OUTPUT);//LED BLUE
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A0);//Joystick X
  int y = analogRead(A1);//Joystick Y
  int z = digitalRead(8);//Joystick Z
  if(x >= 900) red = red + 1;
  if(x <= 200) red = red - 1;
  if(y >= 900) green = green + 1;
  if(y <= 200) green = green - 1;
  blue = analogRead(A5) / 4;

  if(red >= 256) red = 255;
  if(green >= 256) green = 255;
  if(red < 0) red = 0;
  if(green < 0) green = 0;

  analogWrite(9, red);
  analogWrite(10, green);
  analogWrite(11, blue);
  /*
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  Serial.println("");
  */
  delay(10);
}

// C++ code
//
int output = A0;
int red = 7,blue = 6, green = 5;

void setup()
{
Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  
}

void loop()
{int result = analogRead(output);
 Serial.println(result);
 if(result>=0 && result <= 292){
  Red();
 }
 if(result>292 && result <= 584){
   Yellow();}
 if (result>584 && result <=876){
   Green();
 }
  
}
void Red(){
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
}
void Yellow(){
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
}
void Green(){
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
}
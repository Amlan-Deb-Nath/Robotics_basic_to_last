#include <LiquidCrystal_I2C.h>
#include <Servo.h>

const int lcd_add = 0x27;
const int lcd_column = 16;
const int lcd_row = 2;
int pos = 3;
int trig = 6, echo = 5;
int light = 13 ;

Servo servo_1;

LiquidCrystal_I2C lcd(lcd_add, lcd_column, lcd_row);

int measure_distance(int trig, int echo);

void setup()
{
  Serial.begin(9600);
  servo_1.attach(pos);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(light , OUTPUT);
}

void loop()
{
  int distanceValue = measure_distance(trig, echo);
  Serial.println(distanceValue);
  
  if (distanceValue <= 70)
  {
    digitalWrite(light,HIGH);
    lcd.init();
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Hello Sir");
    delay(2000);  
    
    for (int i = 0; i <= 90; i++)
    {
      move_servo(i);
      delay(50);
    }
  }
  else
  {
    digitalWrite(light,LOW);
    lcd.clear();
    
    for (int i = 90; i >= 0; i--)
    {
      move_servo(i);
      delay(15);
    }
  }
}

int measure_distance(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(5);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  int time = pulseIn(echo, HIGH);
  int distanceValue = 0.0343 * time / 2;

  return distanceValue;
}

void move_servo(int angle)
{
  servo_1.write(angle);
  delay(15);
}

#include <Servo.h>
#include <LiquidCrystal.h> 

const int rs = 30, en = 31, d4 = 25, d5 = 26, d6 = 27, d7 = 28;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int joyX = A0;
const int joyY = A1;
const int button =10;
bool buttonstate;
bool flag=LOW;
int counter;
  
int servoVal_1;
int servoVal_2;
int servoVal_3;
int servoVal_4;
int servoVal_1NEW;
int servoVal_2NEW;
int servoVal_3NEW;
int servoVal_4NEW;
int x;
int y;
int z;
int L1 =3;
int L2 =6;
int L3 =7;

  
void setup() 
{
  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);
  pinMode(button,INPUT_PULLUP);
 // pinMode(joyX,INPUT);
 // pinMode(joyY,INPUT);
  lcd.begin(16,2);
}
  
void loop()
{
  
  buttonstate = digitalRead(button);

if(buttonstate == LOW && flag == LOW){
    counter++; 
    flag=HIGH;
    lcd.clear();
  }
  
  if(buttonstate == HIGH && flag == HIGH){
  flag=LOW;
  }

  if(counter>3){
    counter=0;
  }
  
  if (counter==0){
  servoVal_1 = analogRead(joyX);
  servoVal_1NEW = map(servoVal_1, 0, 1023, 0, 180);
  servo1.write(servoVal_1NEW);

      lcd.setCursor(0,0);
     lcd.print("Θ1:");
     lcd.print(servoVal_1NEW);
     lcd.print("   ");
     lcd.print("   ");
  }
  if (counter==1){
    servoVal_2 = analogRead(joyY);
  servoVal_2NEW = map(servoVal_2, 0, 1023, 0, 90);
  servo2.write(servoVal_2NEW);
 
     lcd.setCursor(10,0);
     lcd.print("Θ2:");
     lcd.print(servoVal_2NEW);
     lcd.print("   ");
  }
 if (counter==2){
  servoVal_3 = analogRead(joyX);
 servoVal_3NEW = map(servoVal_3, 0, 1023, 0, 180);
  servo3.write(servoVal_3NEW); 

   
     lcd.setCursor(0,0);
     lcd.print("Θ3:");
     lcd.print(servoVal_3NEW);
     lcd.print("   ");
     delay(10);
  
  } 
 if (counter==3){
  servoVal_4 = analogRead(joyY);
  servoVal_4NEW = map(servoVal_4, 0, 1023, 0, 90);
  servo4.write(servoVal_4NEW);
     lcd.setCursor(10,0);
     lcd.print("Θ4:");
     lcd.print(servoVal_4NEW);
     lcd.print("   ");
     delay(10);
    x= cos(servoVal_1NEW)*cos(servoVal_2NEW+servoVal_3NEW)*L3+cos(servoVal_1NEW)*cos(servoVal_2NEW)*L2;
    y= sin(servoVal_1NEW)*cos(servoVal_2NEW+servoVal_3NEW)*L3+sin(servoVal_1NEW)*cos(servoVal_2NEW)*L2;
    z= sin(servoVal_2NEW+servoVal_3NEW)*L3+sin(servoVal_2NEW)*L2+L1;
    lcd.setCursor(0,0);
    lcd.print("posx:");
    lcd.print(x);
    lcd.setCursor(0,1);
    lcd.print("posy:");
    lcd.print(y);
    lcd.print("posz:");
    lcd.print(z);
    
 }
     
}

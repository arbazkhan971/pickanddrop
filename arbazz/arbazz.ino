
#include <Servo.h>

Servo myservo;  // create servo object to control a servo


#include <SoftwareSerial.h>
SoftwareSerial EEBlue(2,3);



const int m1p1=4;
const int m1p2=5;
const int m2p1=6;
const int m2p2=7;
const int p1=9;
const int p2=10;
const int s1=195;
const int s2=250;


char a;
 int pos = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(m1p1,OUTPUT);
pinMode(m1p2,OUTPUT);
pinMode(m2p1,OUTPUT);
pinMode(m2p2,OUTPUT);
pinMode(p1,OUTPUT);
pinMode(p2,OUTPUT);
analogWrite(p1,s1);
analogWrite(p2,s2);
myservo.attach(11);
Serial.begin(9600);
EEBlue.begin(9600);
}
void fwd(){
digitalWrite(m1p1,1);
digitalWrite(m1p2,0);
digitalWrite(m2p1,0);
digitalWrite(m2p2,1);
delay(100);
}


void stp(){
digitalWrite(m1p1,0);
digitalWrite(m1p2,0);
digitalWrite(m2p1,0);
digitalWrite(m2p2,0);
delay(100);
}
void rev(){
digitalWrite(m1p1,0);
digitalWrite(m1p2,1);
digitalWrite(m2p1,1);
digitalWrite(m2p2,0);
delay(100);
}


void right(){
digitalWrite(m1p1,1);
digitalWrite(m1p2,0);
digitalWrite(m2p1,1);
digitalWrite(m2p2,0);
delay(100);
}

void left(){
digitalWrite(m1p1,0);
digitalWrite(m1p2,1);
digitalWrite(m2p1,0);
digitalWrite(m2p2,1);
delay(100);
}


void pick(){
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5
    );                       // waits 15ms for the servo to reach the position
  }
 
}

void drop(){
  
 for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }

}








void loop() {
  // put your main code here, to run repeatedly:
 if(EEBlue.available()>0)
  {
   a= EEBlue.read();
   Serial.print(a);
    
  delay(10);}


   if(Serial.available()){
  
    a= Serial.read();
  Serial.println(a);
  
    delay(10);
 }
 
   switch(a)
   {
    case'F': 
     
    fwd();
    Serial.print("\r\nforward");
   break;
   case 'N': 
    right();
    Serial.print("\r\nright");
    break;
   
  case 'M': 
    left();
    Serial.print("\r\nleft");
    break;
    
   case 'n':
    stp();
    Serial.print("\r\nstop");
    break;

  case 'R':
    rev();
    Serial.print("\r\nreverse");
    break;


  case 'P':
    pick();
    Serial.print("\r\npick");
    break;

  case 'D':
    drop();
    Serial.print("\r\ndrop");
    break;




}
a=0
}




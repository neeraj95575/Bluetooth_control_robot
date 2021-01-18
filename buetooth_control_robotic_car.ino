#include<AFMotor.h>

 AF_DCMotor motor1(1,MOTOR12_64KHZ);
 AF_DCMotor motor2(2,MOTOR12_64KHZ);
 AF_DCMotor motor3(3,MOTOR12_1KHZ);
 AF_DCMotor motor4(4,MOTOR12_1KHZ);



void setup()  
{
  Serial.begin(9600);           
  Serial.println("CAR READY");
  motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

void loop()
{
  if(Serial.available()>0)
    {  
     int incomingByte=Serial.read();
        
     if(incomingByte=='F')
       {
       motor1.run(FORWARD);
       motor2.run(FORWARD);
       Serial.println("GOING FORWARD");
       }
              
     if(incomingByte=='B')
       {
        Serial.println("GOING BACKWARD");
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
     } 
     
     if(incomingByte=='R')
       { 
         Serial.println("MOVING LEFT");
         motor1.run(FORWARD);
         motor2.run(BACKWARD);
       }         
       
     if(incomingByte=='L')
       { 
         Serial.println("MOVING RIGHT");
         motor1.run(BACKWARD);
         motor2.run(FORWARD);
       }
      
     if(incomingByte=='S')
       {
         Serial.println("CAR STOPED");
         motor1.run(RELEASE);
         motor2.run(RELEASE);
       }

     if(incomingByte=='A')
       {
         Serial.println("NECK UP");
         motor3.run(FORWARD);
        
       }

     if(incomingByte=='T')
       {
         Serial.println("NECK DOWN");
         motor3.run(BACKWARD);
       }

     if(incomingByte=='C')
       {
         Serial.println("CLAMP CLOSE");
         motor4.run(FORWARD);
       }

     if(incomingByte=='D')
       {
         Serial.println("CLAMP OPEN");
         motor4.run(BACKWARD);
       }

     if(incomingByte=='Z')                                                                                                   
       {
         Serial.println("NECK AND NECK RELEASE");
         motor3.run(RELEASE);
         motor4.run(RELEASE);
       }
    
    }

}

//by soumya srivastava
//Hand Gesture Controlled Bot
//Reciever Code
#include <Servo.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte add[6] = "00001";
int msg[5];
int s1=0;
int s2=0;
int s3=0;
int s4=0;
int s5=0;
Servo sm1,sm2,sm3,sm4,sm5;
int angle=0;

void setup() {
  //serial communication begins
  Serial.begin(9600);
  //start the radio communication
  radio.begin();
  radio.openReadingPipe(0, add);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
  //Attaching the servo motors to pins of arduino
  sm1.attach(A0);
  sm2.attach(A1);
  sm3.attach(A2);
  sm4.attach(A3);
  sm5.attach(A4);
  
  
}

void loop() {

    
 // sm1.write(0);
  
  //starting the radio communication
  if (radio.available()) {

    radio.read(&msg,sizeof(msg));
    
    
    //storing the incoming mapped angles from the transmitter into 5 variables
    s1=msg[0];
    s2=msg[1];
    s3=msg[2];
    s4=msg[3];
    s5=msg[4];
    
   
   //Writing the mapped angle values in the servo motors
    sm1.write(s1);
    sm2.write(s2);
    sm3.write(s3);
    sm4.write(s4);
    sm5.write(s5);
    
 
  //code for checking the rotation of servo motors
  
  /*for(angle=0; angle <180; ++angle) 
 { 
 sm1.write(angle); 
 delay(5); 
 sm2.write(angle); 
 delay(5); 
 sm3.write(angle); 
 delay(5);
 sm4.write(angle); 
 delay(5);
 sm5.write(angle); 
 delay(5); 
 }
for(angle=180; angle >0; --angle)
 {
 sm1.write(angle); 
 delay(5); 
 sm2.write(angle); 
 delay(5); 
sm3.write(angle); 
 delay(5); 
 sm4.write(angle); 
 delay(5);
 sm5.write(angle); 
 delay(5);  
 }*/
    

  }
    
}


//By soumya Srivastava
//Hand gesture controlled bionic arm
//Transmitter code

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte add[6] = "00001";

const int f1=A0;
const int f2=A1;
const int f3=A2;
const int f4=A3;
const int f5=A4;

int msg[5];

int flex1,flex2,flex3,flex4,flex5;


void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(add);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  
}

void loop() {
 

    
  flex1=analogRead(f1);
  
  flex2=analogRead(f2);
  flex3=analogRead(f3);
  flex4=analogRead(f4);
  flex5=analogRead(f5);
  
  //Serial.println(flex2);
msg[0]= map(flex1, 795,930,0,180); //first finger
  
 
msg[1] = map(flex2, 750, 865,180,0); //second finger
msg[2] = map(flex3, 752, 870,180, 0);// third finger
msg[3]= map(flex4, 743, 760,180, 0); //fourth finger

//radio.write(&msg,sizeof(msg));//second finger
 // Serial.print(":");
//Serial.print(msg[1]);
  //map(flexValue, 785, 850,0, 180);*/

//thumb 
msg[4] = map(flex5, 945, 965,180, 0);
//Serial.println(msg[0]);//thumb*/

//radio.write(&msg,sizeof(msg));
Serial.println(msg[3]);


}

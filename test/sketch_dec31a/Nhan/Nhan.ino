#include <SPI.h>
#include "RF24.h"
 
const uint64_t pipe = 0xE8E8F0F0E1LL; // địa chỉ phát
RF24 radio(9,10);//thay 10 thành 53 với mega
byte msg[3];
const int led = 4;
int led_st = 0;
 
void setup(){
  Serial.begin(9600);
  radio.begin();                     
  radio.setAutoAck(1);              
  radio.setDataRate(RF24_1MBPS);    // Tốc độ dữ liệu
  radio.setChannel(10);               // Đặt kênh
  radio.openReadingPipe(1,pipe);     
  radio.startListening();            
  pinMode(3, OUTPUT);
  pinMode(2, INPUT_PULLUP); // sử dụng điện trở kéo lên cho chân số 2, ngắt 0
  attachInterrupt(0, Truyen, RISING);
}


void loop(){
  if (radio.available()){
    while (radio.available()){
      radio.read(&msg, sizeof(msg));
      Serial.println(msg[0]);
      //analogWrite(led, msg[0]);
    }
  }
}

void Truyen ()
{
  Serial.println("ngat");
 digitalWrite(3,HIGH);
 radio.stopListening();
  radio.openWritingPipe(pipe);        // mở kênh
 
   radio.setRetries(1,1);      
    radio.setPALevel(RF24_PA_MAX);      // Dung lượng tối đa
  msg[0] = 22;
  radio.write(&msg, sizeof(msg));
//  msg[0] = value / 4;
//  radio.write(&msg, sizeof(msg));
radio.openReadingPipe(1,pipe); 
radio.startListening();     
 Serial.println("done");
//delay(500);
  digitalWrite(3,LOW);
  
}

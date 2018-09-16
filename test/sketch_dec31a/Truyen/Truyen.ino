#include <SPI.h>
#include "RF24.h"
 
const uint64_t pipe = 0xE8E8F0F0E1LL; // địa chỉ để phát
RF24 radio(9,10); //thay 10 thành 53 với mega
byte msg;
int mode;


void setup()
{ 
  //============================================================Module NRF2
  radio.begin();     
  radio.setAutoAck(1);               
  radio.setRetries(1,1);             
  radio.setDataRate(RF24_1MBPS);    // Tốc độ truyền
  radio.setPALevel(RF24_PA_MAX);      // Dung lượng tối đa
  radio.setChannel(10);               // Đặt kênh
  radio.openWritingPipe(pipe);        // mở kênh
  //===========================================================
  mode=0;
  
  pinMode(8,OUTPUT);
  pinMode(4,INPUT);
  
  attachInterrupt(0, ngat0, FALLING);
  attachInterrupt(1, ngat1, FALLING);
  
 
  Serial.begin(9600);
    
}

void ngat0()
{
  digitalWrite(8,HIGH);
  delay(500);
  digitalWrite(8,LOW);
}

void ngat1()
{
  mode=mode+1;
  if (mode==5) mode=0;
}

void ModeXemanni()
{
}

void 
void ModeCaithoigian()
{
  int a=0;
      Serial.println("cai gio");
      while(a<10)
      {   
      if (digitalRead(4)==LOW)
      Serial.println("Tha");
      else
      {
      Serial.println("Nhan");
      a++;
      Serial.println(a);
      }
      delay(200);
      }
}


void loop(){
  msg[0] = 55;
  radio.write(&msg, sizeof(msg));
  delay(1000);
  Serial.println(mode);
 
  switch(mode)
  {
    case 1:
    {
      Serial.println("anni");
      break;
    }
    case 2:
    {
      Serial.println("pomoto");
      break;
    }
    case 3:
    {
     Serial.println("Pecha");
     
      break;
    }
    case 4:
    {
      Serial.println("Bao thuc");
      break;
    }
    case 5:
    {
      Serial.println("Caithoigian");
      break;
    }
  }

}

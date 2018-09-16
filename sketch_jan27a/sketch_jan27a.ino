#include <Wire.h>
#include <GOFi2cOLED.h>
#include <avr/pgmspace.h>

#define LED 8
#define BEEP  6
#define RUNG  A0

uint16_t Anni;
uint8_t mode;
uint8_t on=0;

uint8_t hBaothuc;
uint8_t mBaothuc;

uint8_t ChoPhepSuaPhut;
uint8_t ChoPhepBaoThuc;

uint8_t BamGio;
uint8_t mBamGio;
uint8_t sBamGio;

uint8_t Pomo;
uint8_t ePomo;
uint8_t mPomo;

uint8_t ePecha;
uint8_t nPecha;
uint8_t sPecha;

uint8_t m0,m1,m2,m3,m4,m5;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Địa chỉ của DS1307 */
const byte DS1307 = 0x68;
/* Số byte dữ liệu sẽ đọc từ DS1307 */
const byte NumberOfFields = 7;
 
/* khai báo các biến thời gian */
int second, minute, hour, day, wday, month, year;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
GOFi2cOLED twoYrs;

const unsigned char PROGMEM Dot[] =
{
  0xff,0xff,0xff,0xff
};

const unsigned char PROGMEM ThanhDoc[] =
{
  0xff,
  0xff,
  0xff,
  0xff,
  0xff,
  0xff,
  0xff,
  0xff
};


const unsigned char PROGMEM ThanhNgang[] =
{
  0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,
};

void BlinkDot(uint8_t x)
{
  twoYrs.drawBitmap(x+0, 10,Dot, 4, 8 , WHITE);  
  twoYrs.drawBitmap(x+0, 46,Dot, 4, 8 , WHITE);  
}


void n0(int x)
{
  twoYrs.drawBitmap(x+0, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+0, 30,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+0, 0,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 60,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+14, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+14, 30,ThanhDoc, 2, 32 , WHITE); 

  twoYrs.fillRect(x+0, 1, 1, 1, BLACK);
  twoYrs.fillRect(x+17, 1, 1, 1, BLACK);
  twoYrs.fillRect(x+0, 63, 1, 1, BLACK);
  twoYrs.fillRect(x+17, 63, 1, 1, BLACK);
}

void n1(int x)
{
  twoYrs.drawBitmap(x+14, 0,ThanhDoc, 2, 32 , WHITE); 
  twoYrs.drawBitmap(x+14, 32,ThanhDoc, 2, 32 , WHITE);  
}

void n2(int x)
{
  twoYrs.drawBitmap(x+14, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+0, 32,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+0, 60,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 30,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 0,ThanhNgang, 16, 4 , WHITE);  
}

void n3(int x)
{
  twoYrs.drawBitmap(x+14, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+14, 32,ThanhDoc, 2, 32 , WHITE);  

  twoYrs.drawBitmap(x+0, 60,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 30,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 0,ThanhNgang, 16, 4 , WHITE);  
}

void n4(int x)
{
  twoYrs.drawBitmap(x+0, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+14, 0,ThanhDoc, 2, 32 , WHITE); 
  twoYrs.drawBitmap(x+14, 30,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+0, 30,ThanhNgang, 16, 4 , WHITE);  
}

void n5(int x)
{
  twoYrs.drawBitmap(x+0, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+14, 30,ThanhDoc, 2, 32 , WHITE);  
  
  twoYrs.drawBitmap(x+0, 60,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 30,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 0,ThanhNgang, 16, 4 , WHITE);  
}

void n6(int x)
{
  twoYrs.drawBitmap(x+14, 30,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+0, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+0, 30,ThanhDoc, 2, 32 , WHITE);    
  twoYrs.drawBitmap(x+0, 60,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 30,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 0,ThanhNgang, 16, 4 , WHITE);  
}

void n7(int x)
{
  twoYrs.drawBitmap(x+0, 0,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+14, 0,ThanhDoc, 2, 32 , WHITE); 
  twoYrs.drawBitmap(x+14, 32,ThanhDoc, 2, 32 , WHITE);  
}

void n8(int x)
{
  twoYrs.drawBitmap(x+0, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+0, 30,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+0, 0,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 60,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 30,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+14, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+14, 30,ThanhDoc, 2, 32 , WHITE); 
}

void n9(int x)
{
  twoYrs.drawBitmap(x+0, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+0, 0,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 60,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+0, 30,ThanhNgang, 16, 4 , WHITE);  
  twoYrs.drawBitmap(x+14, 0,ThanhDoc, 2, 32 , WHITE);  
  twoYrs.drawBitmap(x+14, 30,ThanhDoc, 2, 32 , WHITE); 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void readDS1307()
{
        Wire.beginTransmission(DS1307);
        Wire.write((byte)0x00);
        Wire.endTransmission();
        Wire.requestFrom(DS1307, NumberOfFields);
        
        second = bcd2dec(Wire.read() & 0x7f);
        minute = bcd2dec(Wire.read() );
        hour   = bcd2dec(Wire.read() & 0x3f); // chế độ 24h.
        wday   = bcd2dec(Wire.read() );
        day    = bcd2dec(Wire.read() );
        month  = bcd2dec(Wire.read() );
        year   = bcd2dec(Wire.read() );
        year += 2000;    
}
/* Chuyển từ format BCD (Binary-Coded Decimal) sang Decimal */
int bcd2dec(byte num)
{
        return ((num/16 * 10) + (num % 16));
}
/* Chuyển từ Decimal sang BCD */
int dec2bcd(byte num)
{
        return ((num/10 * 16) + (num % 10));
}
 
void digitalClockDisplay(){
    // digital clock display of the time
    Serial.print(hour);
    printDigits(minute);
    printDigits(second);
    Serial.print(" ");
    Serial.print(day);
    Serial.print(" ");
    Serial.print(month);
    Serial.print(" ");
    Serial.print(year); 
    Serial.println(); 
}
 
void printDigits(int digits){
    // các thành phần thời gian được ngăn chách bằng dấu :
    Serial.print(":");
        
    if(digits < 10)
        Serial.print('0');
    Serial.print(digits);
}
 
/* cài đặt thời gian cho DS1307 */
void setTime(byte hr, byte min, byte sec, byte wd, byte d, byte mth, byte yr)
{
        Wire.beginTransmission(DS1307);
        Wire.write(byte(0x00)); // đặt lại pointer
        Wire.write(dec2bcd(sec));
        Wire.write(dec2bcd(min));
        Wire.write(dec2bcd(hr));
        Wire.write(dec2bcd(wd)); // day of week: Sunday = 1, Saturday = 7
        Wire.write(dec2bcd(d)); 
        Wire.write(dec2bcd(mth));
        Wire.write(dec2bcd(yr));
        Wire.endTransmission();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ChuyenMode()
{
  mode=mode+1;
  
    if(mode==6)
  {
  mode=0;
  }
  
  digitalWrite(LED,LOW);
  delay(1000);
  digitalWrite(LED,HIGH);
  Serial.println(mode);

  m0=0;
  m1=0;
  m2=0;
  m3=0;
  m4=0;
  m5=0;
}

void nRF()
{
  on=1;
}

void XemAnni()
{
  uint8_t hAnni=Anni/100;
  uint8_t mAnni=(Anni-((Anni/100)*100))/10;
  uint8_t lAnni=Anni%10;
  
  switch(hAnni)
  {
    case 0:
    {
      n0(30);
      break;
    }
    case 1:
    {
      n1(30);
      break;
    }
    case 2:
    {
      n2(30);
      break;
    }
    case 3:
    {
      n3(30);
      break;
    }
    case 4:
    {
      n4(30);
      break;
    }
    case 5:
    {
      n5(30);
      break;
    }
    case 6:
    {
      n6(30);
      break;
    }
    case 7:
    {
      n7(30);
      break;
    }
    case 8:
    {
      n8(30);
      break;
    }
    case 9:
    {
      n9(30);
      break;
    }
  }

  switch(mAnni)
  {
    case 0:
    {
      n0(50);
      break;
    }
    case 1:
    {
      n1(50);
      break;
    }
    case 2:
    {
      n2(50);
      break;
    }
    case 3:
    {
      n3(50);
      break;
    }
    case 4:
    {
      n4(50);
      break;
    }
    case 5:
    {
      n5(50);
      break;
    }
    case 6:
    {
      n6(50);
      break;
    }
    case 7:
    {
      n7(50);
      break;
    }
    case 8:
    {
      n8(50);
      break;
    }
    case 9:
    {
      n9(50);
      break;
    }
  }

  switch(lAnni)
  {
    case 0:
    {
      n0(70);
      break;
    }
    case 1:
    {
      n1(70);
      break;
    }
    case 2:
    {
      n2(70);
      break;
    }
    case 3:
    {
      n3(70);
      break;
    }
    case 4:
    {
      n4(70);
      break;
    }
    case 5:
    {
      n5(70);
      break;
    }
    case 6:
    {
      n6(70);
      break;
    }
    case 7:
    {
      n7(70);
      break;
    }
    case 8:
    {
      n8(70);
      break;
    }
    case 9:
    {
      n9(70);
      break;
    }
  }

  twoYrs.display();
}

void Xem(int x)
{
  switch(x/10)
  {
    case 0:
    {
      n0(45);
      break;
    }
    case 1:
    {
      n1(45);
      break;
    }
    case 2:
    {
      n2(45);
      break;
    }
    case 3:
    {
      n3(45);
      break;
    }
    case 4:
    {
      n4(45);
      break;
    }
    case 5:
    {
      n5(45);
      break;
    }
    case 6:
    {
      n6(45);
      break;
    }
    case 7:
    {
      n7(45);
      break;
    }
    case 8:
    {
      n8(45);
      break;
    }
    case 9:
    {
      n9(45);
      break;
    }
  }

switch(x%10)
  {
    case 0:
    {
      n0(65);
      break;
    }
    case 1:
    {
      n1(65);
      break;
    }
    case 2:
    {
      n2(65);
      break;
    }
    case 3:
    {
      n3(65);
      break;
    }
    case 4:
    {
      n4(65);
      break;
    }
    case 5:
    {
      n5(65);
      break;
    }
    case 6:
    {
      n6(65);
      break;
    }
    case 7:
    {
      n7(65);
      break;
    }
    case 8:
    {
      n8(65);
      break;
    }
    case 9:
    {
      n9(65);
      break;
    }
  }
  twoYrs.display();
}

void XemGio(int h, int m)
{
  twoYrs.clearDisplay();
  readDS1307();
  //int second, minute, hour, day, wday, month, year;
  
  uint8_t phHour=h/10;
  uint8_t plHour=h%10;

  int phMinute=m/10;
  int plMinute=m%10;
  
  switch(phHour)
  {
    case 0:
    {
      n0(10);
      break;
    }
    case 1:
    {
      n1(10);
      break;
    }
    case 2:
    {
      n2(10);
      break;
    }
    case 3:
    {
      n3(10);
      break;
    }
    case 4:
    {
      n4(10);
      break;
    }
    case 5:
    {
      n5(10);
      break;
    }
    case 6:
    {
      n6(10);
      break;
    }
    case 7:
    {
      n7(10);
      break;
    }
    case 8:
    {
      n8(10);
      break;
    }
    case 9:
    {
      n9(10);
      break;
    }
  }

 switch(plHour)
  {
    case 0:
    {
      n0(30);
      break;
    }
    case 1:
    {
      n1(30);
      break;
    }
    case 2:
    {
      n2(30);
      break;
    }
    case 3:
    {
      n3(30);
      break;
    }
    case 4:
    {
      n4(30);
      break;
    }
    case 5:
    {
      n5(30);
      break;
    }
    case 6:
    {
      n6(30);
      break;
    }
    case 7:
    {
      n7(30);
      break;
    }
    case 8:
    {
      n8(30);
      break;
    }
    case 9:
    {
      n9(30);
      break;
    }
  }

  BlinkDot(60);

  switch(phMinute)
  {
    case 0:
    {
      n0(80);
      break;
    }
    case 1:
    {
      n1(80);
      break;
    }
    case 2:
    {
      n2(80);
      break;
    }
    case 3:
    {
      n3(80);
      break;
    }
    case 4:
    {
      n4(80);
      break;
    }
    case 5:
    {
      n5(80);
      break;
    }
    case 6:
    {
      n6(80);
      break;
    }
    case 7:
    {
      n7(80);
      break;
    }
    case 8:
    {
      n8(80);
      break;
    }
    case 9:
    {
      n9(80);
      break;
    }
  }

  
    switch(plMinute)
  {
    case 0:
    {
      n0(100);
      break;
    }
    case 1:
    {
      n1(100);
      break;
    }
    case 2:
    {
      n2(100);
      break;
    }
    case 3:
    {
      n3(100);
      break;
    }
    case 4:
    {
      n4(100);
      break;
    }
    case 5:
    {
      n5(100);
      break;
    }
    case 6:
    {
      n6(100);
      break;
    }
    case 7:
    {
      n7(100);
      break;
    }
    case 8:
    {
      n8(100);
      break;
    }
    case 9:
    {
      n9(100);
      break;
    }
  }


  twoYrs.display();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


void setup()   
{           

  mode=0;
  Anni = 715;

  ChoPhepSuaPhut=0;
  ChoPhepBaoThuc=0;
  hBaothuc =0;
  mBaothuc =0;
  BamGio = 0;
  mBamGio = 0;
  sBamGio = 0;

  Pomo=0;
  ePomo=0;
  mPomo=0;

  ePecha=0;
  sPecha=0;
  nPecha=0;
  m0=0;
  m1=0;
  m2=0;
  m3=0;
  m4=0;
  m5=0;
  
  ///////////////////////////////////////////////////////
  pinMode(3,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  
  pinMode(LED, OUTPUT);
  pinMode(BEEP, OUTPUT);
  pinMode(RUNG, OUTPUT);

  digitalWrite(LED,HIGH);
  digitalWrite(BEEP,HIGH);
  digitalWrite(RUNG,HIGH);

  attachInterrupt(0, nRF, FALLING);
  attachInterrupt(1, ChuyenMode, FALLING);
  ///////////////////////////////////////////////////////

  
  ///////////////////////////////////////////////////////       
  twoYrs.init(0x3c);  
  twoYrs.clearDisplay();
  
  ///////////////////////////////////////////////////////


  ///////////////////////////////////////////////////////
   Wire.begin();
  /* cài đặt thời gian cho module */
  //setTime(12, 30, 45, 1, 8, 2, 15); // 12:30:45 CN 08-02-2015
  //setTime(23, 53, 00, 4, 21, 2, 18); // 12:30:45 CN 08-02-2
  Serial.begin(9600);
  ///////////////////////////////////////////////////////

  
}

void loop() 
{
//////////////////////////////////////////////////////////////////////////////////////
  readDS1307();



  
  if (on==1)
  {
   readDS1307();
   digitalClockDisplay();
   XemGio(hour,minute);
   delay(2000);
   twoYrs.clearDisplay();
   twoYrs.display();
   on=0;   
  }
 
  if(hour==hBaothuc && minute==mBaothuc)
  {
    while(ChoPhepBaoThuc==1)
    {
    digitalWrite(BEEP,LOW);
    delay(250);
    digitalWrite(BEEP,HIGH);
    delay(250);
     if(digitalRead(4)==0)
    {
    ChoPhepBaoThuc=0;
    hBaothuc=0;
    mBaothuc=0;
    }
    }
  }
  
  if( hour==0 && minute==0 && second==0)
  {
    Anni=Anni+1;
    delay(1000);
  }

  switch(mode)
  {
    case 0:
    {
      if (m0==0)
      {
        twoYrs.clearDisplay();
        n0(50);
        twoYrs.display();
        delay(500);
        twoYrs.clearDisplay();
        twoYrs.display();
      }
      m0=1;
      break;
    }

    case 1:
    {
     if (m1==0)
      {
        twoYrs.clearDisplay();
        n1(50);
        twoYrs.display();
        delay(500);
        twoYrs.clearDisplay();
        twoYrs.display();
      }
      m1=1;
      XemAnni();
      break;
    }

    case 2:
    {
     if (m2==0)
      {
        twoYrs.clearDisplay();
        n2(50);
        twoYrs.display();
        delay(500);
        twoYrs.clearDisplay();
        twoYrs.display();
      }
      m2=1;

    if(ChoPhepSuaPhut == 0)
    {
      
      if(digitalRead(5) == 0 )
        {
          hBaothuc=hBaothuc+1;
          if (hBaothuc>23)
          {
          hBaothuc=0;
          }  
         }
       if(digitalRead(7) == 0 )
        {
          hBaothuc=hBaothuc-1;
          if (hBaothuc>23)
          {
          hBaothuc=0;
          }
         }

      if(digitalRead(4) == 0 )
        {
           digitalWrite(BEEP,LOW);
           delay(100);
           digitalWrite(BEEP,HIGH);
           ChoPhepSuaPhut=1;
           delay(500);
         }
    }

    if(ChoPhepSuaPhut ==1)
    {
      if(digitalRead(5) == 0 )
        {
          mBaothuc=mBaothuc+1;
          if (mBaothuc>59)
          {
          mBaothuc=0;
          }
         }
       if(digitalRead(7) == 0 )
        {
          mBaothuc=mBaothuc-1;
          if (mBaothuc>59)
          {
            mBaothuc=0;
          }
         }

      if(digitalRead(4) == 0 )
        {
          digitalWrite(BEEP,LOW);
           delay(250);
           digitalWrite(BEEP,HIGH);  
           delay(500);       
           ChoPhepSuaPhut=0;
           ChoPhepBaoThuc=1;
           mode=0;
         }
   }

      if (ChoPhepBaoThuc==1 && digitalRead(5)==0 && digitalRead(7)==0)
      {
        delay(1000);
        if( digitalRead(5)==0 && digitalRead(7)==0)
        {
          digitalWrite(BEEP,LOW);
          delay(500);
          digitalWrite(BEEP,HIGH);
          delay(500);       
          ChoPhepBaoThuc=0;
          hBaothuc=0;
          mBaothuc=0;
        }
      }

      
      XemGio(hBaothuc,mBaothuc);
      break;
    }
    case 3:
    {
      if (m3==0)
      {
        twoYrs.clearDisplay();
        n3(50);
        twoYrs.display();
        delay(500);
        twoYrs.clearDisplay();
        twoYrs.display();
      }
      m3=1;
      
      XemGio(mBamGio,sBamGio);
      twoYrs.display();
      if(digitalRead(4) == 0 && BamGio ==0 )
      {
        digitalWrite(BEEP,LOW);
        delay(100);
        digitalWrite(BEEP,HIGH);
        BamGio=1;
        readDS1307();
        sBamGio=second;
        delay(500);
      }

       while(BamGio==1)
      {
        readDS1307();
        if(second-sBamGio >=0)
        {
          XemGio(mBamGio,second-sBamGio);
        }
        else
        {
          XemGio(mBamGio,60+second-sBamGio);
        }
       
        if(sBamGio==60)
        {
          sBamGio=0;
          mBamGio=mBamGio+1;
          
        }
        if (digitalRead(4) == 0 && BamGio==1)
        {
        digitalWrite(BEEP,LOW);
        delay(100);
        digitalWrite(BEEP,HIGH);
        delay(2000);
          BamGio=0;
          mBamGio=0;
          sBamGio=0;
          //break;
        }
      }
     
      break;
    }
    case 4:
    {
      if (m4==0)
      {
        twoYrs.clearDisplay();
        n4(50);
        twoYrs.display();
        delay(500);
        twoYrs.clearDisplay();
        twoYrs.display();
      }
      m4=1;

      if(digitalRead(4) == 0)
      {
        digitalWrite(BEEP,LOW);
        delay(100);
        digitalWrite(BEEP,HIGH);
        delay(500);
        
        ePomo=1;
        readDS1307();
        mPomo=minute;
      }

      while(ePomo==1)
      {
        readDS1307();
        if(minute-mPomo >=0)
        {
          Xem(minute-mPomo);
          if (minute-mPomo >=26) 
          {
            
            digitalWrite(BEEP,LOW);
            delay(100);
            digitalWrite(BEEP,HIGH);
            delay(1000);
            ePomo=0;
            mPomo=0;
          }
        }
        else
        {
          Xem(60-mPomo+minute);
          if (60-mPomo+minute >=26) 
          {
            digitalWrite(BEEP,LOW);
            delay(100);
            digitalWrite(BEEP,HIGH);
            delay(1000);
            ePomo=0;
            mPomo=0;
          }
        }

      if (digitalRead(4)==0) 
          {
            digitalWrite(BEEP,LOW);
            delay(100);
            digitalWrite(BEEP,HIGH);
            delay(1000);
            ePomo=0;
            mPomo=0;
          }
        twoYrs.clearDisplay();
      }

     
      twoYrs.clearDisplay();
      break;
    }
    case 5:
    {
//      twoYrs.clearDisplay();
//      
//      if (m5==0)
//      {
//        twoYrs.clearDisplay();
//        n5(50);
//        twoYrs.display();
//        delay(500);
//        twoYrs.clearDisplay();
//        twoYrs.display();
//      }
//      m5=1;
//
//      Xem(nPecha);
//      
//      if(digitalRead(5) == 0 )
//        {
//          nPecha=nPecha+1;
//          if(nPecha>20)
//          {
//            nPecha=0;
//          }
//        }
//       if(digitalRead(7) == 0 )
//        {
//          nPecha=nPecha-1;
//         if(nPecha>20)
//          {
//            nPecha=0;
//          }
//         }
//
//        if(digitalRead(4)==0 && ePecha==0)
//        {
//          digitalWrite(BEEP,LOW);
//          delay(100);
//          digitalWrite(BEEP,HIGH);
//          ePecha==1
//          readDS1307()
//          sPecha=second;
//        }
//
//      while(ePecha==1)
//      {
//        readDS1307();
//        if(second-sPecha>0)
//        Xem(second-sPecha);
//        else
//        Xem(60-sPecha+second);
//
//        if(digitalRead(4)==0)
//        {
//          digitalWrite(BEEP,LOW);
//          delay(100);
//          digitalWrite(BEEP,HIGH);
//          ePecha=0;
//          nPecha=0;
//          sPecha=0;
//        }
// 
//        
//      }
//      
//      break;
    }
  }
  twoYrs.display();

  delay(500);

  
//////////////////////////////////////////////////////////////////////////////////////
}


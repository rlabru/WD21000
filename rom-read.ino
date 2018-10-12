
#define A0 38
#define A1 36
#define A2 34
#define A3 32
#define A4 30
#define A5 28
#define A6 26
#define A7 24
#define A8 22
#define A9 23
#define A10 25
#define A11 27
#define A12 29
#define A13 31
#define A14 33

#define D0 42
#define D1 44
#define D2 46
#define D3 48
#define D4 50
#define D5 52
#define D6 53
#define D7 51
#define D8 49
#define D9 47
#define D10 45
#define D11 43
#define D12 41
#define D13 39
#define D14 37
#define D15 35

#define OE 40

struct DATARAW
{
  byte b0 : 1;
  byte b1 : 1;
  byte b2 : 1;
  byte b3 : 1;
  byte b4 : 1;
  byte b5 : 1;
  byte b6 : 1;
  byte b7 : 1;
  byte b8 : 1;
  byte b9 : 1;
  byte b10: 1;
  byte b11: 1;
  byte b12: 1;
  byte b13: 1;
  byte b14: 1;
  byte b15: 1;
};

union DATA
{
  DATARAW rawdata;
  word value;
};

word romAddress = 0;

void setup() {
// address
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
  pinMode(A8, OUTPUT);
  pinMode(A9, OUTPUT);
  pinMode(A10, OUTPUT);
  pinMode(A11, OUTPUT);
  pinMode(A12, OUTPUT);
  pinMode(A13, OUTPUT);
  pinMode(A14, OUTPUT);
  setAddress(romAddress);
// data
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  pinMode(D8, INPUT);
  pinMode(D9, INPUT);
  pinMode(D10, INPUT);
  pinMode(D11, INPUT);
  pinMode(D12, INPUT);
  pinMode(D13, INPUT);
  pinMode(D14, INPUT);
  pinMode(D15, INPUT);
// ctrl
  pinMode(OE, OUTPUT);
  digitalWrite(OE,HIGH);
// serial
  Serial.begin(115200);
}

void loop() {
  if(Serial.available() > 0) {
    char ctrl = Serial.read();
    if(ctrl== 'd') {
      setAddress(romAddress);
      delay(1);
      digitalWrite(OE,LOW);
      delay(1);
      word wData = getData();
      if( (wData < 0x1000)&&(wData >= 0x0100) ) {
        Serial.print(0);
      }
      if( (wData < 0x0100)&&(wData >= 0x0010) ) {
        Serial.print(0);
        Serial.print(0);
      }
      if(wData < 0x0010 ) {
        Serial.print(0);
        Serial.print(0);
        Serial.print(0);
      }
      Serial.println(wData,HEX);
      romAddress++;
      digitalWrite(OE,HIGH);
    }
    if(ctrl== 'r') {
      romAddress = 0;
    }
    if(ctrl== 'a') {
      for(romAddress=0;romAddress<32000;romAddress++) {
        setAddress(romAddress);
        delay(1);
        digitalWrite(OE,LOW);
        delay(1);
        word wData = getData();
        if( (wData < 0x1000)&&(wData >= 0x0100) ) {
          Serial.print(0);
        }
        if( (wData < 0x0100)&&(wData >= 0x0010) ) {
          Serial.print(0);
          Serial.print(0);
        }
        if(wData < 0x0010 ) {
          Serial.print(0);
          Serial.print(0);
          Serial.print(0);
        }
        Serial.println(wData,HEX);
        digitalWrite(OE,HIGH);
      }
    }
  }
}

void setAddress(int a)
{
  if( (a & 0x0001) == 0x0001 ) {
    digitalWrite(A0,HIGH);
  } else {
    digitalWrite(A0,LOW);
  }
  if( (a & 0x0002) == 0x0002 ) {
    digitalWrite(A1,HIGH);
  } else {
    digitalWrite(A1,LOW);
  }
  if( (a & 0x0004) == 0x0004 ) {
    digitalWrite(A2,HIGH);
  } else {
    digitalWrite(A2,LOW);
  }
  if( (a & 0x0008) == 0x0008 ) {
    digitalWrite(A3,HIGH);
  } else {
    digitalWrite(A3,LOW);
  }
  if( (a & 0x0010) == 0x0010 ) {
    digitalWrite(A4,HIGH);
  } else {
    digitalWrite(A4,LOW);
  }
  if( (a & 0x0020) == 0x0020 ) {
    digitalWrite(A5,HIGH);
  } else {
    digitalWrite(A5,LOW);
  }
  if( (a & 0x0040) == 0x0040 ) {
    digitalWrite(A6,HIGH);
  } else {
    digitalWrite(A6,LOW);
  }
  if( (a & 0x0080) == 0x0080 ) {
    digitalWrite(A7,HIGH);
  } else {
    digitalWrite(A7,LOW);
  }
  if( (a & 0x0100) == 0x0100 ) {
    digitalWrite(A8,HIGH);
  } else {
    digitalWrite(A8,LOW);
  }
  if( (a & 0x0200) == 0x0200 ) {
    digitalWrite(A9,HIGH);
  } else {
    digitalWrite(A9,LOW);
  }
  if( (a & 0x0400) == 0x0400 ) {
    digitalWrite(A10,HIGH);
  } else {
    digitalWrite(A10,LOW);
  }
  if( (a & 0x0800) == 0x0800 ) {
    digitalWrite(A11,HIGH);
  } else {
    digitalWrite(A11,LOW);
  }
  if( (a & 0x1000) == 0x1000 ) {
    digitalWrite(A12,HIGH);
  } else {
    digitalWrite(A12,LOW);
  }
  if( (a & 0x2000) == 0x2000 ) {
    digitalWrite(A13,HIGH);
  } else {
    digitalWrite(A13,LOW);
  }
  if( (a & 0x4000) == 0x4000 ) {
    digitalWrite(A14,HIGH);
  } else {
    digitalWrite(A14,LOW);
  }
}

word getData()
{
  DATA data;
  data.rawdata.b0 = digitalRead(D0);
  data.rawdata.b1 = digitalRead(D1);
  data.rawdata.b2 = digitalRead(D2);
  data.rawdata.b3 = digitalRead(D3);
  data.rawdata.b4 = digitalRead(D4);
  data.rawdata.b5 = digitalRead(D5);
  data.rawdata.b6 = digitalRead(D6);
  data.rawdata.b7 = digitalRead(D7);
//
  data.rawdata.b8 = digitalRead(D8);
  data.rawdata.b9 = digitalRead(D9);
  data.rawdata.b10 = digitalRead(D10);
  data.rawdata.b11 = digitalRead(D11);
  data.rawdata.b12 = digitalRead(D12);
  data.rawdata.b13 = digitalRead(D13);
  data.rawdata.b14 = digitalRead(D14);
  data.rawdata.b15 = digitalRead(D15);
  return data.value;
}

//

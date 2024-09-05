
#include "BluetoothSerial.h"
#include "Arduino.h"

BluetoothSerial SerialBT;

char btSignal;
int speed = 100;

int enA = 5;
int enB = 23;

int in1 = 22;
int in2 = 21;
int in3 = 19;
int in4 = 18;
void setup(){
  Serial.begin(115200);
  SerialBT.begin("XeDua");

  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(enA, speed);
  analogWrite(enB, speed);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop(){

  while(SerialBT.available()){
    btSignal = SerialBT.read();
    if(btSignal == '0') speed=100;
    if(btSignal == '1') speed=110;
    if(btSignal == '2') speed=120;
    if(btSignal == '3') speed=130;
    if(btSignal == '4') speed=140;
    if(btSignal == '5') speed=150;
    if(btSignal == '6') speed=180;
    if(btSignal == '7') speed=200;
    if(btSignal == '8') speed=220;
    if(btSignal == '9') speed=240;
    if(btSignal == 'q') speed=255;

    if(btSignal == 'B'){dilui();}
    else if(btSignal == 'F'){dithang();}
    else if(btSignal == 'L'){queotrai();}
    else if(btSignal == 'R'){queophai();}
    else{dung();}
  }
}

void dilui(){
  ledcWrite(R, speed);
  ledcWrite(L, speed);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}
void dithang(){
  ledcWrite(R, speed);
  ledcWrite(L, speed);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}
void queotrai(){
  ledcWrite(R, speed);
  ledcWrite(L, speed);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}
void queophai(){
  ledcWrite(R, speed);
  ledcWrite(L, speed);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}
void dung(){
  ledcWrite(R, speed);
  ledcWrite(L, speed);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}


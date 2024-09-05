#define BLYNK_TEMPLATE_ID "TMPL6a15ek1Uc"
#define BLYNK_TEMPLATE_NAME "Wifi Car"
#define BLYNK_AUTH_TOKEN "IOqbkOb0L38vpwY1CYnKQvsDbhTfMfpM"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

int speed;
bool forward =0;
bool backward =0;
bool left =0;
bool right =0;


int enA = 5;
int enB = 23;

int in1 = 22;
int in2 = 21;
int in3 = 19;
int in4 = 18;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Gia Phuc";
char pass[] = "44449999";

void setup(){
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
BLYNK_WRITE(V0){forward = param.asInt();}
BLYNK_WRITE(V1){backward = param.asInt();}
BLYNK_WRITE(V2){left = param.asInt();}
BLYNK_WRITE(V3){right = param.asInt();}
BLYNK_WRITE(V4){speed = param.asInt();}

void car(){
  if(forward == 1){Forward();}
  else if(backward ==1){Backward();}
  else if(left ==1){Left();}
  else if(right ==1){Right();}
  else if(forward == 0 && backward == 0 && left == 0 && right ==0){Stop();}
}
void loop(){
  Blynk.run();
  car();
}
void Forward(){
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void Backward(){
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void Left(){
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void Right(){
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void Stop(){
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
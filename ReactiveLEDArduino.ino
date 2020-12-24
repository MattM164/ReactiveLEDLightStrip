#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    60

CRGB leds[NUM_LEDS];
//int i = 0;

int brightness = 50;

int stage = 0;
String message = "                     0";
int r = 0;
String red = "        ";
int lastr = 0;
int g = 0;
String green = "         ";
int lastg = 0;
int b = 0;
String blue = "        ";
int lastb = 0;

int r1 = 0;
int r2 = 0;
int r3 = 0;
int g1 = 0;
int g2 = 0;
int g3 = 0;
int b1 = 0;
int b2 = 0;
int b3 = 0;

String red1 = "           ";
String red2 = "           ";
String red3 = "           ";
String green1 = "         ";
String green2 = "         ";
String green3 = "         ";
String blue1 = "          ";
String blue2 = "          ";
String blue3 = "          ";


byte redbite;

void setup() {

  Serial.begin(9600);//115200
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {

  if(Serial.available()>0){
    message = Serial.readStringUntil('\n');
    //redbite = Serial.read();
    Serial.print(message + '\n');
    /*char newline = '\n';
    char bite;
    int count = 0;
    while(bite != '\n'){
      bite = Serial.read();
      message[count] = bite;
      count++;
      //Serial.print(message);
    }
    */
    //message = readString();
    //delay(10);
    //Serial.print(message + '\n');
    //Serial.write("Got it");
    //Serial.write(message.toInt());
    }
  
  ////StringManip////
  /*for(int i = 0;i < message.length();i++){
    if(message[i] == '-'){
      message[i] = ' ';
    }
  }*/

  
    //Load First Pixel
    for(int i = 0;i < 3; i++){
      red[i] = message[i];
    }
    for(int i = 0;i < 3; i++){
      green[i] = message[i + 4];
    }
    for(int i = 0;i < 3; i++){
      blue[i] = message[i + 8];
    }
    //Load Second Pixel
    for(int i = 0;i < 3; i++){
      red1[i] = message[i + 12];
    }
    for(int i = 0;i < 3; i++){
      green1[i] = message[i + 4 + 12];
    }
    for(int i = 0;i < 3; i++){
      blue1[i] = message[i + 8 + 12];
    }
    //Load third Pixel
    for(int i = 0;i < 3; i++){
      red2[i] = message[i + 24];
    }
    for(int i = 0;i < 3; i++){
      green2[i] = message[i + 4  + 24];
    }
    for(int i = 0;i < 3; i++){
      blue2[i] = message[i + 8 + 24];
    }
    //Load Fourth Pixel
    for(int i = 0;i < 3; i++){
      red3[i] = message[i + 36];
    }
    for(int i = 0;i < 3; i++){
      green3[i] = message[i + 4 + 36];
    }
    for(int i = 0;i < 3; i++){
      blue3[i] = message[i + 8 + 36];
    }



    
    //Serial.print(red + '\n');
    r = red.toInt();
    g = green.toInt();
    b = blue.toInt();

    r1 = red1.toInt();
    g1 = green1.toInt();
    b1 = blue1.toInt();

    r2 = red2.toInt();
    g2 = green2.toInt();
    b2 = blue2.toInt();

    r3 = red3.toInt();
    g3 = green3.toInt();
    b3 = blue3.toInt();

   // map(r,0,255,0,brightness);
   // map(g,0,255,0,brightness);
   // map(b,0,255,0,brightness);
    
    for(int j = 45;j <60; j++){
      leds[j] = CRGB(map(r,0,255,0,brightness),map(g,0,255,0,brightness),map(b,0,255,0,brightness));
    }
    for(int j = 30;j <45; j++){
      leds[j] = CRGB(map(r1,0,255,0,brightness),map(g1,0,255,0,brightness),map(b1,0,255,0,brightness));
    }
    for(int j = 15;j <30; j++){
      leds[j] = CRGB(map(r2,0,255,0,brightness),map(g2,0,255,0,brightness),map(b2,0,255,0,brightness));
    }
    for(int j = 0;j <15; j++){
      leds[j] = CRGB(map(r3,0,255,0,brightness),map(g3,0,255,0,brightness),map(b3,0,255,0,brightness));
    }



    
    FastLED.show();
    //message = "                          ";
    //delay(5);
  

  /*/////////////////////////WORKINGSERIAL
  leds[message.toInt()] = CRGB(random(0,25),random(0,25),random(0,25));
  FastLED.show();
  if(message == "59"){
    FastLED.clear();
  }
  */

  /*
  for (int j = 0; j < i; j++){
    leds[j] = CRGB(random(0,255),random(0,255),random(0,255));
  }
  i++;
  if(i > 60){
    i = 0;
    FastLED.clear();
  }
  FastLED.show();
  delay(75);
  */

/*
    for (int j = 0; j < i; j++){
    if(stage == 0){
      leds[j] = CRGB(255,0,0);
    }else if(stage == 1){
      leds[j] = CRGB(0,255,0);
    }else if(stage == 2){
      leds[j] = CRGB(0,0,255);
    }
  }
  i++;
  if(i > 60){
    i = 0;
    stage++;
    if(stage == 3){
      stage = 0;
    }
    FastLED.clear();
  }
  FastLED.show();
  delay(75);

  
*/ 
}

String readString(){
  return Serial.readStringUntil('\n');
  //delay(10);
}

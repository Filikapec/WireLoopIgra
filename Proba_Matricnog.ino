#include <LedControl.h>
#include "Bitmape.h"

int DIN = 11;
int CS = 7;
int  CLK = 13;

bool isPlaying = false;

int startpin =3, kontakt = 2;

int greske = 0;

LedControl lc=LedControl(DIN, CLK, CS,4);



void setup()  {
  Serial.begin(9600);
  pinMode(startpin, INPUT);
  pinMode(kontakt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), DodirnuoJe, FALLING);
  lc.shutdown(0,false); lc.setIntensity(0,0); lc.clearDisplay(0);
  lc.shutdown(1,false); lc.setIntensity(1,0); lc.clearDisplay(1);
  lc.shutdown(2,false); lc.setIntensity(2,0); lc.clearDisplay(2);
  lc.shutdown(3,false); lc.setIntensity(3,0); lc.clearDisplay(3);
  //Reklama();
}

void  loop() {
  isPlaying = true;
  for(int i=60; i>0; i--) {
    for(int j=0; j<8; j++) {
      lc.setRow(1, j, cifre09[i/10][j]/2);
      lc.setRow(0, j, cifre09[i%10][j]*2);
      if(greske<10) {
        lc.setRow(3, j, cifre09[greske][j]);
      } else {
        lc.setRow(2, j, cifre09[greske%10][j]*2);
        lc.setRow(3, j, cifre09[greske/10][j]/2);
      }
    }
    delay(1000);
  }
}

void DodirnuoJe() {
  if(isPlaying) {
    greske++;
  }
}

void Reklama() {
  for(int i=0;i<4; i++) {
      for(int j=0; j<8; j++) {
        lc.setRow(i, j, logo[3-i][j]);
      }
    }
}

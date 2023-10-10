//Included Libraries
#include <LedControl.h>

//MACROS are defined here
LedControl dotMatrixDisplay = LedControl(3, 6, 5, 1);

//Gloabl Variables are declared here
float secura;

void setup() {
  //put your setup code here, to run once:
  dotMatrixDisplay.shutdown(0,false);
  dotMatrixDisplay.setIntensity(0,8);
  dotMatrixDisplay.clearDisplay(0);
  pinMode(0, INPUT);
  
  
}

void loop() {
  //put your main code here, to run repeatedly:
  
  
  secura = analogRead(0);
  if((secura < 75)) {
    dotMatrixDisplay.drawFromString(0, "0000000001100110100110011000000101000010001001000001100000000000");
  }
  if(((secura > 75) && (secura < 125))) {
    dotMatrixDisplay.drawFromString(0, "0000000001100110100110011000000101000010001111000001100000000000");
  }
  if(((secura > 125) && (secura < 175))) {
    dotMatrixDisplay.drawFromString(0, "0000000001100110100110011000000101111110001111000001100000000000");
  }
  if(((secura > 175) && (secura < 225))) {
    dotMatrixDisplay.drawFromString(0, "0000000001100110100110011111111101111110001111000001100000000000");
  }
  if((secura > 225)) {
    dotMatrixDisplay.drawFromString(0, "0000000001100110111111111111111101111110001111000001100000000000");
  }
}
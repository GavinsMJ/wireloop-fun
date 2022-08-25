/*
  By Gavins M 
       Have fun
*/
#include "definitions.h"


void gameover();

enum Status
{
  STOP = 0,
  GO = 1
};

void setup() {
  Serial.begin(9600);
  int i;
   
 pinMode(clock, OUTPUT); // make the clock pin an output
 pinMode(data , OUTPUT); // make the data pin an output
 
   for (i = 0; i < NUM_OF_DIGITS; i++)
  {
    pinMode(control_pins[i], OUTPUT);
  }
  
  for (i = 0; i < NUM_OF_DIGITS; i++)
  {
    digitalWrite(i, LOW);
  }
 
 pinMode(7, OUTPUT);

 
 //Random animations
 for (i = 0; i < 100 ; i++){
  
          digitalWrite(7, HIGH);
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
          digitalWrite(4, LOW);
          shiftOut(data, clock, LSBFIRST, P);
           digitalWrite(7, HIGH);
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
          digitalWrite(4, LOW);
          
          //shiftOut(data, clock, LSBFIRST, P);
          delay(DElaycontrol);
          digitalWrite(7, LOW);
          digitalWrite(6, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(4, LOW);
          
          shiftOut(data, clock, LSBFIRST, L);
          digitalWrite(7, LOW);
          digitalWrite(6, HIGH);
          digitalWrite(5, LOW);
          digitalWrite(4, LOW);
          
          //shiftOut(data, clock, LSBFIRST, L);
         delay(DElaycontrol);
         
          digitalWrite(7, LOW);
          digitalWrite(6, LOW);
          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          shiftOut(data, clock, LSBFIRST, A);
          digitalWrite(7, LOW);
          digitalWrite(6, LOW);
          digitalWrite(5, HIGH);
          digitalWrite(4, LOW);
          //shiftOut(data, clock, LSBFIRST, A);
          delay(DElaycontrol);

          digitalWrite(7, LOW);
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
          digitalWrite(4, HIGH);    
          shiftOut(data, clock, LSBFIRST, Y);
          digitalWrite(7, LOW);
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
          digitalWrite(4, HIGH);
          //shiftOut(data, clock, LSBFIRST, Y);
          delay (DElaycontrol);

          
 }
for (i = 0; i < NUM_OF_DIGITS; i++)
  {
    digitalWrite(i, LOW);
  }
digitalWrite(7, HIGH);

shiftOut(data, clock, LSBFIRST, zero);
}


Status status = GO;
int failCounter = 0;

void loop() {


  while (failCounter > fail_threshold)
    {
       gameover();
    }

  switch (status)
  {
    case GO:
      digitalWrite(GO_LED, HIGH);
      digitalWrite(STOP_LED, LOW);
      digitalWrite(BUZZ, LOW);
      if (digitalRead(TOUCH) == HIGH)
      {
        status = STOP;
      }
      break;
      
    case STOP:
      digitalWrite(GO_LED, LOW);
        digitalWrite(STOP_LED, HIGH);
      failCounter++;
      if (failCounter > fail_threshold)
        break;

       if(failCounter == 0 ){
        shiftOut(data, clock, LSBFIRST, zero); 
      delay(100); }
        if(failCounter == 1 ){
        shiftOut(data, clock, LSBFIRST, one); 
      delay(100);
        } if(failCounter == 2 ){
        shiftOut(data, clock, LSBFIRST, two); 
      delay(100);
        } if(failCounter == 3 ){
        shiftOut(data, clock, LSBFIRST, three); 
      delay(100);
        } if(failCounter == 4 ){
        shiftOut(data, clock, LSBFIRST, four); 
      delay(100);
        } if(failCounter == 5 ){
        shiftOut(data, clock, LSBFIRST, five); 
      delay(100);
        } if(failCounter == 6 ){
        shiftOut(data, clock, LSBFIRST, six); 
      delay(100);
        } if(failCounter == 7 ){
        shiftOut(data, clock, LSBFIRST, seven); 
      delay(100);
        } if(failCounter == 8 ){
        shiftOut(data, clock, LSBFIRST, eight); 
      delay(100);
        } if(failCounter == 9 ){
        shiftOut(data, clock, LSBFIRST, nine); 
      delay(100);
        }

      Serial.println(failCounter);
     // failAlarm();
      status = GO;
      break;
  }
delay(100);
}



void gameover()
{
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
 
     
  for (int thisNote = 0; thisNote < 112; thisNote++) {
    
    shiftOut(data, clock, LSBFIRST, ~seg_spin[thisNote]);
        
    int noteDuration = 750 / noteDurations[thisNote];
    tone(BUZZ, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(BUZZ);
  }
  

}

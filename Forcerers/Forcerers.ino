#include <PWM.h>

// the pins that the transducers are attached to
int transducer = 5;
int transducer2 = 12;

//(0-255) 128-1/2t high 1/2t low
int timeFraction = 127; 

//frequency (in Hz) for each circuit of transducers
int32_t frequency = 39800;
int32_t frequency2 = 40000;

void setup()
{
  //initialize all timers except for 0, to save time keeping functions
  InitTimersSafe(); 

  //sets the frequency for the specified pin
  bool success = SetPinFrequencySafe(transducer, frequency);
  bool success2 = SetPinFrequencySafe(transducer2, frequency2);
  
  //Serial.begin(9600);
  
  //if the pin frequency was set successfully, turn pin 13 on
  if(success && success2) {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);    
  }
}

void loop()
{
  //use this functions instead of analogWrite on 'initialized' pins
  pwmWrite(transducer, timeFraction);
  pwmWrite(transducer2, timeFraction);

  //outputs for debugging
  //Serial.print(Timer0_GetFrequency());
  //Serial.print(" ");
  //Serial.print(Timer1_GetFrequency());
  //Serial.print(" ");
  //Serial.print(Timer2_GetFrequency());
  //Serial.print(" ");
  //Serial.print(Timer3_GetFrequency());
  //Serial.print(" ");
  //Serial.print(Timer4_GetFrequency());
  //Serial.print(" ");
  //Serial.println(Timer5_GetFrequency());
}

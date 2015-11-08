/*

 Mimics the fade example but with an extra parameter for frequency. It should dim but with a flicker 
 because the frequency has been set low enough for the human eye to detect. This flicker is easiest to see when 
 the LED is moving with respect to the eye and when it is between about 20% - 60% brighness. The library 
 allows for a frequency range from 1Hz - 2MHz on 16 bit timers and 31Hz - 2 MHz on 8 bit timers. When 
 SetPinFrequency()/SetPinFrequencySafe() is called, a bool is returned which can be tested to verify the 
 frequency was actually changed.
 
 This example runs on mega and uno.
 */

#include <PWM.h>

//use pin 11 on the Mega instead, otherwise there is a frequency cap at 31 Hz
int led = 5;
int led2 = 12;// the pin that the LED is attached to
int brightness = 127;         // how bright the LED is         // how many points to fade the LED by
int32_t frequency = ;
int32_t frequency2 = 40000;//frequency (in Hz)

boolean change_freq(){
   
}

void setup()
{
  //initialize all timers except for 0, to save time keeping functions
  InitTimersSafe(); 

  //sets the frequency for the specified pin
  bool success = SetPinFrequencySafe(led, frequency);
  bool success2 = SetPinFrequencySafe(led2, frequency2);
  
  Serial.begin(9600);
  
  //if the pin frequency was set successfully, turn pin 13 on
  if(success && success2) {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);    
  }
}

void loop()
{
  //use this functions instead of analogWrite on 'initialized' pins
  pwmWrite(led, brightness);
  pwmWrite(led2, brightness);
  Serial.print(Timer0_GetFrequency());
  Serial.print("                 ");
  Serial.print(Timer1_GetFrequency());
  Serial.print("              ");
  Serial.print(Timer2_GetFrequency());
  Serial.print(" ");
  Serial.print(Timer3_GetFrequency());
  Serial.print(" ");
  Serial.print(Timer4_GetFrequency());
  Serial.print(" ");
  Serial.println(Timer5_GetFrequency());
}

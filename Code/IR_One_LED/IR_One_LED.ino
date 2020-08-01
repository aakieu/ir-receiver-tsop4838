/*
 Some Sample code of how to use your IR remote
 
 * Lets get started:
 
 The IR sensor's pins are attached to Arduino as so:
 Pin 1 to Vout (pin 11 on Arduino)
 Pin 2 to GND
 Pin 3 to Vcc (+5v from Arduino)

*/

#include <IRremote.h>

int IRpin = 11;  // pin for the IR sensor
int LED = 13;    // LED pin  
IRrecv irrecv(IRpin);
decode_results results;




void setup()
{
   pinMode(13, OUTPUT);
   Serial.begin(9600);
  irrecv.enableIRIn();                      // Start the receiver
}
 
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume(); 
     
  if(results.value== 3838644744) // Your ON button value                                       
  {
             digitalWrite(13,HIGH);
  }
  else if(results.value == 3772793023) // Your OFF button value 
  {
             digitalWrite(13,LOW);
  }
                                }
}
 
 


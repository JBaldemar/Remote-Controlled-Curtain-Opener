#include <Arduino.h>

#include <IRremote.hpp>
#define IR_RECEIVE_PIN 2
#define HBRIDGE_A 3
#define HBRIDGE_B 4
void setup()
{

  Serial.begin(9600); // // Establish serial communication
  
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}


void loop() {
  if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      IrReceiver.resume();
  }

  analogWrite(3, 255);
}

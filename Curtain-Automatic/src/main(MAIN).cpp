#include <Arduino.h>

#include <IRremote.hpp>
#include <util/delay.h>
#define IR_RECEIVE_PIN 2
#define HBRIDGE_B2 A1
#define HBRIDGE_B1 A2

#define OPEN 1
#define CLOSED 0

void setup()
{

  Serial.begin(9600); // // Establish serial communication
  
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}

void spinLeft(){
    analogWrite(HBRIDGE_B1, 150);
    analogWrite(HBRIDGE_B2, 0);
}
void stopMotor(){
    analogWrite(HBRIDGE_B1, 0);
    analogWrite(HBRIDGE_B2, 0);
}
void spinRight(){
    analogWrite(HBRIDGE_B1, 0);
    analogWrite(HBRIDGE_B2, 150);
}

void curtainFSM(){
  static int state = CLOSED;
  if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      IrReceiver.resume();
      if (state == CLOSED){
        spinLeft();
        _delay_ms(1000);
        stopMotor()
        state = OPEN;
      } else if (state == OPEN){
        spinRight();
        _delay_ms(1000);
        stopMotor();
        state = CLOSED;
      }
  }
}

void loop() {
  if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      IrReceiver.resume();
  }

  analogWrite(3, 255);
}



#include <Arduino.h>

#define HBRIDGE_B2 A1
#define HBRIDGE_B1 A2

#define STOPPED 0
#define SPINING_RIGHT 1
#define STOPPED_2 2
#define SPINNING_LEFT 3

void setup(){
    pinMode(HBRIDGE_B1, OUTPUT);
    pinMode(HBRIDGE_B2, OUTPUT);

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

void spinBothDirectionsFSM(){
    static int state = 0;
    switch(state){
        case STOPPED:
            delay(1000);
            state = SPINNING_LEFT;
            spinLeft();
            break;
        case SPINNING_LEFT:
            delay(1000);
            state = STOPPED_2;
            stopMotor();
            break;
        case STOPPED_2:
            delay(1000);
            state = SPINING_RIGHT;
            spinRight();
            break;
        case SPINING_RIGHT:
            delay(1000);
            state = STOPPED;
            stopMotor();
            break;
        default:
            break;
    }
}

void loop(){
    spinBothDirectionsFSM();
}




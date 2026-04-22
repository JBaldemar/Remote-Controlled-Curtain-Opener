#include <Arduino.h>

#define HBRIDGE_B2 3
#define HBRIDGE_B1 4
#define END_TIMER 20000

#define STOPPED 0
#define SPINING_RIGHT 1
#define STOPPED_2 2
#define SPINNING_LEFT 3

void setup(){
    pinMode(HBRIDGE_B1, OUTPUT);
    pinMode(HBRIDGE_B2, OUTPUT);

}
void spinLeft(){
    digitalWrite(HBRIDGE_B1, HIGH);
    digitalWrite(HBRIDGE_B2, LOW);
}
void stopMotor(){
    digitalWrite(HBRIDGE_B1, 0);
    digitalWrite(HBRIDGE_B2, 0);
}
void spinRight(){
    digitalWrite(HBRIDGE_B1, LOW);
    digitalWrite(HBRIDGE_B2, HIGH);
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
    //spinBothDirectionsFSM();
}




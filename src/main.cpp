#include <Arduino.h>
#include <Servo.h>

/* DECLARATIONS*/
void openPins(void);
int getDistance();
void setLight(int distance);
void setDoor(int distance);
void openServo(void);

/* DEFINES */
#define TRIG1 10
#define ECHO1 9
#define LED1 11
#define PIN_SERVO_DOOR 8

/* GLOBALS */
Servo doorServo_g;
bool doorState;

int main_func(void)
{
    int distance;

    openPins();
    openServo();

    doorServo_g.write(0);
    while(1)
    {
        delay(250);
        distance = getDistance();
        Serial.print("Distance measured:");
        Serial.println(distance);
        setLight(distance); 
        setDoor(distance);
    }

    return 0;
}

void setDoor(int distance)
{
    int openDoorPos = 95;
    
    if(distance <= 5)
    {
        Serial.println("Opening Door:");
        doorState = true; //opened
        doorServo_g.write(openDoorPos);
        delay(5000);
    }
    else if(distance > 5)
    {
        if(doorState)
        {
            Serial.println("Closing Door:");
            doorState = false;
            doorServo_g.write(0);
        }
    }
}

void setLight(int distance)
{
    if(distance <= 15)
    {
        digitalWrite(LED1, HIGH);
    }
    else if(distance > 15)
    {
        digitalWrite(LED1, LOW);
    }
}

int getDistance()
{
    int distance = 0;
    long echoTime = 0;

    digitalWrite(TRIG1, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG1, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG1, LOW);

    echoTime = pulseIn(ECHO1, HIGH);

    distance = echoTime * 0.034 / 2;

    return distance;
}

void openServo()
{
    // initial door position upon power-up
    int initialPos = 0;
    doorState = false; //default is closed

    doorServo_g.attach(PIN_SERVO_DOOR);
    delay(100);
    doorServo_g.write(initialPos);
}

void openPins()
{
    Serial.println("Opening GPIO Pins");
    pinMode(TRIG1, OUTPUT);
    pinMode(ECHO1, INPUT);
    pinMode(LED1, OUTPUT);
}

// starts here, sets up serial output, and goes to 'main'
void setup() 
{
    Serial.begin(9600);
    delay(100);
    Serial.println("Setup test");
    Serial.println("uhhh");
    main_func();
}

void loop() 
{
    // should never reach here!!!
    Serial.println("Loop?");
    delay(1000);
}

    // while(1)
    // {
    //     Serial.println("Blinking ON");
    //     Serial.println("Blinking ON");
    //     digitalWrite(TRIG1, HIGH);
    //     delay(1000);
    //     Serial.println("Blinking OFF");
    //     digitalWrite(TRIG1, LOW);
    //     delay(1000);
    // }
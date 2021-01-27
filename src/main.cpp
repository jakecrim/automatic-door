#include <Arduino.h>

/* DECLARATIONS*/
void openPins(void);
int getDistance();
void setLight(int distance);
void setDoor(int distance);

/* DEFINES */
#define TRIG1 10
#define ECHO1 9
#define LED1 11


int main_func(void)
{
    Serial.println("Test");
    openPins();
    
    int distance;

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
    if(distance <= 5)
    {
        Serial.println("Opening Door:");
    }
    else if(distance > 5)
    {

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
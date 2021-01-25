#include <Arduino.h>

/* DECLARATIONS*/
void openPins(void);

/* DEFINES */
#define TRIG1 12
#define ECHO1 11


int main_func(void)
{
    Serial.begin(9600);
    delay(1000);
    printf("Auto Door Starting \n");
    openPins();

    while(1)
    {
        Serial.println("Blinking ON");
        digitalWrite(TRIG1, HIGH);
        delay(1000);
        Serial.println("Blinking OFF");
        digitalWrite(TRIG1, LOW);
        delay(1000);
    }

    return 0;
}

void openPins()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    pinMode(TRIG1, OUTPUT);
    pinMode(ECHO1, OUTPUT);
    Serial.println("Hello World!");
}

// starts here, sets up serial output, and goes to 'main'
void setup() 
{
    Serial.begin(9600);
    delay(100);
    Serial.println("Setup test");
    main_func();
}

void loop() 
{
    // should never reach here!!!
    delay(1000);
}
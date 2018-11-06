//LEDs
#define RED_1 2 13

//Volume Pots
#define POT_1_2 A1
#define POT_2_2 A2
#define POT_3_2 A3
#define POT_4_2 A4

//LCD Screen
#define LCD_RS 8
#define LCD_ENABLE 9
#define LCD_DATA_4 46
#define LCD_DATA_5 48
#define LCD_DATA_6 50
#define LCD_DATA_7 52
#define LCD_CONTRAST 11

#include <LiquidCrystal.h>
//LiquidCrystal LCD_DISPLAY(LCD_RS, LCD_ENABLE, LCD_DATA_4, LCD_DATA_5, LCD_DATA_6, LCD_DATA_7);

int POT_1_VALUE = 0;
int POT_2_VALUE = 0;
int POT_3_VALUE = 0;
int POT_4_VALUE = 0;

void setup() {
    Serial.begin(115200);

    pinMode(RED_1_2, OUTPUT);
    digitalWrite(RED_1_2, HIGH);
    delay(500);
    digitalWrite(RED_1_2, LOW);
}

void loop() {
    digitalWrite(RED_1_2, LOW);
    //Read the analog values from the pots
    POT_1_VALUE = analogRead(POT_1_2);
    POT_2_VALUE = analogRead(POT_2_2);
    POT_3_VALUE = analogRead(POT_3_2);
    POT_4_VALUE = analogRead(POT_4_2);
    
    //Convert them to a voltage from 0.0v to 5.0v
    float POT_1_V = (POT_1_VALUE * (5/1023.0));
    float POT_2_V = (POT_2_VALUE * (5/1023.0));
    float POT_3_V = (POT_3_VALUE * (5/1023.0));
    float POT_4_V = (POT_4_VALUE * (5/1023.0));

    //Since the range is 0-1023, we divite the analog in by 1023 for a %
    float POT_1_VOL = (POT_1_VALUE / 1023.0) * 100.0;
    float POT_2_VOL = (POT_2_VALUE / 1023.0) * 100.0;
    float POT_3_VOL = (POT_3_VALUE / 1023.0) * 100.0;
    float POT_4_VOL = (POT_4_VALUE / 1023.0) * 100.0;

    int POT_VOLUME[] = {POT_1_VOL, POT_2_VOL, POT_3_VOL, POT_4_VOL};
    int COUNTER;
    for (COUNTER = 0; COUNTER < 4; COUNTER = COUNTER + 1) {
        Serial.print(POT_VOLUME[COUNTER]);
        Serial.print(" ");
    }
    Serial.println();
    digitalWrite(RED_1_2, HIGH);
}
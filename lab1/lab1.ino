#include "buzzer.h"

#define R_OUT 5
#define G_OUT 6
#define B_OUT 7

void setup()
{

    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

void loop() 
{
    set_rgb_led(rgb);
}


void set_rgb_led(colorData rgb)
{
    analogWrite(R_OUT, 255 - rgb.value[TCS230_RGB_R]);
    analogWrite(G_OUT, 255 - rgb.value[TCS230_RGB_G]);
    analogWrite(B_OUT, 255 - rgb.value[TCS230_RGB_B]);

}

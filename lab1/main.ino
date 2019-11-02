#include "button.h"

#define R_OUT 5
#define G_OUT 6
#define B_OUT 7
#define INC_R Button(8)
#define DEC_R Button(9)
#define INC_G Button(10)
#define DEC_G Button(11)
#define INC_B Button(12)
#define DEC_B Button(13)
#define DELTA 10

Button Buttons[] = { INC_R, INC_G, INC_B, DEC_R, DEC_G, DEC_B };
int Pins[] = {R_OUT, G_OUT,B_OUT};
int RGBV[] = { 0, 0, 0 };

void setup()
{
  for (int i = 0; i < 3; ++i)
  {
    pinMode(Pins[i], OUTPUT);
  }
}

void loop() 
{
    for (int i = 0; i < 6; ++i)
    {
        if (Buttons[i].wasPressed())
        {
          if(i<3){
            RGBV[i%3] = min(RGBV[i%3] + DELTA, 250);
          }
          else {
            RGBV[i%3] = max(RGBV[i%3] - DELTA, 0);
            }
        }
    }

    set_rgb_led();
}

void set_rgb_led()
{
   for (int i = 0; i < 3; ++i)
  {
    analogWrite(Pins[i], RGBV[i]);
  }
}

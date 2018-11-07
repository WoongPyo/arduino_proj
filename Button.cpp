#include "Button.h"
#include "Arduino.h"

Button::Button(int pin_ROW[2], int pin_COLUMN[4])
{
  for(int i = 0; i < 2; i++)
    _pin_ROW[i] = pin_ROW[i];
  for(int i = 0; i < 4; i++)
    _pin_COLUMN[i] =  pin_COLUMN[i]; 
};

void Button::Begin()
{
  for(int i = 0; i < 2; i++)
    pinMode(_pin_ROW[i], OUTPUT);
  for(int i = 0; i < 4; i++)
    pinMode(_pin_COLUMN[i], INPUT);
};

int Button::GetButton()
{
  int num;
  int out = TRASH;
  for(int i = 0; i < 2; i++) 
  {
    digitalWrite(_pin_ROW[i], HIGH);
    for(int j = 0; j < 4; j++)
    {
      num = i * 4 + j;
      if(digitalRead(_pin_COLUMN[j]) && _flag[num] == false) 
      {
        _flag[num] = true;
        out = num;
      }
      else if(!digitalRead(_pin_COLUMN[j]))
        _flag[num] = false;
    }
    digitalWrite(_pin_ROW[i], LOW);
  }
  return out;
};



#include "Arduino.h"
#include "SevenSegment.h"

SevenSegment::SevenSegment(int pin_FND_DATA[FND_PIN_NUM], int pin_FND_SEL[DIGIT_NUM])
{
  for(int i=0; i < FND_PIN_NUM; i++)
    _pin_FND_DATA[i] = pin_FND_DATA[i];
  for(int i = 0; i < DIGIT_NUM; i++)
    _pin_FND_SEL[i] = pin_FND_SEL[i];
};

void SevenSegment::FND_data_out(uint8_t data)
{
  for(int i=0; i < FND_PIN_NUM; i++) 
    digitalWrite(_pin_FND_DATA[i], (data>>i) & 0x1);
}

void SevenSegment::FND_sel_out(uint8_t data)
{
  for(int i=0; i < DIGIT_NUM; i++)
    digitalWrite(_pin_FND_SEL[i], (data>>i) & 0x1);
}

void SevenSegment::Begin()
{
  for(int i=0; i < FND_PIN_NUM; i++)
    pinMode(_pin_FND_DATA[i], OUTPUT);
  for(int i=0; i < DIGIT_NUM; i++)
    pinMode(_pin_FND_SEL[i], OUTPUT);
};


void SevenSegment::PrintNum(int SBO[SBO_NUM],int num)
{       
  for(int i = 0; i < SBO_NUM; i++) 
  {
    FND_sel_out(_FND_sel_data[i]);
    if(num > i)
      FND_data_out(_FND_data[SBO[i]]);
    else
      FND_data_out(_FND_data[SBO[i]+10]);
    delay(2);
  }
};

void SevenSegment::Blink(int SBO[SBO_NUM], int tim)
{
  _bling++;
  if(_bling < tim)
    PrintNum(SBO,0);
  else
    PrintNum(SBO,3);

  if(_bling > 2*tim)
    _bling = 0;
};


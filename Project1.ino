#include "SevenSegment.h"
#include "Button.h"
#include "Compare.h"

#define TRASH 1000
#define SBO_NUM 3

int pin_FND_DATA[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int pin_FND_SEL[3] = {A1, A2, A3};
int pin_BUTTON_ROW[2] = {A5, A4};
int pin_BUTTON_COL[4] = {2, 3, 4, 5};

SevenSegment sevenSegment(pin_FND_DATA, pin_FND_SEL);
Button button(pin_BUTTON_ROW, pin_BUTTON_COL);
Compare compare;

int sbo[3] = {0,};
int n = 0;
int pw[3] = {0,};

void setup() 
{
  Serial.begin(9600);
  sevenSegment.Begin();
  button.Begin();
  compare.MakePassword();
  PrintPassword();
}

void loop() 
{
  int input = button.GetButton();
  
  if (input != TRASH)
  {
    if(compare.InputGuess(n, input))
    {
      n++;
    }
  }
  
  sevenSegment.PrintNum(sbo,n);
    
  if(n == 3)
  {
    for(int i = 0; i < SBO_NUM; i++)
      sbo[i] = 0;
    compare.ComparePG(sbo);
    if(sbo[2])
    {
      while(button.GetButton() == TRASH)
        sevenSegment.Blink(sbo,100);
      compare.MakePassword();
    }
    n = 0;
    PrintPassword();
  }
  
}


void PrintPassword()
{
  for(int i = 0; i < 3; i++)
    Serial.print(compare.GetPassword(i));
  Serial.println();
}


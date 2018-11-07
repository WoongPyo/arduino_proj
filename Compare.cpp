#include "Compare.h"
#include "Arduino.h"

Compare::Compare()
{
  _door = false;
};

int Compare::GetPassword(int num)
{
  return _password[num];
};

void Compare::MakePassword()
{
  randomSeed(analogRead(A0));
  while(1)
  {
    for(int i = 0; i < 3; i++)
      _password[i] = random(8);
    if( _password[0] != _password[1] && _password[0] != _password[2] && _password[1] != _password[2])
      break;
  }
};

void Compare::SetPassword(int num, int input)
{
  _password[num] = input;
};

bool Compare::InputGuess(int num, int input)
{
  for(int i = 0; i < num; i++)
  {
    if(input == _guess[i])
      return false;
  }
  _guess[num] = input;
  return true;
};

void Compare::ComparePG(int* sbo)
{
  sbo[0] = 0;
  sbo[1] = 0;
  sbo[2] = 0;
  for(int i = 0; i < PASSWORD_NUM; i++)
  {
    int j = (i + 1) % 3;
    int k = (i + 2) % 3;
    
    if(_password[i] == _guess[i])
      sbo[0]++;
    else if((_password[i] == _guess[j]) || (_password[i] == _guess[k]))
      sbo[1]++;
  }
  
  if(sbo[0] == 3)
  {
    sbo[0] = 0;
    sbo[1] = 0;
    sbo[2] = 1;
  }
};


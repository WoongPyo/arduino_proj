#define TRASH 1000

class Button
{
private:
  int _pin_ROW[2];
  int _pin_COLUMN[4];
  bool _flag[8] = {false, };

public:
  Button(int pin_ROW[2], int pin_COLUMN[4]);
  void Begin();
  int GetButton();
};

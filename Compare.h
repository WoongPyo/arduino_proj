#define PASSWORD_NUM 3
#define SBO_NUM 3

#define TRASH 1000

class Compare
{
private:
  int _password[PASSWORD_NUM] = {1000, };
  int _guess[PASSWORD_NUM];
  bool _door;
  int _point = 0;

  
public:
  Compare();
  int GetPassword(int num);
  void SetPassword(int num, int input);
  bool InputGuess(int num, int input);
  void ComparePG(int* sbo);
  void MakePassword();
};

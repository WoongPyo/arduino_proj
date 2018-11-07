#define FND_PIN_NUM 8
#define DIGIT_NUM 3
#define SBO_NUM 3

class SevenSegment
{
private:
  int _pin_FND_DATA[FND_PIN_NUM];
  int _pin_FND_SEL[DIGIT_NUM];
  int _bling;
  
  
  const uint8_t _FND_data[20] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F, 0xBF, 0x86, 0xDB, 0xCF, 0xD6, 0xDD, 0xFD, 0xA7, 0xFF, 0xDF}; // NUM Memory
  const uint8_t _FND_sel_data[DIGIT_NUM] = {0x06, 0x05, 0x03}; // Digit

  void FND_data_out(uint8_t data);
  void FND_sel_out(uint8_t data);
  
public:
  SevenSegment(int pin_FND_DATA[FND_PIN_NUM], int pin_FND_SEL[DIGIT_NUM]);
  void Begin();
  void PrintNum(int SBO[SBO_NUM],int num);
  void Blink(int SBO[SBO_NUM], int tim);
};


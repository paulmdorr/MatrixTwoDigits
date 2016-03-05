#include <LedControlMS.h>

class MatrixTwoDigits {
  private:
    word matrixNumbers[10] = {
      (B01111011 * 256) + B01101111, //0
      (B01110100 * 256) + B10011010, //1
      (B01110011 * 256) + B11100111, //2
      (B01111001 * 256) + B10100111, //3
      (B01001001 * 256) + B11101101, //4
      (B01111001 * 256) + B11001111, //5
      (B01111011 * 256) + B11001111, //6
      (B01001001 * 256) + B00100111, //7
      (B01111011 * 256) + B11101111, //8
      (B01111001 * 256) + B11101111  //9
    };

    word matrixChars[27] = {
      (B01011011 * 256) + B11101111, //A
      (B01111010 * 256) + B11101111, //B
      (B01110010 * 256) + B01001111, //C
      (B00111011 * 256) + B01101011, //D
      (B01110010 * 256) + B11001111, //E
      (B00010010 * 256) + B11001111, //F
      (B01111011 * 256) + B01001111, //G
      (B01011011 * 256) + B11101101, //H
      (B01110100 * 256) + B10010111, //I
      (B01111001 * 256) + B00100110, //J
      (B01011010 * 256) + B11101101, //K
      (B01110010 * 256) + B01001001, //L
      (B01011011 * 256) + B11111101, //M (sort of)
      (B01011011 * 256) + B01011000, //N (sort of lowercase)
      (B01111011 * 256) + B01101111, //O
      (B00010011 * 256) + B11101111, //P
      (B01001001 * 256) + B11101111, //Q
      (B01010111 * 256) + B11101111, //R
      (B01111001 * 256) + B11001111, //S
      (B00100100 * 256) + B10010111, //T
      (B01111011 * 256) + B01101101, //U
      (B00101011 * 256) + B01101101, //V
      (B01011111 * 256) + B11101101, //W
      (B01011010 * 256) + B10101101, //X
      (B00100100 * 256) + B10101101, //Y
      (B01110010 * 256) + B10100111, //Z
      (B00000000 * 256) + B00000000  //Space (index 26)
    };

    //Harcoded declaration, so it doesn't explode, should I change this? :/
    LedControl lc = LedControl(12, 11, 10, 0);
    bool vertical;
    void printNumberOnMatrix(int number, bool right);
    void printCharOnMatrix(char charToPrint, bool right);
    void printOnMatrix(word* base, int position, bool right);
  public:
    MatrixTwoDigits(int dataPin, int clkPin, int csPin, bool vertical);
    void printNumber(int number);
    void printChars(char first, char second);
    void slideText(String text, int delayTime);
};
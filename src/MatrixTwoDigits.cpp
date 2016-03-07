#include "MatrixTwoDigits.h"

MatrixTwoDigits::MatrixTwoDigits(int dataPin, int clkPin, int csPin, bool vertical) {
  lc = LedControl(dataPin, clkPin, csPin, 0);
  lc.shutdown(0, false);
  lc.setIntensity(0, 2);
  lc.clearDisplay(0);

  this->vertical = vertical;
}

//Only accepts upper case chars
void MatrixTwoDigits::printCharOnMatrix(char charToPrint, bool right) {
  if (charToPrint == ' ') {
    printOnMatrix(matrixChars, 26, right);
  } else {
    printOnMatrix(matrixChars, charToPrint - 65, right);
  }
}

void MatrixTwoDigits::printNumberOnMatrix(int number, bool right) {
  printOnMatrix(matrixNumbers, number, right);
}

void MatrixTwoDigits::printOnMatrix(word* base, int position, bool right) {
  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
      if (i > 2 && j >= 0 && j < 3 && bitRead(base[position], j+(i-3)*3)) {
        int column = right ? j + 4 : j;
        if (!vertical) {
          lc.setLed(0, i, column, true);
        } else {
          lc.setLed(0, column, 7 - i, true);
        }
      }
    }
  }
}

void MatrixTwoDigits::printNumber(int number) {
  if (number > 0 && number < 100) {
    lc.clearDisplay(0);
    if (number > 9) {
      int first = number / 10;
      int second = number % 10;
      printNumberOnMatrix(first, false);
      printNumberOnMatrix(second, true);
    } else {
      printNumberOnMatrix(number, false);
    }
  }
}

void MatrixTwoDigits::printChars(char first, char second) {
  lc.clearDisplay(0);
  if (first != NULL) {
    printCharOnMatrix(first, false);
  }
  if (second != NULL) {
    printCharOnMatrix(second, true);
  }
}

void MatrixTwoDigits::slideText(String text, int delayTime) {
  text.toUpperCase();
  printChars(NULL, text[0]);
  delay(delayTime);
  for (int i = 0; i < text.length(); i++) {
    if (i == text.length()) {
      printChars(text[i], NULL);
    } else {
      printChars(text[i], text[i+1]);
    }
    delay(delayTime);
  }
  printChars(NULL, NULL);
}

void MatrixTwoDigits::printDots(byte dots) {
  for (int i=0; i<dots ; i++) {
    byte row = i / 8;
    byte column = i - ((i / 8) * 8);
    if (!vertical) {
      lc.setLed(0, row, column, true);
    } else {
      lc.setLed(0, column, 7 - row, true);
    }
  }
}
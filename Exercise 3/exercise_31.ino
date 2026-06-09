#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int segmentPins[7] = {A0, A1, A2, A3, A4, A5, 10};

const byte numPatterns[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1}
};

const byte alphaPatterns[4][7] = {
  {1, 1, 1, 0, 1, 1, 1},
  {0, 0, 1, 1, 1, 1, 1},
  {1, 0, 0, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 0, 1}
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  clearDisplay(); 
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey) {
    if (customKey >= '0' && customKey <= '9') {
      int numberToDisplay = customKey - '0';
      displayNumber(numberToDisplay);
    } 
    else if (customKey >= 'A' && customKey <= 'D') {
      int letterIndex = customKey - 'A';
      displayLetter(letterIndex);
    } 
    else {
      displayDash();
    }
  }
}

void displayNumber(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], numPatterns[num][i]);
  }
}

void displayLetter(int index) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], alphaPatterns[index][i]);
  }
}

void displayDash() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(segmentPins[i], LOW);
  }
  digitalWrite(segmentPins[6], HIGH);
}


void clearDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], LOW); 
  }
}
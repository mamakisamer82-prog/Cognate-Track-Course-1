int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
int delayTime = 500;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int center = 6; // LED #7 is index 6

  // start with center LED
  digitalWrite(ledPins[center], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[center], LOW);

  // expand outward (pairs lit simultaneously with delay)
  for (int offset = 1; offset < numLeds / 2; offset++) {
    int left = center - offset;
    int right = center + offset;

    if (left >= 0 && right < numLeds) {
      digitalWrite(ledPins[left], HIGH);
      digitalWrite(ledPins[right], HIGH);
      delay(delayTime);
      digitalWrite(ledPins[left], LOW);
      digitalWrite(ledPins[right], LOW);
    }
  }

  // fold back inward (reverse order, pairs lit simultaneously with delay)
  for (int offset = numLeds / 2 - 1; offset >= 1; offset--) {
    int left = center - offset;
    int right = center + offset;

    if (left >= 0 && right < numLeds) {
      digitalWrite(ledPins[left], HIGH);
      digitalWrite(ledPins[right], HIGH);
      delay(delayTime);
      digitalWrite(ledPins[left], LOW);
      digitalWrite(ledPins[right], LOW);
    }
  }

  // blink center again
  digitalWrite(ledPins[center], HIGH);
  delay(delayTime);
  digitalWrite(ledPins[center], LOW);
}

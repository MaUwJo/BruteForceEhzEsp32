#include <Arduino.h>

// put function declarations here:
// int myFunction(int, int);
// int blink();
// int morseDigit(int);
int ledPin = 4;                       // Verwendet Pin D2 des D1 Mini
int blinkDuration = 500;              // Dauer des Blinkens für eine Ziffer (in Millisekunden)
int blinkDurationlong = 1000;         // Dauer des Blinkens für eine Ziffer (in Millisekunden)
int blinkPauseDuration = 500;         // Dauer der Pause zwischen den Blinkimpulsen für eine Ziffer (in Millisekunden)
int blinkPauseDurationlong = 1000;    // Dauer der Pause zwischen den Blinkimpulsen für eine Ziffer (in Millisekunden)
int digitSpaceBetweenDuration = 3000; // Pause zwischen den Ziffern (in Millisekunden)
int wordSpaceDuration = 7000;          // Pause nach der gesamten 4-stelligen Zahl (in Millisekunden)

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}

// Smartmeter PIN Brute-Force
// written 99% by ChatGPT ;-)
void blinklong()
{
  digitalWrite(ledPin, HIGH);
  delay(blinkDurationlong);
  digitalWrite(ledPin, LOW);
  delay(blinkPauseDurationlong);
}

void blink()
{
  digitalWrite(ledPin, HIGH);
  delay(blinkDuration);
  digitalWrite(ledPin, LOW);
  delay(blinkPauseDuration);
}
void morseDigit(int digit)
{
  for (int i = 0; i < digit; i++)
  {
    // Blinkimpulse für die Ziffer
    blink();
  }
  // Pause zwischen den Ziffern
  delay(digitSpaceBetweenDuration);
}
void setup()
{
  pinMode(ledPin, OUTPUT);
  // Durchprobiere alle Zahlen von 0001 bis 9998
  // for (int i = 1; i <= 9998; i++) {
  for (int i = 850; i < 10000 ; i++)
  {
    // Kurz 2x Blinken vor jeder Zahl um den Pin-Eingabemodus zu starten ()
    blinklong();
    blinklong();
    // 4-stellige Zahl morsen
    morseDigit((i / 1000) % 10); // Tausenderstelle
    morseDigit((i / 100) % 10);  // Hunderterstelle
    morseDigit((i / 10) % 10);   // Zehnerstelle
    morseDigit(i % 10);          // Einerstelle
    // Pause nach jeder Zahl
    delay(wordSpaceDuration);
  }
}
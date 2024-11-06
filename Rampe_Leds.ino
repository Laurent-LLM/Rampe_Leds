// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ400);
int delayval = 150;
bool etat = false;
int etape = 0;


void setup()
{
  pixels.begin(); // This initializes the NeoPixel library.
}


void defileGaD() {
  for (int i = 8; i <= 15; i++) {
    pixels.setPixelColor(i, pixels.Color(128, 128, 0));
    pixels.show();
    delay(delayval);
  }
  pixels.clear();
}
void defileDaG() {
  for (int i = 15; i >= 8; i--) {
    pixels.setPixelColor(i, pixels.Color(128, 128, 0));
    pixels.show();
    delay(delayval);
  }
  pixels.clear();
}
void chenille() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delay(delayval);
  }
  pixels.clear();
}

void boutsBleus() {
  static unsigned long chrono = millis();
  int tempo = 50;
  if ((millis() - chrono) < tempo) {
    return;
  } else {
    chrono = millis();
  }
  pixels.clear();

  if (etat) {
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(7, pixels.Color(0, 0, 255));
  }

  pixels.show();
  etat = !etat;
}

void gyro(int offset = 0) {
  static unsigned long chrono;
  int tempo = 155;
  if ((millis() - chrono) < tempo) {
    return;
  } else {
    chrono = millis();
  }
  pixels.clear();

  if (etat) {
    pixels.setPixelColor(offset + 0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(offset + 1, pixels.Color(0, 0, 255));
    pixels.setPixelColor(offset + 4, pixels.Color(0, 0, 255));
    pixels.setPixelColor(offset + 5, pixels.Color(0, 0, 255));
  } else {
    pixels.setPixelColor(offset + 2, pixels.Color(0, 0, 255));
    pixels.setPixelColor(offset + 3, pixels.Color(0, 0, 255));
    pixels.setPixelColor(offset + 6, pixels.Color(0, 0, 255));
    pixels.setPixelColor(offset + 7, pixels.Color(0, 0, 255));
  }

  pixels.show();
  etat = !etat;
}

void gyro2() {
  static unsigned long chrono;
  int tempo = 155;
  if ((millis() - chrono) < tempo) {
    return;
  } else {
    chrono = millis();
  }
  pixels.clear();

  if (etat) {
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
    pixels.setPixelColor(4, pixels.Color(0, 0, 255));
    pixels.setPixelColor(6, pixels.Color(0, 0, 255));
  } else {
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.setPixelColor(5, pixels.Color(0, 0, 255));
    pixels.setPixelColor(7, pixels.Color(0, 0, 255));
  }

  pixels.show();
  etat = !etat;
}

void gyro3() {
  static unsigned long chrono = millis();
  int delta = (millis() - chrono);
  pixels.clear();

  if (delta > 0  && delta < 100) {
    pixels.setPixelColor(11, pixels.Color(255, 90, 0));
    pixels.setPixelColor(12, pixels.Color(255, 90, 0));
  }
  if (delta > 200 && delta < 300) {
    pixels.setPixelColor(10, pixels.Color(255, 90, 0));
    pixels.setPixelColor(13, pixels.Color(255, 90, 0));
  }
  if (delta > 400 && delta < 500) {
    pixels.setPixelColor(9, pixels.Color(255, 90, 0));
    pixels.setPixelColor(14, pixels.Color(255, 90, 0));
  }
  if (delta > 700  && delta < 800) {
    pixels.setPixelColor(8, pixels.Color(255, 90, 0));
    pixels.setPixelColor(15, pixels.Color(255, 90, 0));
  }
  if (delta > 1500) {
    chrono = millis();
  }

  pixels.show();
}

void gyroUS(bool blanche = false) {
  static unsigned long chrono = millis();
  int delta = (millis() - chrono);
  pixels.clear();

  // leds bleues
  if (delta > 0 && delta < 50) {
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
  }
  if (delta > 100 && delta < 150) {
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
  }
  // leds rouges
  if (delta > 450 && delta < 500) {
    pixels.setPixelColor(5, pixels.Color(255, 0, 0));
    pixels.setPixelColor(6, pixels.Color(255, 0, 0));
    pixels.setPixelColor(7, pixels.Color(255, 0, 0));
  }
  if (delta > 550 && delta < 600) {
    pixels.setPixelColor(5, pixels.Color(255, 0, 0));
    pixels.setPixelColor(6, pixels.Color(255, 0, 0));
    pixels.setPixelColor(7, pixels.Color(255, 0, 0));
  }
  // leds blanches
  if (blanche) {
    if (delta > 200 && delta < 250) {
      pixels.setPixelColor(3, pixels.Color(255, 255, 255));
      pixels.setPixelColor(4, pixels.Color(255, 255, 255));
    }
    if (delta > 300 && delta < 350) {
      pixels.setPixelColor(3, pixels.Color(255, 255, 255));
      pixels.setPixelColor(4, pixels.Color(255, 255, 255));
    }
    if (delta > 650 && delta < 700) {
      pixels.setPixelColor(3, pixels.Color(255, 255, 255));
      pixels.setPixelColor(4, pixels.Color(255, 255, 255));
    }
    if (delta > 750 && delta < 800) {
      pixels.setPixelColor(3, pixels.Color(255, 255, 255));
      pixels.setPixelColor(4, pixels.Color(255, 255, 255));
    }
  }
  if (delta > 850) {
    chrono = millis();
  }

  pixels.show();
}

void loop() {

  static unsigned long chrono = millis();
  int delta = (millis() - chrono);
  if (delta > 5000) {
    etat = bool(random(2));
    chrono = millis();
  }
  gyroUS(etat);
  gyro3();

}

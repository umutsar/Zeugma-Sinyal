#include <FastLED.h>
#define NUM_LEDS1 35
#define Buton 18
#define Buton2 19


int butonDurumu = 0;
volatile int flag1 = 0;
volatile int flag2 = 0;

CRGB leds1[NUM_LEDS1];
#define led_pini 12


void temizle() {
  for (int i = 0; i < NUM_LEDS1; i++) {
    leds1[i].setRGB(255, 255, 255);
  }
}
void buttonInterrupt(void);
void buttonInterrupt2(void);


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, led_pini, GRB>(leds1, NUM_LEDS1);
  pinMode(Buton, INPUT);  // Butonlar için entegre pull-up direnci kullan
  pinMode(Buton2, INPUT);

  attachInterrupt(digitalPinToInterrupt(Buton), button1change, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Buton2), button2change, CHANGE);

  randomSeed(analogRead(0));


// Mor         (100, 50, 0)
// Turkuvaz    (0, 50, 100)
// Sarı        (200, 0, 100)
// Pembe       (230, 40 ,0)
// #Açık Yeşil (0, 40, 230)
// #Koyu Mor   (40, 230, 0)
// Mavi        (0, 255, 255)
// Kırmızı     (255, 0, 0)
// Yeşil       (100, 0, 200)

int a = 0;
int b = 255;
int c = 0;
  temizle();
  for (int i = 0; i <= 14; i++) {
    switch (i % 7) {
      case 0:
        leds1[14 - i].setRGB(100, 50, 0);
        leds1[20 + i].setRGB(100, 50, 100);
        FastLED.show();
        break;

      case 1:
        leds1[14 - i].setRGB(0, 50, 100);
        leds1[20 + i].setRGB(0, 50, 100);
        FastLED.show();
        break;

      case 2:
        leds1[14 - i].setRGB(200, 0, 100);
        leds1[20 + i].setRGB(200, 0, 100);
        FastLED.show();
        break;

      case 3:
        leds1[14 - i].setRGB(230, 40, 0);
        leds1[20 + i].setRGB(230, 40, 0);
        FastLED.show();
        break;

      case 4:
        leds1[14 - i].setRGB(40, 230, 0);
        leds1[20 + i].setRGB(40, 230, 0);
        FastLED.show();
        break;

      case 5:
        leds1[14 - i].setRGB(0, 255, 255);
        leds1[20 + i].setRGB(0, 255, 255);
        FastLED.show();
        break;

      case 6:
        leds1[14 - i].setRGB(255, 0, 0);
        leds1[20 + i].setRGB(255, 0, 0);
        FastLED.show();
        break;

  
    }
    
    delay(100);
  }
}

void button1change() {
  if (digitalRead(Buton) == LOW) {
    flag1 = 0;
  } else {
    flag1 = 1;
  }
}

void button2change() {
  if (digitalRead(Buton2) == LOW) {
    flag2 = 0;
  } else {
    flag2 = 1;
  }
}


void loop() {
  if (flag1 && !flag2) {
    temizle();
    for (int i = 0; i <= 14; i++) {
      leds1[14 - i].setRGB(255, 0, 80);
      FastLED.show();
      delay(70);
    }
  }

  if (flag2 && !flag1) {
    temizle();
    for (int i = 20; i < NUM_LEDS1; i++) {
      leds1[i].setRGB(255, 0, 80);
      FastLED.show();
      delay(70);
    }
  }

  if (flag1 && flag2) {
    temizle();
    for (int i = 0; i <= 14; i++) {
      leds1[14 - i].setRGB(255, 0, 80);
      leds1[20 + i].setRGB(255, 0, 80);
      FastLED.show();
      delay(70);
    }
  }

  if (!flag1 && !flag2) {
    temizle();
    FastLED.show();
  }
  Serial.print("Random sayi: ");
  Serial.println(random(256));
  delay(100);
}

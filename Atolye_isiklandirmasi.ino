#include <FastLED.h>
#define NUM_LEDS1 26

#define led_pini 12
#define saksakSensoru 2

int red = 210;
int green = 50;
int blue = 0;

bool flag = 1;

int param = 0;
int paramPrev = 0;

int butonDurumu = 0;
volatile int flag1 = 0;
volatile int flag2 = 0;

CRGB leds1[NUM_LEDS1];



void temizle() {
  for (int i = 0; i < NUM_LEDS1; i++) {
    leds1[i].setRGB(0, 0, 0);
  }
}
void buttonInterrupt(void);
void buttonInterrupt2(void);


void saksakInterruptHandler() {
  flag = 1;
  param = random(7);
  if (param == paramPrev) {
    param++;
  }
  paramPrev = param;
  // kırmızı
  if (param == 0) {
    red = 255;
    green = 0;
    blue = 0;
  }
  // yeşil
  else if (param == 1) {
    red = 0;
    green = 255;
    blue = 0;
  }
  // mavi
  else if (param == 2) {
    red = 0;
    green = 0;
    blue = 255;
  }
  // mor
  else if (param == 3) {
    red = 100;
    green = 50;
    blue = 0;
  }
  // turkuvaz
  else if (param == 4) {
    red = 0;
    green = 50;
    blue = 100;
  }
  // Sarı
  else if (param == 5) {
    red = 200;
    green = 0;
    blue = 100;
  }
  // Sarı
  else if (param == 6) {
    red = 230;
    green = 40;
    blue = 0;
  }
}



void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, led_pini, GRB>(leds1, NUM_LEDS1);
  randomSeed(analogRead(0));

  attachInterrupt(digitalPinToInterrupt(saksakSensoru), saksakInterruptHandler, RISING);


  // Mor         (100, 50, 0)
  // Turkuvaz    (0, 50, 100)
  // Sarı        (200, 0, 100)
  // Pembe       (230, 40 ,0)
  // #Açık Yeşil (0, 40, 230)
  // #Koyu Mor   (40, 230, 0)
  // Mavi        (0, 255, 255)
  // Kırmızı     (255, 0, 0)
  // Yeşil       (100, 0, 200)

  // Yılbaşı ledleri rengi (255, 5, 58)

  int a = 0;
  int b = 255;
  int c = 0;
  temizle();
}


void loop() {
  // for(int i = 0; i < NUM_LEDS1; i++) {
  //   leds1[i].setRGB(red, green, blue);
  // }
  // if(flag) FastLED.show();


  // for (int i = 0; i < NUM_LEDS1; i++) {
  //   leds1[i].setRGB(random(200), random(200), random(200));
  //   delay(2);
  //   FastLED.show();
  // }

  for (int i = 0; i < NUM_LEDS1; i++) {
    leds1[i].setRGB(255, 5, 58);
    FastLED.show();
  }
  delay(100);


  // for (int i = 0; i < NUM_LEDS1; i++) {

  //   leds1[NUM_LEDS1 - i].setRGB(255, 0, 0);
  //   leds1[NUM_LEDS1 - i - 1].setRGB(255, 0, 0);
  //   leds1[NUM_LEDS1 - i - 2].setRGB(255, 0, 0);

  //   leds1[NUM_LEDS1 - i + 1].setRGB(red, green, blue);
  //   leds1[NUM_LEDS1 - i + 2].setRGB(red, green, blue);
  //   leds1[NUM_LEDS1 - i + 3].setRGB(red, green, blue);

  //   if (i % 3 == 0 && i < NUM_LEDS1 - 15) {
  //     leds1[i / 3].setRGB(255, 0, 0);
  //     leds1[i / 3 - 1].setRGB(red, green, blue);
  //   }

  //   FastLED.show();
  //   delay(15);
  // }
  // for(int i = 0; i < NUM_LEDS1; i++) {
  //   leds1[i].setRGB(red, green, blue);
  //   FastLED.show();
  // }

  // // for(int i = 0; i < 22; i++) {
  // //   temizle();
  // //   leds1[i].setRGB(255,0,0);
  // //   FastLED.show();
  // // }

  // if (flag) {
  //   flag = 0;
  //   for (int i = 0; i < NUM_LEDS1; i++) {
  //     leds1[i].setRGB(red, green, blue);
  //     FastLED.show();
  //   }
  // }
}



// End

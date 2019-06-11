#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_CLK   9
#define OLED_MOSI   10
#define OLED_RESET 11
#define OLED_DC    12
#define OLED_CS    13

#define mod_rotation(a) (a ? 4 : 1)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

const byte sizes[] = {2,3,3,3,3,3,4};

const boolean O[] = {1,1,
               	     1,1};

const boolean S1[] = {0,1,1,
                      1,1,0,
                      0,0,0};
const boolean S2[] = {0,1,0,
                      0,1,1,
                      0,0,1};
const boolean S3[] = {0,0,0,
                      0,1,1,
                      1,1,0};
const boolean S4[] = {1,0,0,
                      1,1,0,
                      0,1,0};

const boolean Z1[] = {1,1,0,
                      0,1,1,
                      0,0,0};
const boolean Z2[] = {0,0,1,
                      0,1,1,
                      0,1,0};
const boolean Z3[] = {0,0,0,
                      1,1,0,
                      0,1,1};
const boolean Z4[] = {0,1,0,
                      1,1,0,
                      1,0,0};

const boolean L1[] = {0,0,0,
                      0,0,1,
                      1,1,1};
const boolean L2[] = {1,0,0,
                      1,0,0,
                      1,1,0};
const boolean L3[] = {1,1,1,
                      1,0,0,
                      0,0,0};
const boolean L4[] = {0,1,1,
                      0,0,1,
                      0,0,1};

const boolean J1[] = {0,0,0,
                      1,0,0,
                      1,1,1};
const boolean J2[] = {1,1,0,
                      1,0,0,
                      1,0,0};
const boolean J3[] = {1,1,1,
                      0,0,1,
                      0,0,0};
const boolean J4[] = {0,0,1,
                      0,0,1,
                      0,1,1};

const boolean T1[] = {0,1,0,
                      1,1,1,
                      0,0,0};
const boolean T2[] = {0,1,0,
                      0,1,1,
                      0,1,0};
const boolean T3[] = {0,0,0,
                      1,1,1,
                      0,1,0};
const boolean T4[] = {0,1,0,
                      1,1,0,
                      0,1,0};

const boolean I1[] = {0,1,0,0,
                      0,1,0,0,
                      0,1,0,0,
                      0,1,0,0};
const boolean I2[] = {0,0,0,0,
                      1,1,1,1,
                      0,0,0,0,
                      0,0,0,0};
const boolean I3[] = {0,0,1,0,
                      0,0,1,0,
                      0,0,1,0,
                      0,0,1,0};
const boolean I4[] = {0,0,0,0,
                      0,0,0,0,
                      1,1,1,1,
                      0,0,0,0};
boolean stage[] = {
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
};

const boolean* pieces(byte piece, byte rot) {
  if(piece == 0) { 
    return &O[0];
  } else if(piece == 1) {
    if(rot == 0) {
      return &S1[0];
    } else if(rot == 1) {
      return &S2[0];
    } else if(rot == 2) {
      return &S3[0];
    } else if(rot == 3){
      return &S4[0];
    }
  } else if(piece == 2) {
    if(rot == 0) {
      return &Z1[0];
    } else if(rot == 1) {
      return &Z2[0];
    } else if(rot == 2) {
      return &Z3[0];
    } else if(rot == 3){
      return &Z4[0];
    }
  } else if(piece == 3) {
    if(rot == 0) {
      return &L1[0];
    } else if(rot == 1) {
      return &L2[0];
    } else if(rot == 2) {
      return &L3[0];
    } else if(rot == 3){
      return &L4[0];
    }
  } else if(piece == 4) {
    if(rot == 0) {
      return &J1[0];
    } else if(rot == 1) {
      return &J2[0];
    } else if(rot == 2) {
      return &J3[0];
    } else if(rot == 3){
      return &J4[0];
    }
  } else if(piece == 5) {
    if(rot == 0) {
      return &T1[0];
    } else if(rot == 1) {
      return &T2[0];
    } else if(rot == 2) {
      return &T3[0];
    } else if(rot == 3){
      return &T4[0];
    }
  } else if(piece == 6) {
    if(rot == 0) {
      return &I1[0];
    } else if(rot == 1) {
      return &I2[0];
    } else if(rot == 2) {
      return &I3[0];
    } else if(rot == 3){
      return &I4[0];
    }
  }
  return &O[0];
}

void print_bit(byte x, byte y) {
  for(int i = 0; i < 16; i++)
    display.drawPixel((101-5*y) - i/4, (8+5*x) + i%4, WHITE);
}

void print_bit_matrix(byte p, byte rot, byte x, byte y) {
  const boolean* piece = pieces(p, rot);
  for(int  i = 0; i < sizes[p]*sizes[p]; i ++)
    if (piece[i])
      print_bit(x + i%sizes[p], y + i/sizes[p]);
}

void setup_game() {
  for(int i = 1; i < 104; i++) {
    display.drawPixel(i, 6, WHITE);
    display.drawPixel(i, 58, WHITE);
  }
  for(int i = 6; i < 59; i++) {
    display.drawPixel(1, i, WHITE);
    display.drawPixel(103, i, WHITE);
  }
}

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC))
    for(;;); // Don't proceed, loop forever
  display.clearDisplay();
  setup_game();
  display.display();
}

void loop() {
  for(int i = 0; i < 7; i++) {
    for(int j = 0; j < mod_rotation(i); j++) {
      print_bit_matrix(i, j, 0, 0);
      display.display();
      delay(500);
      display.clearDisplay();
      setup_game();
    }
  }
}

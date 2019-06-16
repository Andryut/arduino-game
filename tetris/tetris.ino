#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64

#define OLED_CLK    9
#define OLED_MOSI   10
#define OLED_RESET  11
#define OLED_DC     12
#define OLED_CS     13
#define JOY_X       A0
#define JOY_Y       A1
#define JOY_B       8
#define MID_Y       502
#define MID_X       517
const byte sizes[]  = {2, 3, 3, 3, 3, 3, 4};

const boolean O1[]  = {1, 1,
                       1, 1
                      };
const boolean O2[]  = {1, 1,
                       1, 1
                      };
const boolean O3[]  = {1, 1,
                       1, 1
                      };
const boolean O4[]  = {1, 1,
                       1, 1
                      };

const boolean S1[]  = {0, 1, 1,
                       1, 1, 0,
                       0, 0, 0
                      };
const boolean S2[]  = {0, 1, 0,
                       0, 1, 1,
                       0, 0, 1
                      };
const boolean S3[]  = {0, 0, 0,
                       0, 1, 1,
                       1, 1, 0
                      };
const boolean S4[]  = {1, 0, 0,
                       1, 1, 0,
                       0, 1, 0
                      };

const boolean Z1[]  = {1, 1, 0,
                       0, 1, 1,
                       0, 0, 0
                      };
const boolean Z2[]  = {0, 0, 1,
                       0, 1, 1,
                       0, 1, 0
                      };
const boolean Z3[]  = {0, 0, 0,
                       1, 1, 0,
                       0, 1, 1
                      };
const boolean Z4[]  = {0, 1, 0,
                       1, 1, 0,
                       1, 0, 0
                      };

const boolean L1[]  = {0, 0, 0,
                       0, 0, 1,
                       1, 1, 1
                      };
const boolean L2[]  = {1, 0, 0,
                       1, 0, 0,
                       1, 1, 0
                      };
const boolean L3[]  = {1, 1, 1,
                       1, 0, 0,
                       0, 0, 0
                      };
const boolean L4[]  = {0, 1, 1,
                       0, 0, 1,
                       0, 0, 1
                      };

const boolean J1[]  = {0, 0, 0,
                       1, 0, 0,
                       1, 1, 1
                      };
const boolean J2[]  = {1, 1, 0,
                       1, 0, 0,
                       1, 0, 0
                      };
const boolean J3[]  = {1, 1, 1,
                       0, 0, 1,
                       0, 0, 0
                      };
const boolean J4[]  = {0, 0, 1,
                       0, 0, 1,
                       0, 1, 1
                      };

const boolean T1[]  = {0, 1, 0,
                       1, 1, 1,
                       0, 0, 0
                      };
const boolean T2[]  = {0, 1, 0,
                       0, 1, 1,
                       0, 1, 0
                      };
const boolean T3[]  = {0, 0, 0,
                       1, 1, 1,
                       0, 1, 0
                      };
const boolean T4[]  = {0, 1, 0,
                       1, 1, 0,
                       0, 1, 0
                      };

const boolean I1[]  = {0, 1, 0, 0,
                       0, 1, 0, 0,
                       0, 1, 0, 0,
                       0, 1, 0, 0
                      };
const boolean I2[]  = {0, 0, 0, 0,
                       1, 1, 1, 1,
                       0, 0, 0, 0,
                       0, 0, 0, 0
                      };
const boolean I3[]  = {0, 0, 1, 0,
                       0, 0, 1, 0,
                       0, 0, 1, 0,
                       0, 0, 1, 0
                      };
const boolean I4[]  = {0, 0, 0, 0,
                       0, 0, 0, 0,
                       1, 1, 1, 1,
                       0, 0, 0, 0
                      };

const boolean N0[]  = {1, 1, 1,
                       1, 0, 1,
                       1, 0, 1,
                       1, 0, 1,
                       1, 1, 1
                      };
const boolean N1[]  = {0, 1, 0,
                       0, 1, 0,
                       0, 1, 0,
                       0, 1, 0,
                       0, 1, 0
                      };
const boolean N2[]  = {1, 1, 1,
                       0, 0, 1,
                       1, 1, 1,
                       1, 0, 0,
                       1, 1, 1
                      };
const boolean N3[]  = {1, 1, 1,
                       0, 0, 1,
                       1, 1, 1,
                       0, 0, 1,
                       1, 1, 1
                      };
const boolean N4[]  = {1, 0, 1,
                       1, 0, 1,
                       1, 1, 1,
                       0, 0, 1,
                       0, 0, 1
                      };
const boolean N5[]  = {1, 1, 1,
                       1, 0, 0,
                       1, 1, 1,
                       0, 0, 1,
                       1, 1, 1
                      };
const boolean N6[]  = {1, 1, 1,
                       1, 0, 0,
                       1, 1, 1,
                       1, 0, 1,
                       1, 1, 1
                      };
const boolean N7[]  = {1, 1, 1,
                       0, 0, 1,
                       0, 0, 1,
                       0, 0, 1,
                       0, 0, 1
                      };
const boolean N8[]  = {1, 1, 1,
                       1, 0, 1,
                       1, 1, 1,
                       1, 0, 1,
                       1, 1, 1
                      };
const boolean N9[]  = {1, 1, 1,
                       1, 0, 1,
                       1, 1, 1,
                       0, 0, 1,
                       1, 1, 1
                      };
const boolean CHS[]  = {1, 1, 1,
                        1, 0, 0,
                        1, 1, 1,
                        0, 0, 1,
                        1, 1, 1
                       };
const boolean CHC[]  = {1, 1, 1,
                        1, 0, 0,
                        1, 0, 0,
                        1, 0, 0,
                        1, 1, 1
                       };
const boolean CHO[]  = {1, 1, 1,
                        1, 0, 1,
                        1, 0, 1,
                        1, 0, 1,
                        1, 1, 1
                       };
const boolean CHR[]  = {1, 1, 1,
                        1, 0, 1,
                        1, 1, 1,
                        1, 1, 0,
                        1, 0, 1
                       };
const boolean CHE[]  = {1, 1, 1,
                        1, 0, 0,
                        1, 1, 1,
                        1, 0, 0,
                        1, 1, 1
                       };
const boolean CHN[]  = {0, 0, 1,
                        1, 0, 1,
                        1, 1, 1,
                        1, 0, 1,
                        1, 0, 0
                       };
const boolean CHX[]  = {1, 0, 1,
                        1, 0, 1,
                        0, 1, 0,
                        1, 0, 1,
                        1, 0, 1
                       };
const boolean CHT[]  = {1, 1, 1,
                        0, 1, 0,
                        0, 1, 0,
                        0, 1, 0,
                        0, 1, 0
                       };


byte button, rotation, kappa;
short vx, vy, x, y;
long score;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

boolean stage[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void setup_pins() {
  pinMode(JOY_B, INPUT);
}

void setup_variables() {
  x = 0;
  y = 0;
  rotation = 0;
  score = 0;
  kappa = 0;
}

const boolean* pieces(byte piece, byte rot) {
  if (piece == 0) {
    if (rot == 0) {
      return &O1[0];
    } else if (rot == 1) {
      return &O2[0];
    } else if (rot == 2) {
      return &O3[0];
    } else if (rot == 3) {
      return &O4[0];
    }
  } else if (piece == 1) {
    if (rot == 0) {
      return &S1[0];
    } else if (rot == 1) {
      return &S2[0];
    } else if (rot == 2) {
      return &S3[0];
    } else if (rot == 3) {
      return &S4[0];
    }
  } else if (piece == 2) {
    if (rot == 0) {
      return &Z1[0];
    } else if (rot == 1) {
      return &Z2[0];
    } else if (rot == 2) {
      return &Z3[0];
    } else if (rot == 3) {
      return &Z4[0];
    }
  } else if (piece == 3) {
    if (rot == 0) {
      return &L1[0];
    } else if (rot == 1) {
      return &L2[0];
    } else if (rot == 2) {
      return &L3[0];
    } else if (rot == 3) {
      return &L4[0];
    }
  } else if (piece == 4) {
    if (rot == 0) {
      return &J1[0];
    } else if (rot == 1) {
      return &J2[0];
    } else if (rot == 2) {
      return &J3[0];
    } else if (rot == 3) {
      return &J4[0];
    }
  } else if (piece == 5) {
    if (rot == 0) {
      return &T1[0];
    } else if (rot == 1) {
      return &T2[0];
    } else if (rot == 2) {
      return &T3[0];
    } else if (rot == 3) {
      return &T4[0];
    }
  } else if (piece == 6) {
    if (rot == 0) {
      return &I1[0];
    } else if (rot == 1) {
      return &I2[0];
    } else if (rot == 2) {
      return &I3[0];
    } else if (rot == 3) {
      return &I4[0];
    }
  }
  return &O1[0];
}

void print_bit(byte x, short y) {
  for (int i = 0; i < 16; i++)
    display.drawPixel((100 - 5 * y) - i / 4, (2 + 5 * x) + i % 4, WHITE);
}
void clear_bit(byte x, short y) {
  for (int i = 0; i < 16; i++)
    display.drawPixel((100 - 5 * y) - i / 4, (2 + 5 * x) + i % 4, BLACK);
}

void print_bit_matrix(byte p, byte rot, byte x, short y) {
  const boolean* piece = pieces(p, rot);
  for (int  i = 0; i < sizes[p]*sizes[p]; i ++)
    if (piece[i])
      print_bit(x + i % sizes[p], y + i / sizes[p]);
}

void clear_bit_matrix(byte p, byte rot, byte x, short y) {
  const boolean* piece = pieces(p, rot);
  for (int  i = 0; i < sizes[p]*sizes[p]; i ++)
    if (piece[i])
      clear_bit(x + i % sizes[p], y + i / sizes[p]);
}

const boolean* character(char ch) {
  if (ch == 'S') {
    return &CHS[0];
  } else if (ch == 'C') {
    return &CHC[0];
  } else if (ch == 'O') {
    return &CHO[0];
  } else if (ch == 'R') {
    return &CHR[0];
  } else if (ch == 'E') {
    return &CHE[0];
  } else if (ch == 'N') {
    return &CHN[0];
  } else if (ch == 'X') {
    return &CHX[0];
  } else if (ch == 'T') {
    return &CHT[0];
  } else {
    return NULL;
  }
}

void print_character(char ch, byte x, byte y) {
  const boolean* cha = character(ch);
  for (int i = 0; i < 15; i ++)
    display.drawPixel(127 - y - (i / 3), x + (i % 3), cha[i] ? WHITE : BLACK);
}

void print_string(String str, byte x, byte y) {
  for (int i = 0; str[i] != '\0'; i++)
    print_character(str[i], x + i * 4, y);
}

const boolean* number(byte num) {
  if (num == 0) {
    return &N0[0];
  } else if (num == 1) {
    return &N1[0];
  } else if (num == 2) {
    return &N2[0];
  } else if (num == 3) {
    return &N3[0];
  } else if (num == 4) {
    return &N4[0];
  } else if (num == 5) {
    return &N5[0];
  } else if (num == 6) {
    return &N6[0];
  } else if (num == 7) {
    return &N7[0];
  } else if (num == 8) {
    return &N8[0];
  } else if (num == 9) {
    return &N9[0];
  } else {
    return NULL;
  }
}

void print_digit(byte num, byte x, byte y) {
  const boolean* numb = number(num);
  for (byte i = 0; i < 15; i ++)
    if (numb[i])
      display.drawPixel(127 - y - (i / 3), x + (i % 3), WHITE);
    else
      display.drawPixel(127 - y - (i / 3), x + (i % 3), BLACK);
}

long pow(long b, short e) {
  long out = b;
  for (short i = 1; i < e; i++)
    out *= b;
  return e == 0 ? 1 : out;
}

void print_number(long num, byte x, byte y) {
  num = num > 9999999L ? 9999999L : num;
  int digits = 1;
  for (long i = 10; num / i > 0; i *= 10)
    digits++;
  for (byte i = 0; i < 8 - digits; i++)
    print_digit(0, x + 4 * i, y);
  x += (6 - digits) * 4;
  for (short i = digits - 1; i >= 0; i--) {
    print_digit((num - num % pow(10, i)) / pow(10, i), x + 4 * (digits - i), y);
    num -= (num - num % pow(10, i));
  }
}

void print_next(byte piece) {
  print_bit_matrix(piece, 0, 9, -4);
}

void clear_next(byte piece) {
  clear_bit_matrix(piece, 0, 9, -4);
}

void setup_scene() {
  for (int i = 0; i < 103; i++) {
    display.drawPixel(i, 0, WHITE);
    display.drawPixel(i, 52, WHITE);
  }
  for (int i = 0; i < 53; i++) {
    display.drawPixel(0, i, WHITE);
    display.drawPixel(102, i, WHITE);
  }
  print_string("SCORE", 0, 0);
  print_string("NEXT", 49, 0);
}

void setup_game() {
  setup_variables();
  if (!display.begin(SSD1306_SWITCHCAPVCC))
    while (1);
  display.clearDisplay();
  setup_scene();
  display.display();
}

void setup() {
  setup_pins();
  setup_game();
}

void loop() {
  vx = analogRead(JOY_X);
  vy = analogRead(JOY_Y);
  button = digitalRead(JOY_B);
  if (button == LOW) rotation = (rotation + 1) % 4;
  vx = (vx > MID_X + 10) ? -1 : ((vx < MID_X - 10) ? 1 : 0);
  vy = (vy > MID_Y + 10) ? 1 : ((vy < MID_Y - 10) ? -1 : 0);
  x = x + vx;
  x = (x < 0) ? 0 : ((x > 10 - sizes[5]) ? (10 - sizes[5]) : x);
  y = y + vy;
  y = (y < 0) ? 0 : ((y > 20 - sizes[5]) ? (20 - sizes[5]) : y);
  score += 100000;
  print_bit_matrix(5, rotation, x, y);
  print_number(score, 0, 6);
  print_next(kappa % 7);

  display.display();
  delay(100);

  clear_bit_matrix(5, rotation, x, y);
  //clear_next(kappa % 7);
  kappa++;
}

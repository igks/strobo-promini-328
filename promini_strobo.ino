#include <Arduino.h>

int RR = 2; // Merah kanan
int RB = 3; // Biru kanan
int LR = 4; // Merah kiri
int LB = 5; // Biru kiri
int NA = 13;
int on = HIGH;
int off = LOW;
int repeat = 15;
int delays = 100;

void setup()
{
  pinMode(RR, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LR, OUTPUT);
  pinMode(LB, OUTPUT);
}

void strobo(int ArrState[])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      digitalWrite(ArrState[j], on);
    }
    delay(30);
    digitalWrite(RR, off);
    digitalWrite(RB, off);
    digitalWrite(LR, off);
    digitalWrite(LB, off);
    digitalWrite(NA, off);
    delay(30);
  }
}

void variasi(int state1[], int state2[], int d)
{
  for (int i = 0; i < repeat; i++)
  {
    strobo(state1);
    delay(d);
    strobo(state2);
    delay(d);
  }
}

int buff[][9] = {
    {LB, RB, LR, RR, LB, RB, LR, RR, 150}, // SEMUA
    {LR, RR, NA, NA, LR, RR, NA, NA, 150}, // MERAH
    {LB, RB, NA, NA, LB, RB, NA, NA, 150}, // BIRU
    {LB, RB, NA, NA, LR, RR, NA, NA, 70},  // MERAH-BIRU
    {RR, LB, NA, NA, LR, RB, NA, NA, 70},  // SILANG
    {LR, LB, NA, NA, RR, RB, NA, NA, 70},  // MERAH-BIRU KIRI KANAN
    {LR, NA, NA, NA, RR, NA, NA, NA, 70},  // MERAH KIRI KANAN
    {LB, NA, NA, NA, RB, NA, NA, NA, 70}   // BIRU KIRI KANAN
};

void loop()
{
  int buffSize = sizeof(buff) / sizeof(buff[0]);
  int index = 0;

  while (index < buffSize)
  {
    int stateA[] = {buff[index][0], buff[index][1], buff[index][2], buff[index][3]};
    int stateB[] = {buff[index][4], buff[index][5], buff[index][6], buff[index][7]};

    variasi(stateA, stateB, buff[index][8]);
    index++;
    delay(delays);
  }
}
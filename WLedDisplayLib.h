#ifndef WLEDDISPLAYLIB_H
#define WLEDDISPLAYLIB_H
#include <Arduino.h>
void write(int x, int y , int z);
void brightness(byte b);
void clear();
void fill();
void Random();
void onebyone(int d);
void VM(int x);
void hearts();
void letters();
void checkers();
void sin(int n);
extern byte itr[8];
extern byte alphabet[27][8];
extern byte smallAlphabet[27][8];
#endif
/*Write function names here*/
#ifndef MONOCHROMELEDCUBE_H
#define MONOCHROMELEDCUBE_H
#include <Arduino.h>
#include "LedControl.h"
#include "MonoChromeLedCube.h"
#define CUBE_SIZE 8
extern LedControl lc;
extern byte sine[8];
extern byte isine[8];
void initialiseCube();
void clearDisplay(int i);
void clearCube();
void updateCubeBool(bool cube[CUBE_SIZE][CUBE_SIZE][CUBE_SIZE]);
void xaxis(int t);
void yaxis(int t);
void zaxis(int t);
void set1(int x, int y, int z, bool state);
void sphereFormCollapse();
void drawCube(int startX, int startY, int startZ, int size, int state);
void randomOne();
void draw_sphere(int radius, int center_x, int center_y, int center_z, bool state);
void draw_circle(int radius, int center_x, int center_y, int z_level);
void blink(int d);
void sin();
void screenFill();
void screenTest(int t);
void drawSquare(int x, int y, int height, int size, bool state);
void drawHollowSquare(int x, int y, int height, int size, bool state);
extern byte alphabet[27][8];
void setRow(int addr, int row, byte b);
void showText(const char* t,int d, int th);
int* stringToAlphabetIndices(const char* str);
byte reverseByte(byte b);
void pyramid(int t);
void upsideDownPyramid(int t);
void cubeExpand(int d);
byte invertBits(byte b);
void wipe(int d);
void wipeReverse(int d);
void slantPlanes(int choice, int d);
void wipeVerticalUp(int d);
void wipeVerticalDown(int d);
void cubeCollapse(int d);
void straightPlanes(int d);
void drawHollowCube(int startX, int startY, int startZ, int size, int state);
#endif
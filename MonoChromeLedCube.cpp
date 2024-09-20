/*Write how functions work here*/
#include "MonoChromeLedCube.h"
#include "LedControl.h"
#define CUBE_SIZE 8
LedControl lc = LedControl(12, 11, 10, CUBE_SIZE);
byte alphabet[27][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0B00110000, 0B01111000, 0B11001100, 0B11001100, 0B11111100, 0B11001100, 0B11001100, 0B00000000},
                        {0B11111100, 0B01100110, 0B01100110, 0B01111100, 0B01100110, 0B01100110, 0B11111100, 0B00000000},
                        {0B00111100, 0B01100110, 0B11000000, 0B11000000, 0B11000000, 0B01100110, 0B00111100, 0B00000000},
                        {0B11111000, 0B01101100, 0B01100110, 0B01100110, 0B01100110, 0B01101100, 0B11111000, 0B00000000},
                        {0B11111110, 0B01100010, 0B01101000, 0B01111000, 0B01101000, 0B01100010, 0B11111110, 0B00000000},
                        {0B11111110, 0B01100010, 0B01101000, 0B01111000, 0B01101000, 0B01100000, 0B11110000, 0B00000000},
                        {0B00111100, 0B01100110, 0B11000000, 0B11000000, 0B11001110, 0B01100110, 0B00111110, 0B00000000},
                        {0B11001100, 0B11001100, 0B11001100, 0B11111100, 0B11001100, 0B11001100, 0B11001100, 0B00000000},
                        {0B01111000, 0B00110000, 0B00110000, 0B00110000, 0B00110000, 0B00110000, 0B01111000, 0B00000000},
                        {0B00011110, 0B00001100, 0B00001100, 0B00001100, 0B11001100, 0B11001100, 0B01111000, 0B00000000},
                        {0B11110110, 0B01100110, 0B01101100, 0B01111000, 0B01101100, 0B01100110, 0B11110110, 0B00000000},
                        {0B11110000, 0B01100000, 0B01100000, 0B01100000, 0B01100010, 0B01100110, 0B11111110, 0B00000000},
                        {0B11000110, 0B11101110, 0B11111110, 0B11111110, 0B11010110, 0B11000110, 0B11000110, 0B00000000},
                        {0B11000110, 0B11100110, 0B11110110, 0B11011110, 0B11001110, 0B11000110, 0B11000110, 0B00000000},
                        {0B00111000, 0B01101100, 0B11000110, 0B11000110, 0B11000110, 0B01101100, 0B00111000, 0B00000000},
                        {0B11111100, 0B01100110, 0B01100110, 0B01111100, 0B01100000, 0B01100000, 0B11110000, 0B00000000},
                        {0B01111000, 0B11001100, 0B11001100, 0B11001100, 0B11011100, 0B01111000, 0B00011100, 0B00000000},
                        {0B11111100, 0B01100110, 0B01100110, 0B01111100, 0B01101100, 0B01100110, 0B11110110, 0B00000000},
                        {0B01111000, 0B11001100, 0B11100000, 0B01110000, 0B00011100, 0B11001100, 0B01111000, 0B00000000},
                        {0B11111100, 0B10110100, 0B00110000, 0B00110000, 0B00110000, 0B00110000, 0B01111000, 0B00000000},
                        {0B11001100, 0B11001100, 0B11001100, 0B11001100, 0B11001100, 0B11001100, 0B11111100, 0B00000000},
                        {0B11001100, 0B11001100, 0B11001100, 0B11001100, 0B11001100, 0B01111000, 0B00110000, 0B00000000},
                        {0B11000110, 0B11000110, 0B11000110, 0B11010110, 0B11111110, 0B11101110, 0B11000110, 0B00000000},
                        {0B11000110, 0B11000110, 0B01101100, 0B00111000, 0B00111000, 0B01101100, 0B11000110, 0B00000000},
                        {0B11001100, 0B11001100, 0B11001100, 0B01111000, 0B00110000, 0B00110000, 0B01111000, 0B00000000},
                        {0B11111110, 0B11000110, 0B10001100, 0B00011000, 0B00110010, 0B01100110, 0B11111110, 0B00000000}};
void initialiseCube()
{
  for (int i = 0; i < lc.getDeviceCount(); i++)
  {
    lc.shutdown(i, false);
    lc.setIntensity(i, 15);
    lc.clearDisplay(i);
  }
}
void clearDisplay(int i)
{
  lc.clearDisplay(i);
}
void clearCube()
{
  for (int i = 0; i < CUBE_SIZE; i++)
  {
    lc.clearDisplay(i);
  }
}
void setRow(int addr, int row, byte b)
{
  lc.setRow(addr, row, b);
}
void updateCubeBool(bool cube[CUBE_SIZE][CUBE_SIZE][CUBE_SIZE])
{
  for (int x = 0; x < CUBE_SIZE; x++)
  {
    for (int y = 0; y < CUBE_SIZE; y++)
    {
      for (int z = 0; z < CUBE_SIZE; z++)
      {
        set1(x, y, z, cube[x][y][z]);
      }
    }
  }
}
void xaxis(int t)
{
  for (int i = 0; i < 8; i++)
  {
    set1(i, 0, 0, 1);
    delay(t);
    set1(i, 0, 0, 0);
    delay(t);
  }
}
void yaxis(int t)
{
  for (int i = 0; i < 8; i++)
  {
    set1(0, i, 0, 1);
    delay(t);
    set1(0, i, 0, 0);
    delay(t);
  }
}
void zaxis(int t)
{
  for (int i = 0; i < 8; i++)
  {
    set1(0, 0, i, 1);
    delay(t);
    set1(0, 0, i, 0);
    delay(t);
  }
}
void set1(int x, int y, int z, bool state)
{
  lc.setLed(y, z, x, state);
}
void sphereFormCollapse()
{
  int x[3];
  for (int i = 0; i < 3; i++)
  {
    // x[i] = random(3, 5);
    x[i] = random(0, 8);
  }
  for (int i = 0; i < 9; i++)
    draw_sphere(i, x[0], x[1], x[2], 1);
  for (int i = 0; i < 9; i++)
    draw_sphere(i, x[0], x[1], x[2], 0);
}
void drawCube(int startX, int startY, int startZ, int size, int state)
{
  for (int x = 0; x < size; x++)
  {
    for (int y = 0; y < size; y++)
    {
      for (int z = 0; z < size; z++)
      {
        set1(startX + x, startY + y, startZ + z, state);
      }
    }
  }
}
byte sine[8] = {0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001};
byte isine[8] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000};
void randomOne()
{
  lc.setRow(random(0, 8), random(0, 8), sine[random(0, 8)]);

  // lc.setRow(random(0, 8), random(0, 8), random(0, 0xff));
  lc.setIntensity(random(0, 8), random(0, 16));
}
void draw_sphere(int radius, int center_x, int center_y, int center_z, bool state)
{
  for (int x = 0; x < CUBE_SIZE; x++)
  {
    for (int y = 0; y < CUBE_SIZE; y++)
    {
      for (int z = 0; z < CUBE_SIZE; z++)
      {
        // Calculate the distance from the center
        double distance = sqrt((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) + (z - center_z) * (z - center_z));

        // If the distance is within the radius, turn the LED on
        if (distance <= radius)
        {
          lc.setLed(y, z, x, state);
        }
        else
        {
          lc.setLed(y, z, x, !state);
        }
      }
    }
  }
}
void draw_circle(int radius, int center_x, int center_y, int z_level)
{
  for (int x = 0; x < CUBE_SIZE; x++)
  {
    for (int y = 0; y < CUBE_SIZE; y++)
    {
      // Calculate the distance from the center (ignoring the Z axis)
      double distance = sqrt((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y));

      // If the distance is within the radius, turn the LED on
      if (distance <= radius)
      {
        lc.setLed(x, y, z_level, 1);
      }
      else
      {
        lc.setLed(x, y, z_level, 0);
      }
    }
  }
}
void blink(int d)
{
  for (int i = 0; i < lc.getDeviceCount(); i++)
  {
    for (int j = 0; j < 8; j++)
    {
      lc.setRow(i, j, 255);
    }
  }
  for (int i = 0; i < 16; i++)
  {
    for (int j = 0; j < lc.getDeviceCount(); j++)
    {
      lc.setIntensity(j, i);
    }
    delay(d);
  }
  for (int i = 15; i > -1; i--)
  {
    for (int j = 0; j < lc.getDeviceCount(); j++)
    {
      lc.setIntensity(j, i);
    }
    delay(d);
  }
}
void sin()
{
  for (int x = lc.getDeviceCount(); x > -1; x--)
  {
    for (int i = 0; i < 8; i++)
    {
      lc.setRow(x, i, sine[i]);
    }
  }
  for (int j = 0; j < 8; j++)
  {
    sine[j] = (sine[j] * 2 + isine[j] / 128);
    isine[j] = (isine[j] * 2 + (sine[j] / 128));
  }
}
void screenFill()
{
  for (int i = 0; i < lc.getDeviceCount(); i++)
  {
    for (int j = 0; j < 8; j++)
    {
      lc.setRow(i, j, 255);
    }
  }
}
void screenTest(int t)
{
  for (int x = 0; x < 8; x++)
  {
    for (int z = 0; z < lc.getDeviceCount(); z++)
    {
      lc.setRow(z, x, 0xff);
    }
    delay(t);
  }
  for (int x = 0; x < 8; x++)
  {
    for (int z = 0; z < lc.getDeviceCount(); z++)
    {
      lc.setRow(z, x, 0x00);
    }
    delay(t);
  }
}
void drawSquare(int x, int y, int height, int size, bool state)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      set1(x + i, y + j, height, state);
    }
  }
}
void drawHollowSquare(int x, int y, int height, int size, bool state)
{
  for (int i = 0; i < size; i++)
  {
    set1(x + i, y, height, state);
    set1(x + i, y + size - 1, height, state);
  }
  for (int j = 0; j < size; j++)
  {
    set1(x, y + j, height, state);
    set1(x + size - 1, y + j, height, state);
  }
}
void showText(const char *t, int d, int th){
  int x = 0;
  const char *text = t;
  int *indices = stringToAlphabetIndices(text);
  int length = strlen(text);
  for (int j = 0; j < length; j++)
  {
    for (int k = 0; k < 8 + th; k++)
    {
      for (int i = 0; i < 8; i++)
      {
        clearDisplay(k - th);
        setRow(k, i, reverseByte(alphabet[indices[j]][7 - i]));
      }
      delay(d);
    }
  }
}
int *stringToAlphabetIndices(const char *str){
  static int indices[100];
  int length = strlen(str);

  for (int i = 0; i < length; i++)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      indices[i] = str[i] - 'A' + 1;
    }
    else
    {
      indices[i] = 0;
    }
  }

  return indices;
}
byte reverseByte(byte b)
{
  byte reversed = 0;
  for (int i = 0; i < 8; i++)
  {
    reversed |= ((b >> i) & 0x01) << (7 - i);
  }
  return reversed;
}
void pyramid(int t)
{
  for (int i = 0; i < 4; i++)
  {
    drawHollowSquare(i, i, 2 * i, 8 - (2 * i), 1);
    delay(t);
    drawHollowSquare(i, i, 2 * (i) + 1, 8 - (2 * i), 1);
    delay(t);
  }
}
void upsideDownPyramid(int t)
{
  for (int i = 0; i < 4; i++)
  {
    drawHollowSquare(i, i, 7 - 2 * i, 8 - (2 * i), 1);
    delay(t);
    drawHollowSquare(i, i, 6 - 2 * i, 8 - (2 * i), 1);
    delay(t);
  }
}
void cubeExpand(int d)
{
  int x[3] = {0, 0, 0};
  // for (int i = 0; i < 3; i++)
  // {
  //   // x[i] = random(3, 5);
  //   x[i]= random(0,8);
  // }
  for (int i = 0; i < 9; i++)
  {
    drawCube(x[0], x[1], x[2], i, 1);
    delay(d);
  }
}
void cubeCollapse(int d)
{
  int x[3] = {0, 0, 0};
  // for (int i = 0; i < 3; i++)
  // {
  //   // x[i] = random(3, 5);
  //   x[i]= random(0,8);
  // }
  for (int i = 0; i < 9; i++)
  {
    drawCube(x[0], x[1], x[2], i, 0);
    delay(d);
  }
}
byte invertBits(byte b) {
  byte inverted = 0;
  for (int i = 0; i < 8; i++) {
    inverted |= ((~b >> i) & 0x01) << i;
  }
  return inverted;

}
void wipe(int d)
{
  for (int i = 0; i < 8; i++)
  {
    lc.clearDisplay(i);
    delay(d);
  }
}
void wipeReverse(int d)
{
  for (int i = 7; i > -1; i--)
  {
    lc.clearDisplay(i);
    delay(d);
  }
}
void slantPlanes(int choice, int d)
{
  if (choice == 0)
  {
    for (int t = -7; t <= 8; t++)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, x == (y - t));
          }
        }
      }
    }
  }
  if (choice == 1)
  {
    for (int t = -7; t <= 8; t++)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, y == (x - t));
          }
        }
      }
    }
  }
  if (choice == 2)
  {
    for (int t = -7; t <= 8; t++)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, y == (z - t));
          }
        }
      }
    }
  }
  if (choice == 3)
  {
    for (int t = -7; t <= 8; t++)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, z == (y - t));
          }
        }
      }
    }
  }
  if (choice == 4)
  {
    for (int t = -7; t <= 8; t++)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, z == (x - t));
          }
        }
      }
    }
  }
  if (choice == 5)
  {
    for (int t = -7; t <= 8; t++)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, x == (z - t));
          }
        }
      }
    }
  }
}
void wipeVerticalUp(int d)
{
  for (int j = 0; j < 8; j++)
  {
    for (int i = 0; i < 8; i++)
    {
      setRow(i, j, 0);
    }
    delay(d);
  }
}
void wipeVerticalDown(int d)
{
  for (int j = 7; j > -1; j--)
  {
    for (int i = 0; i < 8; i++)
    {
      setRow(i, j, 0);
    }
    delay(d);
  }
}
void straightPlanes(int d)
{

  for (int x = 0; x < 8; x++)
  {
    for (int y = 0; y < 8; y++)
    {
      setRow(x, y, 0xFF); // Turn on all LEDs in the row
    }
    delay(d);
    for (int y = 0; y < 8; y++)
    {
      setRow(x, y, 0x00); // Turn off all LEDs in the row
    }
  }
  for (int x = 7; x >= 0; x--)
  {
    for (int y = 0; y < 8; y++)
    {
      setRow(x, y, 0xFF); // Turn on all LEDs in the row
    }
    delay(d);
    for (int y = 0; y < 8; y++)
    {
      setRow(x, y, 0x00); // Turn off all LEDs in the row
    }
  }

  for (int y = 0; y < 8; y++)
  {
    for (int x = 0; x < 8; x++)
    {
      setRow(x, y, 0xFF); // Turn on all LEDs in the row
    }
    delay(d);
    for (int x = 0; x < 8; x++)
    {
      setRow(x, y, 0x00); // Turn off all LEDs in the row
    }
  }
  for (int y = 7; y >= 0; y--)
  {
    for (int x = 7; x >= 0; x--)
    {
      setRow(x, y, 0xFF); // Turn on all LEDs in the row
    }
    delay(d);
    for (int x = 7; x >= 0; x--)
    {
      setRow(x, y, 0x00); // Turn off all LEDs in the row
    }
  }
  byte t = 0b00000001;
  for (int k = 0; k < 7; k++)
  {

    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        setRow(i, j, t);
      }
    }
    delay(d);
    t = t << 1;
  }
  for (int k = 0; k < 9; k++)
  {

    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
      {
        setRow(i, j, t);
      }
    }
    delay(d);
    t = t >> 1;
  }
}
void drawHollowCube(int startX, int startY, int startZ, int size, int state)
{
  // Draw the edges of the cube
  for (int i = 0; i < size; i++)
  {
    // Bottom face
    set1(startX + i, startY, startZ, state);
    set1(startX + i, startY + size - 1, startZ, state);
    set1(startX, startY + i, startZ, state);
    set1(startX + size - 1, startY + i, startZ, state);

    // Top face
    set1(startX + i, startY, startZ + size - 1, state);
    set1(startX + i, startY + size - 1, startZ + size - 1, state);
    set1(startX, startY + i, startZ + size - 1, state);
    set1(startX + size - 1, startY + i, startZ + size - 1, state);

    // Vertical edges
    set1(startX, startY, startZ + i, state);
    set1(startX + size - 1, startY, startZ + i, state);
    set1(startX, startY + size - 1, startZ + i, state);
    set1(startX + size - 1, startY + size - 1, startZ + i, state);
  }
}
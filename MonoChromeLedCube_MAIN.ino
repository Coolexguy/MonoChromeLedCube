#include "LedControl.h"
#include "MonoChromeLedCube.h"
#define CUBE_SIZE 8
// LedControl lc = LedControl(12, 11, 10, CUBE_SIZE);  //data=12,clock=13,cs=10,displays
void setup()
{
  initialiseCube();
  pinMode(A0, INPUT);
  randomSeed(analogRead(A0));
  // Serial.begin(9600);
}

/* Important points:
  - Convert 3d boolean array to 2d byte array.
*/

// bool cube[8][8][8];
// int t = -8;
void loop()
{
  // for(int i = 0 ; i < 12 ; i++)
  // slantPlanes(0, 1000);
  // slantPlanes(6);

  // slantPlanes(3);
  // slantPlanes(6);
  // for (int t = 8; t > -9; t--) {
  //   for (int x = 0; x < 8; x++) {
  //     for (int y = 0; y < 8; y++) {
  //       for (int z = 0; z < 8; z++) {
  //         set1(x, y, z, x == (y - t));
  //       }
  //     }
  //   }
  // }
  // for (int i = 0; i < 8; i++) {
  //   clearDisplay(i);
  // }
  // for (int t = -7; t < 8; t++) {
  //   for (int x = 0; x < 8; x++) {
  //     for (int y = 0; y < 8; y++) {
  //       // set1(x, y, (int)(2.5 * sin(x + y + t) + 4), 1);
  //       for (int z = 0; z < 8; z++) {
  //         set1(x, y, z, z == (y - t));
  //       }
  //     }
  //   }
  // }
  // t++;
  // delay(10);
  // xaxis(10);
  // yaxis(10);
  // zaxis(10);

  // for (int x = 0; x < CUBE_SIZE; x++) {
  //   for (int y = 0; y < CUBE_SIZE; y++) {
  //     for (int z = 0; z < CUBE_SIZE; z++) {
  //       // set1(x, y, z, cube[x][y][z]);
  //       cube[x][y][z]=0;
  //     }
  //   }
  // }

  // screenFill();
  // draw_circle(3,3,3,3);
  // screenTest(0);
  // blink(100);
  // sin();
  // delay(50);
  // lc.setLed(0, 0, 0, 1);
  // randomOne();

  // for(int i = 0 ; i < 8 ; i++)
  // lc.setIntensity(i,random(0,16));

  // sphereFormCollapse();

  // pyramid();
const char* text = "RATNA";
  int* indices = stringToAlphabetIndices(text);
  int length = strlen(text);
  for (int j = 0; j < length; j++) {
    for (int k = 0; k < 10; k++) {
      for (int i = 0; i < 8; i++) {
        clearDisplay(k - 2);
        setRow(k, i, reverseByte(alphabet[indices[j]][7 - i]));
      }
      delay(100);
    }
  }
}
int* stringToAlphabetIndices(const char* str) {
  static int indices[100];
  int length = strlen(str);
  
  for (int i = 0; i < length; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      indices[i] = str[i] - 'A' + 1; 
    } else {
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
void pyramid()
{
  for (int i = 0; i < 4; i++)
  {
    drawHollowSquare(i, i, 2 * i, 8 - (2 * i), 1);
    drawHollowSquare(i, i, 2 * (i) + 1, 8 - (2 * i), 1);
  }
}

void slantPlanes(int choice, int d)
{
  if (choice == 0)
  {
    for (int t = -7; t <= 7; t++)
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
  else if (choice == 1)
  {
    for (int t = -7; t < 8; t++)
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
  else if (choice == 2)
  {
    for (int t = -7; t < 8; t++)
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
  else if (choice == 3)
  {
    for (int t = -7; t < 8; t++)
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
  else if (choice == 4)
  {
    for (int t = -7; t < 8; t++)
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
  else if (choice == 5)
  {
    for (int t = -7; t < 8; t++)
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

  else if (choice == 6)
  {
    for (int t = 7; t > -8; t--)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, x == (y - t)); //
          }
        }
      }
    }
  }
  else if (choice == 7)
  {
    for (int t = 7; t > -8; t--)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, y == (z + t));
          }
        }
      }
    }
  }
  else if (choice == 8)
  {
    for (int t = 7; t > -8; t--)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, z == (x + t));
          }
        }
      }
    }
  }
  else if (choice == 9)
  {
    for (int t = 7; t > -8; t--)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, y == (x + t));
          }
        }
      }
    }
  }
  else if (choice == 10)
  {
    for (int t = 7; t > -8; t--)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, z == (y + t));
          }
        }
      }
    }
  }
  else if (choice == 11)
  {
    for (int t = 7; t > -8; t--)
    {
      delay(d);
      for (int x = 0; x < 8; x++)
      {
        for (int y = 0; y < 8; y++)
        {
          for (int z = 0; z < 8; z++)
          {
            set1(x, y, z, x == (z + t));
          }
        }
      }
    }
  }
}
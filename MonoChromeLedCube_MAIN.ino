#include "LedControl.h"
#include "MonoChromeLedCube.h"
#define CUBE_SIZE 8
void setup()
{
  initialiseCube();
  pinMode(A0, INPUT);
  randomSeed(analogRead(A0));
  Serial.begin(9600);
}

/* Important points:
  - Convert 3d boolean array to 2d byte array.
*/


void loop()
{

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
  // screenFill();
  // randomOne();
  // blink(100);

  // runtime();

  bool cube1[8][8][8];
  byte cube2[8][8];
  for (int x = 0; x < 8; x++)
  {
    for (int y = 0; y < 8; y++)
    {
      for (int z = 0; z < 8; z++)
      {
        cube1[x][y][z] = (x==0 && y==0)?1:0;
      }
    }
  }
  Bool3DToByte2D(cube1, cube2);
  displayByteArray(cube2);

  // for (int x = 0; x < 8; x++)
  // {
  //   for (int y = 0; y < 8; y++)
  //   {
  //     for (int z = 0; z < 8; z++)
  //     {
  //       set1(x, y, z, 1);
  //     }
  //   }
  // }
  // Serial.print(":");
  // Serial.println(millis() - prev);
  // delay(1000);
  // xaxis(50);
}

void displayByteArray(byte result[CUBE_SIZE][CUBE_SIZE])
{
  for (int i = 0; i < CUBE_SIZE; i++)
  {
    for (int j = 0; j < CUBE_SIZE; j++)
    {
      setRow(i, j, result[i][j]);
    }
  }
}

void runtime()
{
  // SEQUENCE
  xaxis(50);
  yaxis(50);
  zaxis(50);

  showText("RISC", 50, 3);

  for (int i = 0; i < 2500; i++)
    randomOne();
  clearCube();
  // wipe(100);
  for (int i = 0; i < 8; i++)
  {
    lc.setIntensity(i, 15);
  }
  for (int i = 0; i < 50; i++)
  {
    sin();
    delay(50);
  }
  // clearCube();
  wipe(50);
  pyramid(100);
  wipeVerticalUp(100);
  upsideDownPyramid(100);
  delay(100);
  // clearCube();
  wipeVerticalDown(100);
  for (int t = 0; t < 50; t++)
  {
    for (int x = 0; x < 8; x++)
    {
      for (int y = 0; y < 8; y++)
      {
        set1(x, y, (int)(4 * sin(x + y + t - 1) + 4), 0);
        set1(x, y, (int)(4 * sin(x + y + t) + 4), 1);
      }
    }
    delay(50);
  }
  for (int i = 0; i < 4; i++)
  {
    sphereFormCollapse();
  }
  clearCube();
  cubeExpand(250);
  cubeCollapse(250);
  for (int k = 0; k < 2; k++)
  {
    for (int i = 0; i < 4; i++)
    {
      drawHollowCube(3 - i, 3 - i, 3 - i, 2 + (i * 2), 1);
      delay(100);
      drawHollowCube(3 - i, 3 - i, 3 - i, 2 + (i * 2), (i == 3) ? 1 : 0);
    }
    for (int i = 3; i >= 0; i--)
    {
      drawHollowCube(3 - i, 3 - i, 3 - i, 2 + (i * 2), 1);
      delay(100);
      drawHollowCube(3 - i, 3 - i, 3 - i, 2 + (i * 2), (i == 0) ? 1 : 0);
    }
  }
  int r = random(0, 3);
  slantPlanes(r * 2, 0);
  slantPlanes((r * 2) + 1, 0);
  wipe(100);
  straightPlanes(30);
  delay(100);
  for (int k = 0; k < 2; k++)
  {
    for (int i = 0; i < 4; i++)
    {
      drawHollowCube(3 - i, 3 - i, 3 - i, (i + 1) * 2, 1);
      delay(100);
    }
    for (int i = 3; i >= 0; i--)
    {
      drawHollowCube(3 - i, 3 - i, 3 - i, (i + 1) * 2, 0);
      delay(100);
    }
  }
  for (int k = 0; k < 2; k++)
  {

    for (int t = 0; t < 3; t += 2)
    {

      for (int i = 0; i < 8; i++)
      {
        drawHollowSquare(t, t, i, 8 - (t * 2), 1);
        delay(25);
        drawHollowSquare(t, t, i, 8 - (t * 2), 0);
      }
      for (int j = 7; j >= 0; j--)
      {
        drawHollowSquare(t + 1, t + 1, j, 6 - (t * 2), 1);
        delay(25);
        drawHollowSquare(t + 1, t + 1, j, 6 - (t * 2), 0);
      }
    }
    for (int t = 0; t < 4; t += 2)
    {

      for (int i = 0; i < 8; i++)
      {
        drawHollowSquare(3 - t, 3 - t, i, 2 + 2 * t, 1);
        delay(25);
        drawHollowSquare(3 - t, 3 - t, i, 2 + 2 * t, 0);
      }
      for (int i = 7; i >= 0; i--)
      {
        drawHollowSquare(2 - t, 2 - t, i, 4 + 2 * t, 1);
        delay(25);
        drawHollowSquare(2 - t, 2 - t, i, 4 + 2 * t, 0);
      }
    }
  }

}

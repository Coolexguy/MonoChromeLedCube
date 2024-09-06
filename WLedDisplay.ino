// Register1 : -ve
// Register2 : +ve at end
// Register3 : +ve at middle
#include "WLedDisplayLib.h"
#define data1 12
#define latch1 11 // register1
#define clock1 10

#define data2 9
#define latch2 8 // register2
#define clock2 7

#define data3 6
#define latch3 5 // register3
#define clock3 4

#define brightnessPin 3 // pwm pin attached to register1
String Str = "";

void setup()
{
  Serial.begin(9600);
  for (int k = 3; k <= 12; k++)
  {
    pinMode(k, OUTPUT);
  }
  for (int k = 5; k <= 11; k += 3)
  {
    digitalWrite(k, HIGH);
  }
  // pinMode(data1, OUTPUT);
  // pinMode(data2, OUTPUT);
  // pinMode(data3, OUTPUT);

  // pinMode(latch1, OUTPUT);
  // pinMode(latch2, OUTPUT);
  // pinMode(latch3, OUTPUT);

  // pinMode(clock1, OUTPUT);
  // pinMode(clock2, OUTPUT);
  // pinMode(clock3, OUTPUT);

  // pinMode(brightnessPin, OUTPUT);  //Initialising the pins

  // digitalWrite(latch1, HIGH);
  // digitalWrite(latch2, HIGH);  //latch pins high initially
  // digitalWrite(latch3, HIGH);
  brightness(255);            // full brightness initially
  randomSeed(analogRead(A0)); // random func seed
}
  byte temp1[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  byte temp2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  // int l = 7;
void loop()
{
  // if (Serial.available() > 0)
  // {

  //   Str = Serial.readString();
  //   Str.toUpperCase();
  //   Serial.print("Text to be printed: ");
  //   Serial.println(Str);
  //   int f[Str.length() - 1];
  //   for (int i = 0; i < Str.length(); i++)
  //   {
  //     f[i] = Str[i] - 64;
  //     Serial.println(f[i]);
  //   }
  //   byte temp1[8];
  //   byte temp2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  //   for (int i = 0; i < 8; i++)
  //   {
  //     temp1[i] = alphabet[1][i];
  //   }
  //   for (int i = 0; i < 8; i++)
  //   {
  //     temp2[i] = temp2[i] * 2 + temp1[i] / 128;
  //     for (int k = 0; k < 100; k++)
  //     {
  //       write(itr[i], temp2[i], temp1[i]);
  //       delay(1);
  //     }
  //   }
  // }
/*  int f[3] = {1, 2, 3};
for(int j = 0 ;j < 3 ;j++ ){  
for(int l = 7 ; l >= -8 ; l--){
if(l>=0){
  for (int i = 0; i < 8; i++)
  {
    temp1[i] = alphabet[f[j]][i]/pow(2,l);
  }
}


  for (int k = 0; k < 100; k++)
  {
    for (int i = 0; i < 8; i++)
    {
      write(itr[i], temp2[i], temp1[i]);
    }
    delay(1);
  }
  for (int i = 0; i < 8; i++)
  {
    temp2[i] = temp2[i] * 2 + temp1[i] / 128;
    temp1[i] = temp1[i] * 2;
  }
}
}*/
// l--;

// sin(5);
write(0b11111111,0b11111111,0b11111111);
}
// checkers();
// onebyone(100);
// hearts();
// letters();
// shift last bit of z to y,

// power supply
// for (int i = 0; i < Str.length()-1; i++)
//     {
//       byte temp[8];

//         Serial.println(f[i]);

//       for(int ii = 0 ; ii < 8 ; ii++){
//       temp[ii] = alphabet[t][ii];
//      }
//      for(int v = 7 ; v > -7 ; v--){
//       for(int iii = 0 ; iii <300 ; iii++){
//         for(int iv = 0 ; iv < 8 ; iv++){
//           if(v>=0){
//           write(itr[iv],0,temp[iv]>>v);
//           }
//           else{

//             write(itr[iv],0,temp[iv]<<-v);
//           }
//         }
//       }
//     }
//     }
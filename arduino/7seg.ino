//---------------------------------------------------------------
// Arduino 7Segment LED
//---------------------------------------------------------------
// 参考URL: http://deviceplus.jp/hobby/entry008/
// 2番ピンから8番ピンまでを使用する。pinモード切替と出力方法など。
//---------------------------------------------------------------

boolean Num_Array[16][7] =
{
  {LOW, LOW, LOW, LOW, LOW, LOW, HIGH},     //0
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH}, //1
  {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW},    //2
  {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW},    //3
  {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW},   //4
  {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW},    //5
  {LOW, HIGH, LOW, LOW, LOW, LOW, LOW},     //6
  {LOW, LOW, LOW, HIGH, HIGH, LOW, HIGH},   //7
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW},      //8
  {LOW, LOW, LOW, LOW, HIGH, LOW, LOW},     //9

  {LOW, LOW, LOW, HIGH, LOW, LOW, LOW},     //A
  {HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},    //b
  {LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH},   //C
  {HIGH, LOW, LOW, LOW, HIGH, HIGH, LOW},   //d
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},    //E
  {LOW, HIGH, HIGH, HIGH, LOW, LOW, LOW},   //F
};

boolean Pattern[8][7] =
{
  {LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},  //a
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},  //b
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  //g
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH},  //e
  {HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH},  //d
  {HIGH, HIGH, LOW, HIGH, HIGH, HIGH, HIGH},  //c
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  //g
  {HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH},  //f
};

void setup()
{
 for (int i = 2; i < 9; i++) {
   pinMode(i, OUTPUT);
 } 

 pinMode(10, INPUT);
}

void Num(int Number)
{
  for (int w = 0; w <= 7; w++)
  {
    digitalWrite(w+2, Num_Array[Number][w]);
  }
}

void on()
{
  for (int i = 2; i < 9; i++) {
    digitalWrite(i, LOW);
  }
}

void off()
{
  for (int i = 2; i < 9; i++) {
    digitalWrite(i, HIGH);
  }
}

void Effect(int idx)
{
  digitalWrite(2, Pattern[idx][0]);
  digitalWrite(3, Pattern[idx][1]);
  digitalWrite(4, Pattern[idx][2]);
  digitalWrite(5, Pattern[idx][3]);
  digitalWrite(6, Pattern[idx][4]);
  digitalWrite(7, Pattern[idx][5]);
  digitalWrite(8, Pattern[idx][6]);
}

void loop()
{
  int waitTimer = 250;

  /*
  for (int i = 0; i < 10; i++)
  {
    Num(i);
    delay(waitTimer);
  }
  */

  off();

  /*
  for (int i = 0; i < 8; i++)
  {
    Effect(i);
    delay(waitTimer);
  }
  */
}


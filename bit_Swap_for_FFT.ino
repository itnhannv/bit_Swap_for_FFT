#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define  N               128
#define  LOG_2_N         7

char *String_data = "RE";
int bitRev(int a, int nBits)
{
  int rev_a = 0;
  for (int i = 0; i < nBits; i++)
  {
    rev_a = (rev_a << 1) | (a & 1);
    a     = a >> 1;
  }
  return rev_a;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //Serial.print("//Nghich dao cho FFF %i diem\n", N);
 // Serial.print("void nghich_dao() // du lieu adc doc duoc can phai dua qua ham nay de xu li (goi ham nay 1 lan duy nhat truoc khi tinh FFT)\n{\n");
 // Serial.print("   unsigned int i;\n");
  for (int i = 0; i < N; i++)
    if (bitRev(i, LOG_2_N) > i)
    { 
      char data1[11];
       char data2[17];
        char data3[10];
      sprintf( data1, "i=%s[%3d];" , String_data, i);
      sprintf(data2 ,"%s[%3d]=%s[%3d];", String_data, i, String_data, bitRev(i, LOG_2_N));
      sprintf(data3, "%s[%3d]=i;\n"         , String_data, bitRev(i, LOG_2_N));

     Serial.print(String(data1));
     Serial.print(String(data2));
     Serial.print(String(data3));
     Serial.println();
    }
  //Serial.println("}");

}

void loop() {
  // put your main code here, to run repeatedly:

}

#include <stdio.h>
#define MEM_SIZE 100000
#define INT_VAL(temp_placeHolder) (*(int*)(&Memory[temp_placeHolder]))
#define FLOAT_VAL(temp_placeHolder) (*(float*)(&Memory[temp_placeHolder]))
char Memory[MEM_SIZE];
int Frame_Pointer;
int Stack_Pointer;
int Temp;
double Temp_F;
int main() { 
Frame_Pointer=0;
Stack_Pointer=0;
Stack_Pointer += 4;
Stack_Pointer += 8;
INT_VAL(Frame_Pointer + 0) = 3;
FLOAT_VAL(Frame_Pointer + 4) = 5.000000;
INT_VAL(Stack_Pointer) = Frame_Pointer;
Stack_Pointer += 4;
INT_VAL(Stack_Pointer) = 2;
Stack_Pointer += 4;
Frame_Pointer = Stack_Pointer -4;
f1();
Stack_Pointer -= 4;
Frame_Pointer = INT_VAL(Stack_Pointer);
FLOAT_VAL(Frame_Pointer + 4) = Temp_F;
printf("%6.4f\n",FLOAT_VAL(Frame_Pointer+4));
INT_VAL(Stack_Pointer) = Frame_Pointer;
Stack_Pointer += 4;
INT_VAL(Stack_Pointer) = INT_VAL(Frame_Pointer+0);
Stack_Pointer += 4;
Frame_Pointer = Stack_Pointer -4;
f2();
Stack_Pointer -= 4;
Frame_Pointer = INT_VAL(Stack_Pointer);
INT_VAL(Frame_Pointer + 0) = Temp;
printf("%d\n",INT_VAL(Frame_Pointer+0));
INT_VAL(Stack_Pointer) = Frame_Pointer;
Stack_Pointer += 4;
FLOAT_VAL(Stack_Pointer) = FLOAT_VAL(Frame_Pointer+4);
Stack_Pointer += 8;
Frame_Pointer = Stack_Pointer -8;
f3();
Stack_Pointer -= 4;
Frame_Pointer = INT_VAL(Stack_Pointer);
FLOAT_VAL(Frame_Pointer + 4) = Temp_F;
printf("%6.4f\n",FLOAT_VAL(Frame_Pointer+4));
Stack_Pointer -= 12;
  return 0;
}
int f1()
{
Temp_F = (INT_VAL(Frame_Pointer+0)*2.000000) ;
Stack_Pointer -= 0;
}
int f2()
{
Stack_Pointer += 4;
INT_VAL(Frame_Pointer + 4) = (INT_VAL(Frame_Pointer+0)*3) ;
Temp = INT_VAL(Frame_Pointer+4);
Stack_Pointer -= 8;
}
int f3()
{
Stack_Pointer += 8;
FLOAT_VAL(Frame_Pointer + 8) = (FLOAT_VAL(Frame_Pointer+0)*2) ;
Temp_F = FLOAT_VAL(Frame_Pointer+8);
Stack_Pointer -= 16;
}

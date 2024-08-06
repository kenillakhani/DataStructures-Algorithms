#include<stdio.h>

#define x1 1
#define x2 x1, x1
#define x4 x2, x2
#define x8 x4, x4
#define x16 x8, x8
#define x32 x16, x16

int main(void)
{
// array declaration
int num[] = { x32, x8, x4, x1}; // all elements assigned to 1 
int size = sizeof(num)/ sizeof(int); // 32+8+4+1= 45

printf("The size of the array is %d\n", size);
printf("The value of element in the array at index 5 is %d ",num[1]);

return 0;

}

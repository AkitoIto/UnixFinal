#include <stdio.h>
#include <stdlib.h>

//bonas question number 2
//this program will print all the ugly numbers from 1 - 10000

//dividing with greatest divisible power
int divide(int num, int factor)
{
   while(num%factor == 0)
   {  
     num = num/factor;
   }
   return num;
}
int isUgly(int num)
{
  num =  divide(num, 2);
  num = divide(num, 3);
  num = divide(num, 5);
  return num;
} 

int main()
{
  int i;
  printf("Printing all the ugly numbers in [1, 10000)\n\n");
  int lineCount = 1;
  printf("1, ");
  
  for(i=2; i<10000; i++)
  {
    //check
    if(isUgly(i) == 1)
    {
         printf("%d, ", i);
         lineCount++;
    }
    if(lineCount == 10)
    {
      printf("\n");
      lineCount = 0;
    } 
    
  }

  printf("\n");

 return 0;
}

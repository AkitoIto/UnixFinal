#include <stdio.h>
#include <stdlib.h>
//bonas question 3
//this program will determine whether given number is abudant, deficient, or perfect
//then calculates abudance and deficiency.
int sumAllDivisor(int num)
{
  int i;
  int sum = 0;
  for(i = 1; i <= num; i++)
  {
     if(num%i == 0)
        sum = sum + i;
  }
  return sum;
} 
int sumProperDivisor(int num)
{
  int i;
  int sum = 0;
  for(i = 1; i < num-1; i++)
  {
     if(num%i ==0)
        sum = sum + i;
  }
   return sum;
}

int isPerfect(int num)
{
   int sum;
   sum = sumProperDivisor(num);
   
   if(sum == num)
        return 1; 
   else
        return 0;
}

int isAbudant(int num)
{
   int sum;
   sum = sumProperDivisor(num);
   if(sum > num)
       return sum - num;
   else 
        return 0;
} 

int isDeficient(int num)
{
   int sum;
   sum = sumAllDivisor(num);
   num = num * 2;
   if(sum < num)
       return num - sum;
   else  
        return 0;
}

int main()
{
  int num;
  printf("Please type in the number you want to check: ");
  scanf("%d", &num);
  printf("%d is...\n", num);
  
  int check;
  check = isAbudant(num);
  if(check !=0)
     printf("Abudant, abudance is %d.\n", check);
  else 
     printf("Not abudant.\n");
     
   check = isDeficient(num);
   if(check != 0)
      printf("Deficient, deficiency is %d.\n", check);
   else
      printf("Not deficient.\n");
      
   check = isPerfect(num);
   if(check != 0)
      printf("Pefect.\n");
   else
       printf("Not perfenct.\n");
  
  
 return 0;
}
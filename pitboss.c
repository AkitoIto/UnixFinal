#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
 struct data
   {
     int n1;
     double n2;
     double n3;
     double n4;
   };
   
int main(int argc, char *argv[]){

  int option;
  int i=0;
  int num_trials[9];
  double percentage[9];
  double success[9];
  double failure[9];
  double p;
  
 //gettin arguments
  while((option= getopt(argc, argv, "p:")) != -1)
	{	
  		switch(option)
      {
       case 'p':
         p = atof(optarg);
         break;
       case '?':
          if(optopt == 'p')
          {
               fprintf(stderr, "Option -%c required\n", optopt);
               return 0;
           }
       default:
	   		printf("Invalid input\n");
     }
   }
   printf("\nReading results from %s\n", argv[3]);
   printf("\nChecking results for -p = %.2f\n", p);
   
   //reading file and finding data for percentage given
  struct data num;
   FILE *fptr;
   fptr = fopen(argv[3], "rb");
  for(i=0; i< 9; i++)
	{
     fread(&num,sizeof(struct data),1,fptr);
      num_trials[i] = num.n1;
      percentage[i] = num.n2;
      success[i] = num.n3;
      failure[i] = num.n4;
      
      //found target result
      if(percentage[i] == p)
      {
        printf("\nFound %d trials.\n", num_trials[i]);
        printf("\nSuccess - %.2f %%\n", success[i]);
        printf("Failure - %.2f %%\n", failure[i]);
        fclose(fptr);
        return 0;
      }
    }
    printf("Result was not found for -p = %.2f\n", p);
   fclose(fptr);
 
return 0;
}
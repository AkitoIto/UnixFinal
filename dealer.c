#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){

  if(argc == 1)
  {
    fprintf(stderr, "Input from command line required.\n");
    return 0;
  }
	int option;
	int isVerbose = 0;
	int num_trials;
  char* verbose = "-v";
  char* fileName;
  int isFile = 1;
  double percentage;
  
	//getting arguments from command line
	while((option= getopt(argc, argv, "p:v::o:")) != -1)
	{	
		switch(option)
	 {
	   	case 'p':
        if(strcmp(optarg, verbose) == 0)
         {
             fprintf(stderr, "Percentage required\n");
             return 0;
         }
         else
            percentage = atof(optarg);
        break;
        
	   	case 'v':
			  isVerbose = 1;
		  	break;
              
      case 'o':
          isVerbose = -1;
          num_trials = atoi(argv[5]);
          fileName = optarg;
          //file does not exist
          if(access(optarg, F_OK) == -1)
               isFile = 0;
        break;
        
		  case '?':
  	   		if(optopt == 'p' || optopt == 'o')
           {
               fprintf(stderr, "Option -%c required\n", optopt);
               return 0;
           }
           else
              fprintf(stderr, "Unknown option -%c.\n", optopt);
           break;
	   	default:
	   		printf("Invalid input\n");
		}	
 }

	//verbose option
	if(isVerbose == 1)
	{
		num_trials = atoi(argv[4]);
	}	
	else if(isVerbose == 0)
	{
		num_trials = atoi(argv[3]);
	}
 
	int i;
	pid_t pid;
  int status;
  //counts number of successes
  int sucCounter = 0;
  
  
 //verbose option
 if(isVerbose == 1)
 {
	//creating child procss
	 for(i = 0; i < num_trials; i++)
	 {
		pid = fork();
	
		if(pid > 0)
		{
      //pid represents child PID
			waitpid(pid, &status, 0);
      if(status == 0)
      {
        printf("PID %d returned failure.\n", pid);
      }
      else
      {
        sucCounter++;
        printf("PID %d returned success.\n", pid);
      }
		}
		else if(pid == 0)
		{
			execv("./hand", argv);
      exit(1);
		}
		else 
		{
			//error
			printf("Error");
		}	
	 }
 }
 
 
   //non verbose option
   else
   {
   //creating child procss
	 for(i = 0; i < num_trials; i++)
	 {
		pid = fork();
	
		if(pid > 0)
		{
      //pid represents child PID
			waitpid(pid, &status, 0);
      if(status != 0)
           sucCounter++;
		}
		else if(pid == 0)
		{
			execv("./hand", argv);
      exit(1);
		}
		else 
		{
			//error
			printf("Error");
		}	

   }
}
   
   //final result
   printf("\nCreated %d process.\n", num_trials);
   //printf("number of success: %d\n", sucCounter);
   double success = ((float)sucCounter / num_trials) * 100;
   double failure = 100 - success;
   printf("Success - %.2f %%\n", success);
   printf("Failure - %.2f %%\n", failure);
 
   struct data
   {
     int n1;
     double n2;
     double n3;
     double n4;
   };
   struct data num;
   num.n1 = num_trials;
   num.n2 = percentage;
   num.n3 = success;
   num.n4 = failure;
   
   FILE *fptr;
   //file exists, append to file
   if(isFile == 1)
        fptr = fopen(fileName, "ab");
  //create file
   else
   {
     fptr = fopen(fileName, "wb");
   }
      
   //wrting to binary file
   fwrite(&num, sizeof(struct data), 1,fptr);
   fclose(fptr);
	  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <gsl/gsl_rng.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

pid_t pid;
void pHandler(int);
void cHandler(int);

int main()
{
  //random number generator
   const gsl_rng_type * T;
   gsl_rng * r;
   gsl_rng_env_setup();
   T = gsl_rng_mt19937;
   r = gsl_rng_alloc(T);
   int sig;
   int i;
   //nano sleep
   struct timespec time1;
   time1.tv_sec = 0;
   time1.tv_nsec = 500000000L;
   //creating child process
   pid = fork();

  
  //parent
  if(pid > 0)
  {
    for(i = 1; i < 32; i++)
    {
      signal(i, pHandler);
    }
    //seeding GSL random number generator
    gsl_rng_set(r, pid);
    sleep(1);
     
    while(1)
    {  //randomly generating num 0-31
       sig = gsl_rng_uniform_int(r, 32);
       //0 exclusive
       if(sig == 0)
             sig++;
      printf("Parent sending signal %d\n", sig);
      kill(pid,sig);
      nanosleep(&time1, NULL);
     }
  }
  //child
  else if(pid == 0)
  {
    for(i = 1; i < 32; i++)
    {
      signal(i, cHandler);
    }
    while(1)
    {
      printf("Child waiting.\n");
      
      nanosleep(&time1, NULL);
    }
   }
  else{ printf("error\n");}
  return 0;
}

void pHandler(int sig)
{
   printf("Signal Received by parent %d\n", sig);
   kill(pid, SIGKILL);
   wait(NULL);
   printf("Parent will exit now\n");
   exit(1);
}

void cHandler(int sig)
{
  printf("Signal Received by child %d\n", sig);

}

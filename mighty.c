#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[])
{
   int fd;
   int nfd;
   int pipefd[2];
   char buf[100];
   //char childbuf[100];
   char *newFile;
   
   //opening file foo.txt
   fd = open(argv[1], O_RDONLY);
   if (fd < 0) {perror(argv[1]); exit(1); }
   
  //getting the name the output file
   newFile = argv[2];
   nfd = creat(newFile, 0644);
   if (nfd < 0) {perror(argv[1]); exit(1); }
  
     
   pipe(pipefd);
   pid_t pid = fork();
   
    //child process
   if(pid == 0)
   {
     close(pipefd[0]);
     dup2(pipefd[1], 1);
     execl("/bin/cat", "cat", "-b", argv[1], NULL);
     close(pipefd[1]);
   }
   
   //parent process
   else if(pid > 0)
   {
      wait(NULL);
     close(pipefd[1]);
     open(newFile, O_WRONLY);
     //read from pipe
     while(read(pipefd[0], &buf, 1) > 0)
     {
       write(STDOUT_FILENO, &buf, 1);
       write(nfd, &buf, 1);
     }
       close(pipefd[0]);
    }
     else
     {
       printf("error\n");
       exit(1);
     }
  
   return 0;
}

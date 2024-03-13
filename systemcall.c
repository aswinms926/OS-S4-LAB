#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

 int main()
 {
	pid_t childpid = fork();
	if (childpid==-1)
	{
		printf("child execution is unsuccessfull\n");
	}
	else if(childpid==0)
	{
	printf("child execution is successfull \n ");
	printf("pid : %d \n",getpid());
	printf("parent pid is %d \n",getppid());
	}
	else 
	{
		printf("parent process");
		printf("pid :%d \n",getpid());
		printf("child pid : %d \n",childpid);
		wait(NULL);
		printf("child finfished ");
		exit(0);
	}
		
	return 0;
}	
			

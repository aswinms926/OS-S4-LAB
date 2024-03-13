#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	char * array[] ={ "./EXEC",NULL};
	execvp(array[0],array);
	return 0;
}	


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc , char **argv)
{
	pid_t new_pid;
	pid_t child_new_pid;
	int i = 0;
	
	printf("\n\nThis is just a simulation of fork() \n\n");

	new_pid = fork();

	switch(new_pid)
	{

		case -1 :
			printf("\n\nError creating child process\n\n");
		break;
		
		case 0 :
			printf("\n\tChild\n\n");
			child_new_pid = fork();

			switch(child_new_pid)
			{
				case -1 :
					printf("\n\nError Creating new process from child\n\n");
				break;

				case 0 :
					printf("\t\tChild of child\n\n");

					for (i = 90; i<=110; i++)
					{
						printf("\t\t%d\n",i);
						sleep(1);
					}
				break;

				default : 
					for (i = 0; i<=10; i++)
					{
						printf("\t%d\n",i);
						sleep(1);
					
					}
				
					/* wait for child of child process completion */
					if(child_new_pid)
					{
						int status;
						pid_t child_pid;
	
						child_pid = wait(&status);

						if(WIFEXITED(status))
						{
							printf("\n\nChild of child process exit normally\n\n");
						}
							else
						{
			
							printf("\n\nChild of child process exit abnormally\n\n");
						}
					}
			
				break;

			}
		break;

		default :
			printf("\n\nParent\n\n");
			for (i = 10; i>=5; --i)
			{
				printf("%d\n",i);
				sleep(1);
			}
		break;		

	}

	/* wait for child process completion */
	if(new_pid)
	{
		int status;
		pid_t child_pid;

		child_pid = wait(&status);

		if(WIFEXITED(status))
		{
			printf("\n\nChild process exit normally\n\n");
		}
		else
		{

			printf("\n\nChild process exit abnormally\n\n");
		}
	}
	
	return 0;
}

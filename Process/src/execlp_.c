#include <stdio.h>
#include <unistd.h>

int main(int argc , char **argv)
{
	printf("\n\nExample for execlp\n\n");

	execlp("uname" , "uname" , "-a" , 0);

	return 0;
}


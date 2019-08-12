#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("\n\nExecuting ps -al command from c code\n\n");
	system("ps -al &");
	printf("\n\nDone...!\n\n");
	return 0;
}

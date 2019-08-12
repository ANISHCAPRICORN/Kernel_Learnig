#include <unistd.h>
#include <stdio.h>

int main(int argc , char **argv)
{
	printf("\n\nargc = %d, argv = %s\n\n",argc, argv[0]);

	execl("/usr/bin/ps", "ps","ax", 0);

	return 0;
}

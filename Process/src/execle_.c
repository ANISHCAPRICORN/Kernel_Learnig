#include <stdio.h>
#include <unistd.h>

int main (int argc , char **argv)
{
	char *const env_p[] = {"PATH=/bin:/usr/bin/", "TERM=console", 0};

	printf("\n\nexecle example..!\n\n");

	execle("/usr/bin/ps", "ps", "ax", 0, env_p );
	return 0;
}

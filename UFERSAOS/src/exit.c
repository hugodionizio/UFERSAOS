// UFERSA OS
// Sai do Shell

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int exitShell () {
	printf("exiting...\n");
	exit(1);

	return (0);
}

// UFERSA OS
// Desassocia a variável de ambiente de um export anterior

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int unset (char *argv) {
	extern char exportVar[80];

	printf("unsetting...\n");

	return (0);
}

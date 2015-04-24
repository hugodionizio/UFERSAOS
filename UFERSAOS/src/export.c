// UFERSA OS
// Cria variável de ambiente com um valor do caminho ao qual está associada

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int export (int args, char *argv) {
	extern char var[80];

	printf("exporting...");

	return (0);
}

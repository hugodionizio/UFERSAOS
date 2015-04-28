// UFERSA OS
// Desassocia a variável de ambiente de um export anterior

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int unset (int argc, char *argv[]) {

	char *var;

	if (argc != 2) {
		var = getenv(argv[1]);

		if(var == NULL) {
			printf("\nFalha na remoção. Tente novamente.\n");
			return 1;
		}
	}
	else {
		printf ("Número de entradas (%d) incompatível\n", argc);
		return 1;
	}

	unsetenv(argv[1]);
	printf ("variável \"%s\" removida com sucesso!\n", argv[1]);

	return (0);
}

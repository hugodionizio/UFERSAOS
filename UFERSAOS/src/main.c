/*
 * Projeto: UFERSA OS
 * Algoritmo: main.c
 * FunÃ§Ã£o: UFERSA OS's Shell
 *  Created on: 21/04/2015
 *      Authors: Efraim Rodrigues
 *      		 Hugo Dionizio Santos
 *      		 Wilka Tavares
 */

#include "UFERSAOS.h"

#define MAXCOMMANDS 10
#define MAXBUFFER 80

enum COMMAND_CONSTANTS {
	LS,
	CD,
	ECHO,
	PS,
	KILL,
	EXIT,
	ALIAS,
	UNALIAS,
	EXPORT,
	UNSET
};

int main(int argc, char **argv) {
	int argint = MAXCOMMANDS, i;

	char buffer[MAXBUFFER];
	char commands[][MAXCOMMANDS] = { "ls", "cd", "echo", "ps", "kill",
						  "exit", "alias", "unalias", "export", "unset"};

	if(argc > 1) {
		printf ("\n%d argumentos.\n", argc);
		printf("%s", argv[1]);
		strcpy(buffer, "");

		for(i = 1; i < argc; i++) {
			strcat(buffer, argv[i]);
			if (i < argc)
				strcat(buffer, " ");
		}
	}

	do {
		if (argc <= 1) {
			printf(">> ");
			fgets(buffer, MAXBUFFER, stdin);
			buffer[strlen(buffer)-1] = '\0';
		}
		int numeroDeEntradas = contaEspacos(buffer)+1;

		printf("Número de entradas: %d\n", numeroDeEntradas);

		char ** string = divideString(buffer);

		//Direciona o fluxo de execução para o comando escolhido.
		for(i = 0; i < MAXCOMMANDS; i++) {
			if (argc >= 1) {
				if (strcmp(commands[i], string[0]) == 0) {
					argint = i;
					break;
				}
			}
		}
		if (i == MAXCOMMANDS) {
			argint = MAXCOMMANDS;
		}
		printf("Comando escolhido: %s (%d)\n", string[0], argint);

		switch (argint) {
			case LS: ls(); break;
			case CD: cd(numeroDeEntradas-1,string); break;
			case ECHO: echo(numeroDeEntradas-1,string); break;
			case PS: ps(); break;
			case KILL: killthis(numeroDeEntradas-1,string); break;
			case EXIT: exitShell(); break;
			case ALIAS: alias(argv[2]); break;
			case UNALIAS: unalias(argv[2]); break;
			case EXPORT: export(numeroDeEntradas-1,string); break;
			case UNSET: unset(numeroDeEntradas-1,string); break;
			default: system(buffer);
		}
	} while (argc <= 1 && argint != 5);

	return EXIT_SUCCESS;
}

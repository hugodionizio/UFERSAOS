/*
 * Projeto: UFERSA OS
 * Algoritmo: main.c
 * FunÃ§Ã£o: UFERSA OS's Shell
 *  Created on: 21/04/2015
 *      Authors: Efraim Rodrigues
 *      		 Hugo Dionizio Santos
 *      		 Wilka Tavares
 */

#include <stdio.h>
#include "Auxiliar.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "commands.h"

#define MAXCOMMANDS 10
#define MAXBUFFER 80

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
			case 0: ls(); break;
			case 1: cd(numeroDeEntradas-1,string); break;
			case 2: echo(numeroDeEntradas-1,string); break;
			case 3: ps(); break;
			case 4: killthis(numeroDeEntradas-1,string); break;
			case 5: exitShell(); break;
			case 6: alias(argv[2]); break;
			case 7: unalias(argv[2]); break;
			case 8: export(argv[2]); break;
			case 9: unset(argv[2]); break;
			default: system(buffer);
		}
	} while (argc <= 1 && argint != 5);

	return EXIT_SUCCESS;
}

/*
 * Projeto: UFERSA OS
 * Algoritmo: main.c
 * Função: UFERSA OS's Shell
 *  Created on: 21/04/2015
 *      Authors: Efraim Rodrigues
 *      		 Hugo Dionizio Santos
 *      		 Wilka Tavares
 */

#include <stdio.h>
#include "Auxiliar.h"

#include "commands.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXCOMMANDS 10
#define MAXBUFFER 80

int main(int argc, char **argv) {
	int argint = MAXCOMMANDS, i;

	char buffer[MAXBUFFER];
	char command[20] = "";
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
		printf("Número de comandos: %d\n", contaEspacos(buffer)+1);
		strcpy(command, listarComandos(buffer, 0));

		for(i = 0; i < MAXCOMMANDS; i++) {
			if (argc >= 1) {
				if (strcmp(commands[i], command) == 0) {
					argint = i;
					break;
				}
			}
		}
		printf("Comando escolhido: %s (%d)\n", command, argint);

		switch (argint) {
			case 0: ls(); break;
			case 1: cd(); break;
			case 2: echo(); break;
			case 3: ps(); break;
			case 4: killthis(); break;
			case 5: exitShell(); break;
			case 6: alias(argv[2]); break;
			case 7: unalias(argv[2]); break;
			case 8: export(argv[2]); break;
			case 9: unset(argv[2]); break;
			default: printf("Hem?! Comando desconhecido...\n");
		}
	} while (argc <= 1 && argint != 5);

	return EXIT_SUCCESS;
}


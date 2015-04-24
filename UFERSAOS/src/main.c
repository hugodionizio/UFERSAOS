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
//	printf ("Tinha que ser HelloWorld...");

	int valor = 50, argint = MAXCOMMANDS, i;

	char buffer[MAXBUFFER];
	char command[20] = "";
//	char line[MAXBUFFER];
	char commands[][MAXCOMMANDS] = { "ls", "cd", "echo", "ps", "kill",
						  "exit", "alias", "unalias", "export", "unset"};

	printf ("\n%d argumentos.\n", argc);

	if(argc > 1) {
		printf("%s", argv[1]);
		strcpy(buffer, "");

		for(i = 1; i < argc; i++) {
			strcat(buffer, argv[i]);
			if (i < argc)
				strcat(buffer, " ");
		}
	}
	else {
		//scanf("%s", &buffer);
		fgets(buffer, MAXBUFFER, stdin);
	}
	buffer[strlen(buffer)-1] = '\0';

	printf("Número de comandos: %d\n", contaEspacos(buffer));

	strcpy(command, listarComandos(buffer, 0));
	printf("comando %d: %s\n", 0, command);

	for(i = 0; i < MAXCOMMANDS; i++) {
		if (argc >= 1) {
			if (strcmp(commands[i], command) == 0) {
				argint = i;
				break;
			}
		}
	}

	printf("Comando escolhido = %d\n", argint);

	switch (argint) {
		case 0: ls(); break;
		case 1: cd(); break;
		case 2: echo(); break;
		case 3: ps(); break;
		case 4: killthis(); break;
		case 5: printf("Exiting..."); exit(0); break;
		case 6: alias(argv[2]); break;
		case 7: unalias(argv[2]); break;
		case 8: export(argv[2]); break;
		case 9: unset(argv[2]); break;
		default: printf("Hein?! Comando desconhecido...\n");
	}

	return EXIT_SUCCESS;
}


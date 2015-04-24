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
	strcat(buffer, " concatenado");

	printf("O papagaio diz: %s\n", buffer);

	printf("Número de comandos: %d", contaEspacos(buffer));
	printf("comando %d: %s\n", 0, command);

	for(i = 0; i < MAXCOMMANDS; i++) {
		if (argc == 1) {
			if (strcmp(commands[i], argv[0])) {
				argint = i;
				break;
			}
		}
		else if (argc > 1)
			if (strcmp(commands[i], argv[0])) {
				argint = i;
				break;
			}
	}

	printf("A função enigma retorna valor %d para entrada %d.\n",
			enigma(valor), valor);

	switch (argint) {
		case '7': alias(argv[1]); break;
		default: printf("Hein?! Comando desconhecido...\n");
	}

	return EXIT_SUCCESS;
}


/*
 * kill.c
 *
 *  Created on: 22/04/2015
 *      Author: hugo
 */
#include <signal.h>
#include <stdio.h>

void killthis(int argc, char * argv[]) {
	if(argc == 1)
		if(!kill(atoi(argv[1]),SIGQUIT))
			printf("Processo %s finalizado.\n",argv[1]);
		else
			printf("Processo inexiste ou impossibilitado de ser finalizado.\n");
	else
		printf("Verifique a quantidade de argumentos passados.\n");
}

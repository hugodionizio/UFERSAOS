/*
 * cd.c
 *
 *  Created on: 22/04/2015
 *      Author: hugo
 */

/**
 * Muda o diretório atual para o diretório passado como argv[1]
 * Retorna 0 se tudo ocorreu como esperado e 1 caso contrário.
 */
void cd(int argc, char * argv []) {
	if(chdir(argv[1]))
				printf("cd: can't cd to %s\n",argv[1]);
}

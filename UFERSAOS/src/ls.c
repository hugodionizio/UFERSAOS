#define _LS_C_
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
#include <dirent.h>
int ls(){
	/*Esta string armazenará o atual caminho do programa*/
	char * diretorio = (char*)malloc(1024*sizeof(char));

	/*Esta função insere o caminho atual na variável string*/
	getcwd(diretorio,1024);

	/*Esta função abre o diretório.*/
	DIR * dir = opendir(diretorio);

	/*Esta estrutura armazenará informações sobre o item lido. No caso, pela função readdir*/
	struct dirent * entrada;

	if(!dir)
		return -1;

	/*Lembrando que a função readdir aponta para o próximo item dentro do diretório diretório*/
	if(!(entrada = readdir(dir)))
		return -1;

	do {
		printf("%s	",entrada->d_name);

	} while (entrada = readdir(dir));

	closedir(dir);

	printf("\n");

	return 0;
}

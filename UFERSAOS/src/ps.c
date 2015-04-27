/*
 * ps.c
 *
 *  Created on: 22/04/2015
 *      Author: hugo
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/procfs.h>

#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>

void ps() {
	/*Esta string armazenará o atual caminho do programa*/
	char * diretorio = (char*)malloc(1024*sizeof(char));

	for(int i=0; i<1024; i++)
		diretorio[i] = '\0';

	/*Esta função insere o caminho atual na variável diretorio*/
	strcpy(diretorio,"/proc/");

	/*Esta função abre o diretório.*/
	DIR * dir = opendir(diretorio);

	/*Esta estrutura armazenará informações sobre o item lido. No caso, pela função readdir*/
	struct dirent * entrada;

	if(!dir)
		return -1;

	/*Lembrando que a função readdir aponta para o próximo item dentro do diretório diretório*/
	if(!(entrada = readdir(dir)))
		return -1;

	int strlenght = strlen(diretorio);

	/*This is going to open the psinfo files*/
	FILE * psinfo;

	printf("PID	PROCESS\n");

	do {

		strcat(diretorio,entrada->d_name);

		strcat(diretorio,"/psinfo");

		//NOW OPEN THE FOLDERS
		int temp = open(diretorio,O_RDONLY);


		/*Se o item for um diretório, isto significa que o diretório representa um processo em execução*/
		if(temp != -1)
		{
			char * line = (char*)malloc(1024*sizeof(char));

			psinfo = fopen(diretorio,"r");

			char * pid = (char*)malloc(4*sizeof(char));

			int i;

			for(i=0; diretorio[i+6] != '/'; i++)
				pid[i] = diretorio[i+6];

			pid[i] = '\0';

			printf("%s	",pid);

			i=0;

			while(!feof(psinfo))
			{
				fscanf(psinfo,"%s",line);

				if(i==3)
					printf("%s ",line);

				i++;
			}

			printf("\n");

			fclose(psinfo);
		}
		//read(temp);

		diretorio[strlenght] = '\0';

	} while (entrada = readdir(dir));

	closedir(dir);
}

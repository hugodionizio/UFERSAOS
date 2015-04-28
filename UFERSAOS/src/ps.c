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
	/*Esta string armazenarÃ¡ o atual caminho do programa*/
	char * diretorio = (char*)malloc(1024*sizeof(char));

	for(int i=0; i<1024; i++)
		diretorio[i] = '\0';

	/*Esta funÃ§Ã£o insere o caminho atual na variÃ¡vel diretorio*/
	strcpy(diretorio,"/proc/");

	/*Esta funÃ§Ã£o abre o diretÃ³rio.*/
	DIR * dir = opendir(diretorio);

	/*Esta estrutura armazenarÃ¡ informaÃ§Ãµes sobre o item lido. No caso, pela funÃ§Ã£o readdir*/
	struct dirent * entrada;

	/*Lembrando que a funÃ§Ã£o readdir aponta para o prÃ³ximo item dentro do diretÃ³rio diretÃ³rio*/
	if(!(entrada = readdir(dir)))
		printf("Problem 39 - ps.c");

	int strlenght = strlen(diretorio);

	/*This is going to open the psinfo files*/
	FILE * psinfo;

	printf("PID	PROCESS\n");

	do {

		strcat(diretorio,entrada->d_name);

		strcat(diretorio,"/psinfo");

		//NOW OPEN THE FOLDERS
		int temp = open(diretorio,O_RDONLY);


		/*Se o item for um diretÃ³rio, isto significa que o diretÃ³rio representa um processo em execuÃ§Ã£o*/
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

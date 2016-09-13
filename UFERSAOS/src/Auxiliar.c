/*
 * Auxiliar.c
 *
 *  Created on: 21/04/2015
 *      Author: hugo
 */

#include <stdio.h>

int enigma(int n) {

	return 2*n;
}

int contaEspacos(char s[]) {
   int numEspacos, i;
   numEspacos = 0;

   for (i = 0; s[i] != '\0'; ++i) {
	   if(s[i] == ' ')
		   numEspacos++;
//	   printf("%d espaços", numEspacos);
   }
   return numEspacos;
}

char ** divideString(char s[])
{
	int numeroDeEntradas = contaEspacos(s)+1;

	char ** string = (char**)malloc(numeroDeEntradas*sizeof(char*));

	int * tamanhoEntradas = (int*)malloc(numeroDeEntradas*sizeof(int));

	int qntEntradas=0,j = 0;

	int tamanhoDeS = strlen(s);

	int i;
	//Calculando tamanho de cada subString
	for(i=1; i<tamanhoDeS; i++)
			if(s[i] != ' ' && s[i] != '\0')
				j++;
			else
			{
				tamanhoEntradas[qntEntradas] = j+1;
				j=0;
				qntEntradas++;
			}

	string[0] = (char*)malloc(tamanhoEntradas[0]*sizeof(char));

	string[0] = strtok (s," ");


	//Reservando espaço para cada subString
	for(i=1; i<numeroDeEntradas; i++)
	{
		string[i] = (char*)malloc(tamanhoEntradas[i]*sizeof(char));

		string[i] = strtok (NULL," ");
	}

	return string;
}

char *listarComandos(char s[], int pos) {
   int numEspacos = 0, i = 0;
   char *comando = (char *)malloc(sizeof(char)*10);

   while (s[i] != '\0' && numEspacos < pos + 1) {
	   if(s[i] == ' ')
		   numEspacos++;
	   else
		   if (numEspacos < pos + 1)
			   comando[i] = s[i];
	   i++;
   }
   comando[i] = '\0';

   return comando;
}

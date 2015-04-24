/*
 * Auxiliar.c
 *
 *  Created on: 21/04/2015
 *      Author: hugo
 */

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

char *listarComandos(char s[], int pos) {
   int numEspacos = 0, i = 0;
   char comando[strlen(s)];

   while (s[i] != '\0' && numEspacos < pos) {
	   if(s[i] == ' ')
		   numEspacos++;
	   else
		   if (numEspacos == pos - 1)
			   comando[i] = s[i];
   }

   return (char *)comando;
}

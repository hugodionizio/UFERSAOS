/*
 * Auxiliar.h
 *
 *  Created on: 21/04/2015
 *      Author: hugo
 */

#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#ifdef i386-pc-minix
	#include "Auxiliar.c"
#endif

int enigma(int);
int contaEspacos(char []);
char *listarComandos(char [], int);

#endif /* AUXILIAR_H_ */

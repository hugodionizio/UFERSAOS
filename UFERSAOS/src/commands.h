/*
 * commands.h
 *
 *  Created on: 21/04/2015
 *      Author: hugo
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_

/*int ls();
void cd();
void echo();
void ps();
void killthis();
int exitShell();
void alias(char *);
int unalias(char *);
int export(char *);
int unset(char *);
 * */

#ifdef i386-pc-minix
	#include "ls.c"
	#include "cd.c"
	#include "echo.c"
	#include "ps.c"
	#include "kill.c"
	#include "exit.c"
	#include "alias.c"
	#include "unalias.c"
	#include "export.c"
	#include "unset.c"
#endif

#endif /* COMMANDS_H_ */

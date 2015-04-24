/*
 * commands.h
 *
 *  Created on: 21/04/2015
 *      Author: hugo
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_

void ls();
void cd();
void echo();
void ps();
void killthis();
void exitShell();
void alias(char *);
void unalias(char *);
void export(char *);
void unset(char *);

#endif /* COMMANDS_H_ */

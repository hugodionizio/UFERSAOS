/*
 * echo.c
 *
 *  Created on: 22/04/2015
 *      Author: hugo
 */

void echo(int argc, char * argv []) {
	for(int i=1; i<=argc; i++)
	{
		write(1, argv[i], strlen(argv[i]));
		write(1, " ", 1);
	}

	write(1, "\n", 1);
}

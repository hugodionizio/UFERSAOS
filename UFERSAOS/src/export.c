// UFERSA OS
// Cria variável de ambiente com um valor do caminho ao qual está associada

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int export(int argc, char *argv[])
{
	//extern char aliasVar[80];
//	struct aliasent *alias;

  int count = 0;

  printf("exporting...\n");
  printf("\n");
  while(environ[count] != NULL)
  {
    printf("[%s] :: ", environ[count]);
    count++;
  }

  char *val = getenv("USER");
  printf("\n\nCurrent value of environment variable USER is [%s]\n",val);

  if(setenv("USER","Arora",1))
  {
    printf("\n setenv() failed\n");
    return 1;
  }

  printf("\n Successfully Added a new value to existing environment variable USER\n");

  val = getenv("USER");
  printf("\nNew value of environment variable USER is [%s]\n",val);

  /*while(1)
  {
    sleep(2);
  }*/

  return 0;
}

int export_old (char *argv) {
	extern char var[80];

	printf("exporting...\n");

	return (0);
}

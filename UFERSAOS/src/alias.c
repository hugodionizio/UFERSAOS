// UFERSA OS
// Associa um nome a um valor ou comando

//#include <aliases.h>
#include <errno.h>
#include <stddef.h>

void alias (char *argv) {
	extern char aliasVar[80];
//	struct aliasent *alias;

	printf("aliasing...\n");
	/*
    setaliasent();
    for (;;) {
        alias = getaliasent();
        if (alias == NULL)
            break;
        printf("Name: %sn", alias->alias_name);
    }
    if (errno) {
        perror("reading alias");
    }
    endaliasent();
	 */
}

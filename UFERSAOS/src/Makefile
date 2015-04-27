COMPILER_TYPE = gnu

CC = gcc

PROG = UFERSAOS
SRCS = main.c ls.c cd.c echo.c ps.c kill.c exit.c alias.c unalias.c export.c unset.c  

CCFLAGS= -Wall -O3

DPADD += ${LIBDRIVER} ${LIBSYS}
LDADD += -llm -ldriver -lsys

LDFLAGS += -L.

MAN=
BINDIR? = /usr/sbin

.include <bsd.prog.mk>
.include <bsd.gcc.mk>
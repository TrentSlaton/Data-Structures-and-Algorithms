VERSION=	0.1

PREFIX=		/usr/local
MANPREFIX=	${PREFIX}/man/man1

CFLAGS=		-Wall -Werror -Wextra
CC=		cc

BINARY=		htb
SRC=		${BINARY}.c main.c menu.c
OBJ=		${SRC:.c=.o}

all: ${BINARY}

.c.o:
	${CC} -c ${CFLAGS} $<

${BINARY}: ${OBJ}
	${CC} -o $@ ${OBJ}

clean:
	rm -f ${BINARY} ${OBJ}

dist: clean
	mkdir -p ${BINARY}-${VERSION}
	cp -R Makefile ${SRC} menu.h ${BINARY}.1 ${BINARY}.h README\
		${BINARY}-${VERSION}
	tar -cf ${BINARY}-${VERSION}.tar ${BINARY}-${VERSION}
	gzip ${BINARY}-${VERSION}.tar
	rm -rf ${BINARY}-${VERSION}


install: all
	mkdir -p ${PREFIX}/bin
	cp -f ${BINARY} ${PREFIX}/bin
	chmod 755 ${PREFIX}/bin/${BINARY}
	mkdir -p ${MANPREFIX}
	sed "s/VERSION/${VERSION}/g" <${BINARY}.1 > ${MANPREFIX}/${BINARY}.1
	chmod 644 ${MANPREFIX}/${BINARY}.1

uninstall:
	rm -f ${PREFIX}/bin/${BINARY} ${MANPREFIX}/${BINARY}.1

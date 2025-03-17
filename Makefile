all: git_make

git_make: git_make.o
	${CC}	${LDFLAGS} git_make.o -o git_make

git_make.o: git_make.c
	${CC} ${CFLAGS} -c git_make.c 

clean:
	rm -f *.o git_make

install: all
	mkdir -p ${DESTDIR}${bindir}
	cp -f git_make ${DESTDIR}${bindir}
	chmod 755 ${DESTDIR}${bindir}/git_make


.PHONY: all clean install

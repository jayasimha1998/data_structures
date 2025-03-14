all: git_make

hello_make: hello_make.o
	${CC}	${LDFLAGS} hello_make.o -o git_make

hello_make.o: hello_make.c
	${CC} ${CFLAGS} -c hello_make.c 

clean:
	rm -f git_make

install: all
	mkdir -p ${DESTDIR}${bindir}
	cp -f git_make ${DESTDIR}${bindir}
	chmod 755 ${DESTDIR}${bindir}/git_make

.PHONY: all clean install

all: hello_make

hello_make: hello_make.o
	${CC}	${LDFLAGS} hello_make.o -o hello_make

hello_make.o: hello_make.c
	${CC} ${CFLAGS} -c hello_make.c 

clean:
	rm -f hello_make

install: all
	mkdir -p ${DESTDIR}${bindir}
	cp -f hello_make ${DESTDIR}${bindir}
	chmod 755 ${DESTDIR}${bindir}/hello_make

.PHONY: all clean install

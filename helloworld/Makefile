TARGET = helloworld
CC ?= $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -g
DESTDIR ?= /usr/bin

all: $(TARGET)

$(TARGET): helloworld.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install:
	install -d $(DESTDIR)
	install -m 0755 $(TARGET) $(DESTDIR)/$(TARGET)

clean:
	rm -f *.o $(TARGET)

.PHONY: all install clean

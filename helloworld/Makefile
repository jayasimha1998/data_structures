TARGET = helloworld
CC ?= $(CROSS_COMPILE)gcc
DESTDIR ?= /usr/bin

all: $(TARGET)

$(TARGET): helloworld.o
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(LDFLAGS) -c $< -o $@

install:
	install -d $(DESTDIR)
	install -m 0755 $(TARGET) $(DESTDIR)/$(TARGET)

clean:
	rm -f *.o $(TARGET)

.PHONY: all install clean

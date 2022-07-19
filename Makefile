SHELL := /bin/bash
EXECUTABLE = map

INCLUDES = -I./includes -I/usr/include
SOURCES = $(shell find ./sources -name *.c)
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS += -Wall -Wextra -Werror -Wpedantic 

LDLIBS += -lcurl -lm

all: release

release: CFLAGS += -O3
release: $(EXECUTABLE)

debug: CFLAGS += -g
debug: $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
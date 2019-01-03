CC = clang
CFLAGS = -g -std=c99
OBJS = main.o functions.o dyn_array.o

PREFIX = /Users/pavellutskov/.usr/

NAME = prime

all: $(NAME)

$(OBJS): dyn_array.h

.c.o:
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm *.o $(NAME)

install:
	cp $(NAME) $(PREFIX)/bin/$(NAME)

uninstall:
	rm $(PREFIX)/bin/$(NAME)

CC = clang
CFLAGS = -c -g -std=c99
OBJS = main.o functions.o dyn_array.o

PREFIX = /Users/pavellutskov

NAME = prime

all: $(NAME)

main.o: main.c dyn_array.h
	$(CC) $(CFLAGS) main.c

functions.o: functions.c dyn_array.h
	$(CC) $(CFLAGS) functions.c

dyn_array.o: dyn_array.c dyn_array.h
	$(CC) $(CFLAGS) dyn_array.c

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm *.o $(NAME)

install:
	cp $(NAME) $(PREFIX)/bin/$(NAME)

uninstall:
	rm $(PREFIX)/bin/$(NAME)

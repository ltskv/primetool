CC = clang
CFLAGS = -c -g -std=c99
OBJS = main.o

NAME = fact

all: $(NAME)

main.o: main.c dyn_array.h
	$(CC) $(CFLAGS) main.c

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm *.o fact

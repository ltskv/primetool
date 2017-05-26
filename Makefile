CC = clang
CFLAGS = -c -g -std=c99
OBJS = main.o

NAME = fact

all: $(NAME)

main.o: main.c
	$(CC) $(CFLAGS) main.c

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm *.o fact

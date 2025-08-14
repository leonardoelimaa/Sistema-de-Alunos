CC = gcc
CFLAGS = -Wall -Wextra -MMD

SRCS = main.c sistema.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

EXEC = programa.exe

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS) $(EXEC)

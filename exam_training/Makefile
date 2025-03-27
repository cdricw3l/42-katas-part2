NAME=test
CC= gcc
GFLAGS=-Werror -Wall -Wextra

s= voyageur.c
OBJS=$(SRCS:%.o=.c)

$(NAME): $(OBJS)
	$(CC) $(GFLAGS) $(OBJS) -o $(NAME)

run: $(NAME)
	./test
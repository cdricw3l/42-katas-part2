NAME= minishell
GCC=
GFLAGS= -Werror -Wall -Wextra  -I.

MODULE_PATH= main/main.c 
MODULE_TEST=
OBJS= $(patsubst %.c,%.o,$(wildcard *.c))

LINUX=Linux
#get the name of the systeme
OS= $(shell uname)
#get date format iso
DATE=$(shell date -Iseconds) 
# get current branch git
BRANCH=$(shell git branch --show-current) 
#memory log path
MEMORY_CHECK_PATH= error_managment/valgrind


#compilateur configuration linux or mac

ifeq ($(OS), Linux)
GCC=gcc
else
GCC = cc
endif

$(NAME): $(OBJS)
	$(GCC) $(GFLAGS) $(OBJS) -o $(NAME) -lreadline

run: $(NAME) 
ifeq ($(OS),Darwin)
	./$(NAME) > make run
else
	valgrind --log-file=$(MEMORY_CHECK_PATH)/$(DATE) --leak-check=full ./$(NAME)
endif

clean: 
	rm -f *.o

fclean: clean 
	rm -f $(NAME)

all: fclean run
	
re: clean

git: fclean
	git add . && git commit -m $(COM)/$(DATE) && git push origin $(BRANCH)

.PHONY:


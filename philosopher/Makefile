NAME= philo

##########################  OS check

OS = $(shell uname)
ifeq ($(OS), Darwin)
CC=clang
GFLAGS= -Werror -Wall -Wextra -g -Iinclude
else ifeq ($(OS), Linux)
CC=gcc
GFLAGS= -Werror -Wall -Wextra
endif

# compilation flags and envoronement developpent.
# depend on the mode: mode=0: all flags  --mode=1: environement test, --mode=2: no flags.

mode=0
PROD=0
TEST=1
NOFLAGS=2

# production path.
SRCS_MAIN= srcs/main.c
SRCS_PETRI= $(wildcard srcs/petri_network/utils/**/*.c) $(wildcard srcs/petri_network/network/*.c)
SRCS_UTILS= $(wildcard srcs/utils/**/*.c) $(wildcard srcs/utils/*.c)
SRCS_THREAD= $(wildcard srcs/thread_manager/*.c)
SRCS_PHILO= $(wildcard srcs/philosopher/*.c)

# test path.

SRCS_TEST= $(wildcard unit_test/*.c)

# Mode precompilation rules: no flags (unused variable etc...) for mode noflags.

ifeq ($(mode), $(PROD))
%.o:%.c
	$(CC) $(GFLAGS) -c $< -o $@
else ifeq ($(mode), $(NOFLAGS))
%.o:%.c
	$(CC) -c $< -o $@
endif

# Precompilation object.

# Production env:

OBJS_MAIN=$(SRCS_MAIN:%.c=%.o)
OBJS_UTILS=$(SRCS_UTILS:%.c=%.o)
OBJS_PETRI=$(SRCS_PETRI:%.c=%.o)
OBJS_PHILO=$(SRCS_PHILO:%.c=%.o)
OBJS_THREAD=$(SRCS_THREAD:%.c=%.o)

# Test env:

OBJS_TEST=$(SRCS_TEST:%.c=%.o)

# utils.

DATE=$(shell date -Iseconds)
BRANCH=$(shell git branch --show-current)
gcom=
EMPTY=

#Programme arguments

#number_of_philosophers
#time_to_die ms
#time_to_eat
#time_to_sleep 
#time_to_sleep

NOP= 2
TTD= 150
TTE= 2000
TTS= 200
CYCLE= 10

ifeq ($(mode), $(TEST))
OBJS= $(OBJS_TEST)
else
OBJS= $(OBJS_MAIN) $(OBJS_PETRI) $(OBJS_PHILO) $(OBJS_UTILS) $(OBJS_THREAD)
endif


.PHONY: clean fclean run git testenv

#main linkin rule

$(NAME): $(OBJS)
ifeq ($(mode), $(PROD))
	$(CC) $(GFLAGS) $(OBJS)  -o $(NAME)
else ifeq ($(mode), $(NOFLAGS))
recall:  $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
endif

# Call the main rule and start the program with args and valgrind if the od is linux.

run: $(NAME)
ifeq ($(OS), Darwin)
	./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	valgrind --leak-check=full --log-file=filename  -s ./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
endif

# cleaning rules

clean:
	rm -f $(OBJS) $(OBJS_TEST)

fclean: clean
	rm -f $(NAME) test_unit 


# Git hub rules. To be improuv. (remote ...)

git: fclean
ifeq ($(gcom), $(EMPTY))
	git add .
	git commit -m $(NAME)/$(DATE)
else
	git add .
	git commit -m $(NAME)/$(gcom)/$(DATE)
endif
	git push origin $(BRANCH)


# dev environnement

t: $(OBJS) $(OBJS_TEST)
ifeq ($(OS), Darwin)
	$(CC) $(GFLAGS) -fsanitize=address $(OBJS_TEST) $(OBJS) -o test_unit 
	./test_unit $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	$(CC)  $(OBJS_TEST) $(OBJS) -o test_unit 
	valgrind --leak-check=full --log-file=filename  -s ./test_unit $(NOP) $(TTD) $(TTE) $(TTS)
endif


all: $(NAME)

re: clean fclean all

NAME= philo
TEST_NAME= philo_utest

##########################  OS check

OS = $(shell uname)
ifeq ($(OS), Darwin)
CC=cc
GFLAGS= -Werror -Wall -Wextra -I./include -fsanitize=thread -g -O1
else ifeq ($(OS), Linux)
CC=gcc
GFLAGS= -Werror -Wall -Wextra -I./include
endif

# compilation flags and envoronement developpent.
# depend on the mode: mode=0: all flags  --mode=1: environement test, --mode=2: no flags.

mode=0
PROD=0
TEST=1
NOFLAGS=2

# production path.
SRCS_MAIN= srcs/main.c
SRCS_TEST= $(wildcard unit_test/*.c)
SRCS_INIT= $(wildcard srcs/initialisation/*.c)
SRCS_THREAD= $(wildcard srcs/thread/*.c)



# Mode precompilation rules: no flags (unused variable etc...) for mode noflags.

%.o:%.c
	$(CC) $(GFLAGS) -c $< -o $@

# Precompilation object.

# Production env:

OBJS_MAIN=$(SRCS_MAIN:%.c=%.o)
OBJS_INIT=$(SRCS_INIT:%.c=%.o)
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

NOP= 5
TTD= 500
TTE= 200
TTS= 200
CYCLE= 10

TENV_OBJS=   $(OBJS_THREAD) $(OBJS_INIT) $(OBJS_TEST)
PROD_OBJS= $(OBJS_MAIN) $(OBJS_INIT) $(OBJS_THREAD)

.PHONY: clean fclean run git testenv

#main linkin rule

$(NAME): $(PROD_OBJS)
	$(CC) $(GFLAGS) $(PROD_OBJS) -o $(NAME)

$(TEST_NAME): $(TENV_OBJS)
	$(CC) $(GFLAGS) $(TENV_OBJS_OBJS) -o $(TEST_NAME)


# Call the main rule and start the program with args and valgrind if the od is linux.

run: $(NAME)
ifeq ($(OS), Darwin)
	./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	valgrind --leak-check=full --log-file=filename  -s ./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS) 10
endif

# dev environnement

t: $(TENV_OBJS)
ifeq ($(OS), Darwin)
	@$(CC) $(GFLAGS)  $(TENV_OBJS) -o $(TEST_NAME)
	./$(TEST_NAME) $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	@$(CC)  $(TENV_OBJS) -lpthread -o $(TEST_NAME)
	 ./$(TEST_NAME) $(NOP) $(TTD) $(TTE) $(TTS)
endif

#@valgrind  --log-file=filename --track-origins=yes --leak-check=full -s

tv: $(TENV_OBJS)
ifeq ($(OS), Darwin)
	@$(CC) $(GFLAGS) $(TENV_OBJS) -o $(TEST_NAME)
	@./$(TEST_NAME) $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	@$(CC)  $(TENV_OBJS) -lpthread -o $(TEST_NAME)
	@valgrind --tool=helgrind --log-file=filename -s ./$(TEST_NAME) $(NOP) $(TTD) $(TTE) $(TTS)
endif


v: $(TENV_OBJS)
ifeq ($(OS), Darwin)
	$(CC) $(GFLAGS) $(TENV_OBJS)-o test_unit 
	./test_unit $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	$(CC)   $(OBJS) -lpthread -o test_unit 
	 ./test_unit $(NOP) $(TTD) $(TTE) $(TTS)
endif

# cleaning rules

clean:
	rm -f $(PROD_OBJS) $(TENV_OBJS) filename

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

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







all: $(NAME)

re: clean fclean all

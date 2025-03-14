NAME= philo
CC= cc
GCC= gcc
GFLAGS= -Werror -Wextra -Wall  
#-Wno-unused-parameter

SRCS_PETRI= $(wildcard srcs/petri_network/*.c)
SRCS_MAIN= $(wildcard srcs/main/*.c)
SRCS_PHILO= $(wildcard srcs/philo/*.c)
SRCS_UTILS= $(wildcard srcs/utils/*.c)

OBJS_PETRI= $(SRCS_PETRI:*.c=.o)
OBJS_MAIN= $(SRCS_MAIN:*.c=.o)
OBJS_PHILO= $(SRCS_PHILO:*.c=.o)
OBJS_UTILS= $(SRCS_UTILS:*.c=.o)

DATE=$(shell date -Isecond)

NOP= 5 #number_of_philosophers
TTD= 4000 #time_to_die
TTE= 4000 #time_to_eat
TTS= 4000 #time_to_sleep 

GITCOM=
OS = $(shell uname)

$(NAME): $(OBJS_MAIN) $(OBJS_PETRI) $(OBJS_PHILO) $(OBJS_UTILS)
	$(CC) $(GFLAGS) $(OBJS_MAIN) $(OBJS_PETRI) $(OBJS_PHILO) $(OBJS_UTILS) -o $(NAME)
	
run:$(OBJS)
ifeq ($(OS), Darwin)
	$(CC) $(GFLAGS)  -fsanitize=address $(OBJS) -o $(NAME)
	./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	$(GCC) $(GFLAGS) $(OBJS) -o $(NAME)
	valgrind --leak-check=full --log-file=filename  -s ./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
endif

test: $(OBJS_TEST)
ifeq ($(OS), Darwin)
	$(CC) $(GFLAGS) -fsanitize=address $(OBJS_TEST) -o test_unit 
	./test_unit $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	$(CC)  $(OBJS_TEST) -o $(NAME)
	valgrind --leak-check=full --log-file=filename  -s ./test_unit $(NOP) $(TTD) $(TTE) $(TTS)
endif

clean:
	rm -f test_unit
	cd srcs && rm -f *.o 

fclean: clean
	rm -f $(NAME)

all: fclean $(NAME)

re: all

git: fclean
	cd ..
	git add .
	git commit -m $(NAME)/$(DATE)/$(GITCOM)
	git push

copy:
	cd .. && cd 42-katas/philosopher && rm -rf *
	cp -rf * ../42-katas/philosopher
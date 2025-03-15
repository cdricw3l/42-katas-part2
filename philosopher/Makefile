# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 22:40:28 by cw3l              #+#    #+#              #
#    Updated: 2025/03/15 09:43:26 by cw3l             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo

##########################  OS check

OS = $(shell uname)
ifeq ($(OS), Darwin)
CC=cc
GFLAGS= -Werror -Wall -Wextra -fsanitize=address
else ifeq ($(OS), Linux)
CC=gcc
GFLAGS= -Werror -Wall -Wextra
endif

# compilation flags and envoronement developpent.
# depend on the mode: mode=prod: all flags  --mode=test: environement test, --mode=noflags: no flags.

mode=prod
PROD=prod
TEST=test
NOFLAGS=noflags

# source path.
SRCS_PETRI= $(wildcard srcs/petri_network/*.c)
SRCS_PHILO= $(wildcard srcs/philosopher/*.c)
SRCS_UTILS= $(wildcard srcs/utils/**/*.c)
SRCS_MAIN= srcs/main.c

OBJS_PETRI=$(SRCS_PETRI:%.c=%.o)
OBJS_PHILO=$(SRCS_PHILO:%.c=%.o)
OBJS_UTILS=$(SRCS_UTILS:%.c=%.o)
OBJS_MAIN=$(SRCS_MAIN:%.c=%.o)

# utils.
DATE=$(shell date -Isecond)
BRANCH=$(shell git branch --show-current)
gitcom=
EMPTY=

#Programme arguments

NOP= 5 		#number_of_philosophers
TTD= 4000 	#time_to_die
TTE= 4000 	#time_to_eat
TTS= 4000 	#time_to_sleep 


OBJS= $(OBJS_MAIN) $(OBJS_PETRI) $(OBJS_PHILO) $(OBJS_TEST) $(OBJS_UTILS) 

# Mode precompilation rules: no flags for mode no flags.
ifeq ($(mode), $(PROD))
%.o:%.c
	$(CC) $(GFLAGS) -c $< -o $@
else ifeq ($(mode), $(NOFLAGS))
%.o:%.c
	$(CC) -c $< -o $@
endif


#main linkin rule
$(NAME): $(OBJS)
ifeq ($(mode), $(PROD))
	$(CC) $(GFLAGS) $(OBJS)  -o $(NAME)
else ifeq ($(mode), $(NOFLAGS))
	$(CC) $(OBJS) -o $(NAME)
	make clean
endif


# Call the main rule and start the program with args and valgrind if the od is linux.
run: $(NAME)
ifeq ($(OS), Darwin)
	./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
else ifeq ($(OS), Linux)
	valgrind --leak-check=full --log-file=filename  -s ./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
endif

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

git: fclean
ifeq ($(GITCOM), $(EMPTY))
	git add .
	git commit -m $(NAME)/$(DATE)
else
	git add .
	git commit -m $(NAME)/$(GITCOM)/$(DATE)
endif
	git push origin $(BRANCH)



# test: $(OBJS_TEST)
# ifeq ($(OS), Darwin)
# 	$(CC) $(GFLAGS) -fsanitize=address $(OBJS_TEST) -o test_unit 
# 	./test_unit $(NOP) $(TTD) $(TTE) $(TTS)
# else ifeq ($(OS), Linux)
# 	$(CC)  $(OBJS_TEST) -o $(NAME)
# 	valgrind --leak-check=full --log-file=filename  -s ./test_unit $(NOP) $(TTD) $(TTE) $(TTS)
# endif





# all: fclean $(NAME)

# re: all



# copy:
# 	cd .. && cd 42-katas/philosopher && rm -rf *
# 	cp -rf * ../42-katas/philosopher
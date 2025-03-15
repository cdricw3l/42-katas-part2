# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 22:40:28 by cw3l              #+#    #+#              #
#    Updated: 2025/03/15 08:48:12 by cw3l             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# https://www.gnu.org/software/make/manual/html_node/File-Name-Functions.html

NAME= philo
CC=cc
GCC=gcc
GFLAGS= -Werror -Wall -Wextra
mode=0
prod=0
test=1
noflag=2
gitcom=

SRCS_PETRI= $(wildcard srcs/petri_network/*.c)
SRCS_PHILO= $(wildcard srcs/philosopher/*.c)
SRCS_UTILS= $(wildcard srcs/utils/**/*.c)
SRCS_MAIN= srcs/main.c

OBJS_PETRI=$(SRCS_PETRI:%.c=%.o)
OBJS_PHILO=$(SRCS_PHILO:%.c=%.o)
OBJS_UTILS=$(SRCS_UTILS:%.c=%.o)
OBJS_MAIN=$(SRCS_MAIN:%.c=%.o)

DATE=$(shell date -Isecond)
BRANCH=$(shell git branch --show-current)

NOP= 5 		#number_of_philosophers
TTD= 4000 	#time_to_die
TTE= 4000 	#time_to_eat
TTS= 4000 	#time_to_sleep 

OS = $(shell uname)
EMPTY=

OBJS= $(OBJS_MAIN) $(OBJS_PETRI) $(OBJS_PHILO) $(OBJS_TEST) $(OBJS_UTILS) 
	
$(NAME): $(OBJS)
ifeq ($(mode), $(prod))
	$(CC) $(GFLAGS) $(OBJS) -o $(NAME)
else ifeq ($(mode), )
	@echo hello
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

# run:$(OBJS)
#ifeq ($(OS), Darwin)
# 	$(CC) $(GFLAGS)  -fsanitize=address $(OBJS) -o $(NAME)
# 	./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
# else ifeq ($(OS), Linux)
# 	$(GCC) $(GFLAGS) $(OBJS) -o $(NAME)
# 	valgrind --leak-check=full --log-file=filename  -s ./$(NAME) $(NOP) $(TTD) $(TTE) $(TTS)
# endif

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
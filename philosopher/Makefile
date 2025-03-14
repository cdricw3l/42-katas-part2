# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 22:40:28 by cw3l              #+#    #+#              #
#    Updated: 2025/03/14 23:54:59 by cw3l             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# https://www.gnu.org/software/make/manual/html_node/File-Name-Functions.html

NAME= philo
CC=cc
GCC= gcc

mode=0
test=1
dev=2
gitcom=

SRCS_DIR= srcs/petri_network srcs/utils/ srcs/main

SRCS= $(wildcard srcs/**/*.c)

OBJS= $(SRCS:%.c=%.o)

DATE=$(shell date -Isecond)
BRANCH=$(shell git branch --show-current)
#srcs/utils/%.c=%.o srcs/main/%.c=%.o
NOP= 5 		#number_of_philosophers
TTD= 4000 	#time_to_die
TTE= 4000 	#time_to_eat
TTS= 4000 	#time_to_sleep 

OS = $(shell uname)
EMPTY=

$(NAME): $(OBJS)
ifeq ($(mode), 0)
	$(CC)   -I. $(OBJS) -o $(NAME)
else ifeq ($(mode), 1)
	@echo hello
endif

git:
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

# clean:
# 	rm -f test_unit
# 	cd srcs && rm -f *.o 

# fclean: clean
# 	rm -f $(NAME)

# all: fclean $(NAME)

# re: all



# copy:
# 	cd .. && cd 42-katas/philosopher && rm -rf *
# 	cp -rf * ../42-katas/philosopher
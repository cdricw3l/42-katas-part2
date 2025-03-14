NAME=push_swap
DATE=$(shell date | sed 's/ /_/g')

gdev:
	git add .
	git commit -m $(NAME)/$(DATE) 
	git push
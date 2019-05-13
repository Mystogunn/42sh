##
## Makefile for Makefile in /home/Mystogun/exopis
##
## Made by Josselin COSMAO
## Login   <Mystogun@epitech.net>
##
## Started on  Sat Oct 15 16:46:52 2016 Josselin COSMAO
##

RM		= rm -rf

SRCS		= src/main.c				\
		  src/get_next_line.c			\
		  src/my_str_to_wordtab.c		\
		  src/my_function.c			\
		  src/my_function2.c			\
		  src/my_function3.c			\
		  src/path.c				\
		  src/my_exec.c				\
		  src/my_exec2.c			\
		  src/my_cd.c				\
		  src/setenv_cd.c			\
		  src/new_env.c				\
		  src/doble_malloc.c			\
		  src/home.c				\
		  src/get_prompt.c			\
		  src/parsing.c				\
		  src/space_and_tab.c			\
		  src/init_tab.c			\
		  src/push_tab.c			\
		  src/create_tab_pipes.c		\
		  pipes/pipe.c				\
		  pipes/call_access.c			\
		  pipes/my_str_to_word_tab.c		\
		  redirection/redirection.c		\
		  redirection/redirection_right.c	\
		  redirection/redirection_left.c	\
		  and_or/and_and.c			\
		  and_or/or_or.c			\
		  pipe_redirection/pipes.c		\

OBJS		= $(SRCS:.c=.o)

NAME		= 42sh

CC		= gcc

CPPFLAGS	+= -Iinclude

CFLAGS		+= -Wextra -Wall

LFLAGS		+= -L./lib/my -lmy

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./lib/my clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C ./lib/my fclean

re: fclean all

.PHONY:	all clean fclean re

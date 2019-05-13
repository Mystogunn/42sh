##
## Makefile for Makefile in /home/letoux/CPool_infinadd/lib/my
## 
## Made by Nicolas Bontoux
## Login   <letoux@epitech.net>
## 
## Started on  Thu Nov  3 10:50:18 2016 Nicolas Bontoux
## Last update Thu May 18 11:48:18 2017 Yuu
##

SRC		= my_putstr.c		\
		  my_find_prime_sup.c	\
		  my_getnbr.c		\
		  my_isneg.c		\
		  my_is_prime.c		\
		  my_power_rec.c	\
		  my_putchar.c		\
		  my_put_nbr.c		\
		  my_revstr.c		\
		  my_showmem.c		\
		  my_showstr.c		\
		  my_sort_int_tab.c	\
		  my_square_root.c	\
		  my_strcapitalize.c	\
		  my_strcat.c		\
		  my_strcmp.c		\
		  my_strcpy.c		\
		  my_str_isalpha.c	\
		  my_str_islower.c	\
		  my_str_isnum.c	\
		  my_str_isprintable.c	\
		  my_str_isupper.c	\
		  my_strlen.c		\
		  my_strlowcase.c	\
		  my_strncat.c		\
		  my_strncmp.c		\
		  my_strncpy.c		\
		  my_strstr.c		\
		  my_strupcase.c	\
		  my_swap.c		\
		  output.c

OBJ		= $(SRC:.c=.o)

NAME		= libmy.a

CC		= gcc

RM		= rm -rf

CPPFLAGS	+= -I../../include

CFLAGS		+= -g3 -Wall

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re

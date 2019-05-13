/*
** output.c for output.c in /home/letoux/CPool_infinadd
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Tue Oct 25 10:19:44 2016 Nicolas Bontoux
** Last update Tue Oct 25 14:32:39 2016 Nicolas Bontoux
*/

#include <unistd.h>
#include "libmy.h"

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

void	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_error(str[i]);
      i = i + 1;
    }
}

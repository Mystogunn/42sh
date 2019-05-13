/*
** my_str_isnum.c for my_str_isnum.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:54:40 2016 Nicolas Bontoux
** Last update Wed Nov  2 12:15:33 2016 Nicolas Bontoux
*/

#include "libmy.h"

int	my_str_isnum(char *str)
{
  int	l;

  l = 0;
  while (str[l])
    {
      if (str[l] >= '0' && str[l] <= '9')
	l = l + 1;
      else
	return (0);
    }
  return (1);
}

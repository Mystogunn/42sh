/*
** my_putstr.c for my_putstr.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:11:55 2016 Nicolas Bontoux
** Last update Tue Oct 25 09:14:39 2016 Nicolas Bontoux
*/

#include "libmy.h"

int	my_putstr(char *str)
{
  int	start;

  start = 0;
  while (str[start] != '\0')
    {
      my_putchar(str[start]);
      start = start + 1;
    }
  return (0);
}

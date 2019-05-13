/*
** my_strlen.c for my_strlen.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:14:07 2016 Nicolas Bontoux
** Last Update Mon Mar 27 11:16:31 2017 Bontoux Nicolas
*/

#include <stdlib.h>
#include "libmy.h"

int	my_strlen(char *str)
{
  int	count;

  count = 0;
  if (str == NULL)
    return (0);
  while (str[count] != '\0')
    {
      count = count + 1;
    }
  return (count);
}

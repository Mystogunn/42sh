/*
** my_strcmp.c for my_strcmp.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:40:50 2016 Nicolas Bontoux
** Last Update Thu Apr 20 11:29:51 2017 Bontoux Nicolas
*/

#include <stdlib.h>
#include "libmy.h"

int	my_strcmp(char *s1, char *s2)
{
  int	a;

  a = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0')
    {
      a = a + 1;
    }
  return (s1[a] - s2[a]);
}

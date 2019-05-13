/*
** my_revstr.c for my_revstr.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:35:54 2016 Nicolas Bontoux
** Last update Wed Oct 19 09:47:28 2016 Nicolas Bontoux
*/

#include "libmy.h"

char	*my_revstr(char *str)
{
  int	a;
  int	b;

  a = 0;
  b = (my_strlen(str) - 1);
  while (str[a] != '\0' && a < b)
    {
      my_swap((int *)&str[a], (int *)&str[b]);
      a = a + 1;
      b = b - 1;
    }
  return (str);
}

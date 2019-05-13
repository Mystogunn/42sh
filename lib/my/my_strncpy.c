/*
** my_strncpy.c for my_strncpy.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:32:59 2016 Nicolas Bontoux
** Last update Wed Oct 19 09:48:21 2016 Nicolas Bontoux
*/

#include "libmy.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	x;
  int	y;

  y = 0;
  x = 0;
  my_strlen(src);
  if (my_strlen(src) < n)
    {
      dest[my_strlen(dest)] = '\0';
    }
  if (n <= 0)
    {
      my_putchar('\0');
    }
  while (x != n)
    {
      dest[y] = src[x];
      x = x + 1;
      y = y + 1;
    }
  return (dest);
}

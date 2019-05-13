/*
** my_strcat.c for my_strcat.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Thu Oct 13 17:16:59 2016 Nicolas Bontoux
** Last Update Wed May 17 09:49:24 2017 Bontoux Nicolas
*/

#include <stdlib.h>
#include "libmy.h"

char	*my_srtcat(char *dest, char *src)
{
  int	x;
  int	y;
  int	a;
  char	*tmp;

  x = 0;
  a = 0;
  if (src == NULL || dest == NULL)
    return (NULL);
  y = my_strlen(dest);
  if ((tmp = malloc(sizeof(char) * (y + my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (dest[x] != '\0')
    {
      tmp[x] = dest[x];
      x = x + 1;
    }
  while (src[a] != '\0')
    {
      tmp[x + a] = src[a];
      a = a + 1;
    }
  tmp[x + a] = '\0';
  return (tmp);
}

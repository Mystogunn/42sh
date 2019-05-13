/*
** my_strcpy.c for my_strcpy.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:31:33 2016 Nicolas Bontoux
** Last update Sun May 21 20:40:36 2017 Josselin
*/

#include <stdlib.h>
#include "libmy.h"

char	*my_strcpy(char *dest, char *src)
{
  int	x;

  x = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    exit (1);
  while (src[x] != '\0')
    {
      if (src[x] == '\0')
	dest[x] = '\0';
      dest[x] = src[x];
      x = x + 1;
    }
  dest[x] = '\0';
  return (dest);
}

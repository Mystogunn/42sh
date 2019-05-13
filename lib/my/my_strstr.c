/*
** my_strstr.c for my_strstr.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:37:18 2016 Nicolas Bontoux
** Last update Fri Oct 28 10:43:55 2016 Nicolas Bontoux
*/

#include "libmy.h"

char	*my_strstr(char *str, char *to_find)
{
  int	x;
  int	y;
  int	o;
  int	z;

  x = 0;
  y = 0;
  z = 0;
  o = my_strlen(to_find);
  while (str[y] != '\0')
    {
      while (to_find[x] == str[y] && to_find[x] != '\0')
	{
	  x = x + 1;
	  y = y + 1;
	  if (to_find[x] != str[y])
	    {
	      x = 0;
	    }
	  z = y;
	}
      y = y + 1;
    }
  return (str + z - o);
}

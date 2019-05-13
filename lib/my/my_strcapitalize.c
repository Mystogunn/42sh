/*
** my_strcapitalize.c for my_strcapitalize.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:50:01 2016 Nicolas Bontoux
** Last update Thu Oct 27 17:52:55 2016 Nicolas Bontoux
*/

#include "libmy.h"

char	*my_strcapitalize(char *str)
{
  int	x;

  x = 1;
  if (str[0] >= 'a' && str[0] <= 'z')
    {
      str[0] = str[0] - 32;
    }
  while (str[x] != '\0')
    {
      if (str[x] >= 'A' && str[x] <= 'Z')
	{
	  str[x] = str[x] + 32;
	}
      if (str[x] == ' ' && str[x + 1] >= 'a' && str[x + 1] <= 'z')
	{
	  x = x + 1;
	  str[x] = str[x] - 32;
	}
      x = x + 1;
    }
  return (str);
}


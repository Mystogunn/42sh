/*
** my_str_to_word_tab.c for my_str_to_word_tab.c in /home/letoux/Documents/PSU_2016_minishell
** 
** Made by Bontoux Nicolas
** Login   <letoux@epitech.eu>
** 
** Started on  Mon Jan 16 14:32:17 2017 Bontoux Nicolas
** Last Update Mon May 15 16:31:16 2017 Bontoux Nicolas
*/

#include <stdlib.h>
#include "libmy.h"

static char	**party(int y, char *str, char **result, char signe)
{
  int		a;
  int		x;
  int		z;

  a = 0;
  x = 0;
  while (a < y)
    {
      while (str[x] == signe && str[x] != '\0')
	x = x + 1;
      z = 0;
      while (str[x] != signe && str[x] != '\0')
	{
	  result[a][z] = str[x];
	  x = x + 1;
	  z = z + 1;
	}
      a = a + 1;
    }
  return (result);
}

static char	**part(char *str, int y, char signe, char **result)
{
  int		a;
  int		x;
  int		z;

  a = 0;
  x = 0;
  while (a < y)
    {
      z = 0;
      while (str[x] == signe && str[x] != '\0')
	x = x + 1;
      while (str[x] != signe && str[x] != '\0')
	{
	  z = z + 1;
	  x = x + 1;
	}
      if ((result[a] = malloc(sizeof(char) * (z + 1))) == NULL)
	return (NULL);
      result[a][z] = '\0';
      a = a + 1;
    }
  result = party(y, str, result, signe);
  return (result);
}

char	**str_to_tab(char *str, char signe)
{
  char	**result;
  int	x;
  int	y;

  x = 0;
  y = 0;
  if (str[0] != signe)
    y = 1;
  while (str[x] != '\0')
    {
      if (str[x] == signe && str[x + 1] != signe && str[x + 1] != '\0')
	y = y + 1;
      x = x + 1;
    }
  if ((result = malloc(sizeof(char *) * (y + 1))) == NULL)
    return (NULL);
  result[y] = NULL;
  result = part(str, y, signe, result);
  return (result);
}

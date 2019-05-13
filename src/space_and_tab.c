/*
** space_and_tab.c for space_and_tab in /home/josselin/Music/PSU_2016_42sh
** 
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
** 
** Started on  Fri May 19 16:10:58 2017 Josselin
** Last update Sun May 21 19:58:19 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

int	check_end_string(char *str, int i)
{
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (0);
      i++;
    }
  return (-1);
}

char	*space_and_tab(char *str)
{
  char	*enter;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((enter = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
      failed_function("malloc");
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i])
    {
      if (check_end_string(str, i) == -1)
	break;
      while (str[i] == ' ' || str[i] == '\t')
	{
	  if (str[i + 1] != ' ' && str[i + 1] != '\t')
	    {
	      enter[j] = ' ';
	      j++;
	      i++;
	      break;
	    }
	  i++;
	}
      enter[j] = str[i];
      j++;
      i++;
    }
  enter[j] = '\0';
  free (str);
  return (enter);
}

/*
** create_tab_pipes.c for  in /home/josselin/Music/PSU_2016_42sh
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sun May 21 22:15:36 2017 Josselin
** Last update Sun May 21 22:42:34 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

char	*create_tab_pipes(char **arr, int start, int end)
{
  char	*str;
  int	i;
  int	j;

  j = 0;
  if ((str = malloc(sizeof(char) * 1000)) == NULL)
    failed_function("malloc");
  while (arr[start] != NULL)
    {
      i = 0;
      while (arr[start][i])
	{
	  str[j] = arr[start][i];
	  j++;
	  i++;
	}
      str[j] = ' ';
      j++;
      if (start == end)
	break;
      start++;
    }
  str[j] = '\0';
  return (str);
}

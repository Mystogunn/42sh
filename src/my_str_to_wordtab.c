/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/josselin/EPITECH/PSU_2016_minishell1
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Wed Jan 11 23:44:20 2017 Josselin
** Last update Sun May 21 20:08:15 2017 Josselin
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

char	**my_str_to_wordtab2(char *str, int len, int idx_str, char **arr)
{
  int	x;
  int	y;

  y = 0;
  while (str[idx_str] != 0)
    {
      if ((arr[y] = malloc(sizeof(char) * len + 1)) == NULL)
	failed_function("malloc");
      while ((str[idx_str] != 0)
	     && (str[idx_str] == ' ' || str[idx_str] == '\t'))
	idx_str += 1;
      x = 0;
      while (str[idx_str] != 0
	     && str[idx_str] != ' ' && str[idx_str] != '\t')
	       arr[y][x++] = str[idx_str++];
      arr[y++][x] = 0;
      while ((str[idx_str] != 0)
	     && (str[idx_str] == ' ' || str[idx_str] == '\t'))
	idx_str += 1;
    }
  arr[y] = NULL;
  return (arr);
}

char	**my_str_to_wordtab(char *str)
{
  int	len;
  int	idx_str;
  char	**arr;

  if ((len = my_strlen(str)) == -1)
    return (NULL);
  idx_str = 0;
  if ((arr = malloc(sizeof(char *) * len + 1)) == NULL)
    failed_function("malloc");
  arr = my_str_to_wordtab2(str, len, idx_str, arr);
  return (arr);
}

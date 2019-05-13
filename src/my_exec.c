/*
** my_exec.c for my_exec.c in /home/josselin/EPITECH/PSU_2016_minishell1
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Thu Jan 19 01:32:36 2017 Josselin
** Last update Sun May 21 20:21:06 2017 Josselin
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

char    **my_str_to_wordtab3(char *str, int len, int idx_str, char **arr)
{
  int   x;
  int   y;

  y = 0;
  while (str[idx_str] != 0)
    {
      if ((arr[y] = malloc(sizeof(char) * len + 1)) == NULL)
	failed_function("malloc");
      while ((str[idx_str] != 0)
	     && (str[idx_str] == ':'))
	idx_str += 1;
      x = 0;
      while (str[idx_str] != 0
	     && str[idx_str] != ':')
	arr[y][x++] = str[idx_str++];
      arr[y++][x] = 0;
      while ((str[idx_str] != 0)
	     && (str[idx_str] == ':'))
	idx_str += 1;
    }
  arr[y] = NULL;
  return (arr);
}

char    **my_str_tab(char *str)
{
  int   len;
  int   idx_str;
  char  **arr;

  if ((len = my_strlen(str)) == -1)
    return (NULL);
  idx_str = 0;
  if ((arr = malloc(sizeof(char *) * len + 1)) == NULL)
    failed_function("malloc");
  arr = my_str_to_wordtab3(str, len, idx_str, arr);
  return (arr);
}

char    *get_var(char **env, char *elem)
{
  int   i;
  int   len;

  i = 0;
  len = my_strlen(elem);
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], elem, len) == 0)
	return (env[i] + len + 1);
      i++;
    }
  return (NULL);
}

int	my_exec(char **arr, char **env)
{
  char	*path;
  char	**arr_path;
  int	b;

  b = 0;
  path = get_var(env, "PATH");
  (path != NULL) ? arr_path = my_str_tab(path) : 0;
  if (arr[0][0] != 0 && access(arr[0], F_OK | X_OK) == 0)
    b = execute(arr[0], arr, env);
  else if (my_strncmp(arr[0], "./", 2) != 0 &&
	   path != NULL && arr[0][0] != 0)
    {
      if ((path = my_access(arr_path, arr[0])) == NULL)
	return (1);
      b = execute(path, arr, env);
    }
  else if (arr[0][0] != 0 && access(arr[0], F_OK) == -1)
    b = access_error(arr[0], arr[0], -1);
  else if (arr[0][0] != 0 && access(arr[0], X_OK) == -1)
    b = access_error(arr[0], arr[0], 0);
  return (b);
}

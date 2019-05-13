/*
** my_cd.c for my_cd.c in /home/josselin/EPITECH/MINISHELL1/PSU_2016_minishell1
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Fri Jan 20 01:29:34 2017 Josselin
** Last update Sun May 21 20:35:25 2017 Josselin
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

char	*search(char *str, char **env)
{
  char	*dest;
  int	idx_dest;
  int	y;
  int	x;

  if ((dest = malloc(sizeof(char) * 4096)) == NULL)
    failed_function("malloc");
  idx_dest = 0;
  y = 0;
  while (env[y] != NULL && my_strncmp(env[y], str, my_strlen(str)) != 0)
    y = y + 1;
  if (env[y] == NULL)
    return (NULL);
  x = my_strlen(str);
  while (env[y][x] != 0)
    dest[idx_dest++] = env[y][x++];
  dest[idx_dest] = 0;
  return (dest);
}

int	my_cd(char **arr, char **env, char **tab)
{
  char	*dest;

  if (arr[1] == NULL || my_strcmp(arr[1], "~") == 0)
    dest = search("HOME=", env);
  else if (my_strcmp(arr[1], "-") == 0)
    dest = search("OLDPWD=", env);
  else
    dest = arr[1];
  setenv_cd(tab, env);
  if (dest == NULL)
    return (-1);
  if (chdir(dest) != -1)
    return (0);
  else if (access(dest, F_OK) == -1)
    {
      my_putstr(dest);
      my_putstr(" : No such file or directory.\n");
    }
  else if (access(dest, X_OK) == -1)
    my_putstr("Check the rights in the folder.\n");
  return (-1);
}

int	my_cd2(char **arr, char **env)
{
  char **tab;
  int	i;

  if (env[0] == NULL)
    return (1);
  if ((tab = malloc(sizeof(char *) * 10)) == NULL)
    failed_function("malloc");
  tab[0] = "setenv";
  tab[1] = "OLDPWD=";
  tab[2] = get_prompt2();
  tab[3] = NULL;
  i = my_cd(arr, env, tab);
  return (i);
}

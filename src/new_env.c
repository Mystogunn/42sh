/*
** new_env.c for mew_env.c in /home/josselin/EPITECH/MINISELL2/PSU_2016_minishell2
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Tue Apr  4 12:07:31 2017 Josselin
** Last update Sun May 21 20:42:13 2017 Josselin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*last_line(char **env, int i)
{
  char	*str;
  int	a;

  a = 0;
  if ((str = malloc(sizeof(char) * (my_strlen(env[i])) + 1)) == NULL)
    failed_function("malloc");
  while (env[i][a] != 0)
    {
      str[a] = env[i][a];
      a++;
    }
  str[a] = 0;
  return (str);
}

char	**new_env(char **env)
{
  char	**copy_env;
  int	i;
  int	l;

  i = 0;
  l = 0;
  copy_env = create_map(503, (my_strlen(env[i])));
  while (env[i] != NULL)
    {
      while (env[i][l] != 0)
	{
	  copy_env[i][l] = env[i][l];
	  l++;
 	}
      l = 0;
      if (my_strncmp(env[i], "_=", 2) == 0)
	{
	  copy_env[i] = last_line(env, i);
	  copy_env[i + 1] = NULL;
	  return (copy_env);
	}
      i++;
    }
  copy_env[i] = NULL;
  return (copy_env);
}

/*
** or_or.c for or_or.c in /home/letoux/PSU_2016_42sh
** 
** Made by Bontoux Nicolas
** Login   <letoux@epitech.eu>
** 
** Started on  Wed May 17 10:13:52 2017 Bontoux Nicolas
** Last update Sun May 21 23:33:28 2017 Josselin
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "libmy.h"

static char	**select_end_double_pipe(char **result, int place)
{
  char		**tab;
  int		x;
  int		a;

  a = 0;
  x = place + 1;
  while (result[x] != NULL && result[x][0] != '|' && result[x][0] != ';'
	 && result[x][0] != '<' && result[x][0] != '>')
    x = x + 1;
  x = x - 1;
  if ((tab = malloc(sizeof(char *) * (x - place + 1))) == NULL)
    failed_function("malloc");
  tab[x - place] = NULL;
  while (a < x - place)
    {
      if ((tab[a] = malloc(sizeof(char) * (my_strlen(result[place + a + 1])
					   + 1))) == NULL)
	failed_function("malloc");
      tab[a][my_strlen(result[place + a + 1])] = '\0';
      tab[a] = my_strcpy(tab[a], result[place + a + 1]);
      a = a + 1;
    }
  return (tab);
}

static int	check(int x, int *a, char **result, char **path)
{
  char	**tab;

  while (path[x] != NULL)
    {
      if (access(my_srtcat(path[x], my_srtcat("/", result[*a])), R_OK) == -1)
	x = x + 1;
      else
	break;
    }
  if (path[x] == NULL)
    {
      printf("%s: Command not found.\n", result[*a]);
      return (84);
    }
  else
    {
      tab = select_end_double_pipe(result, *a - 1);
      execvp(tab[0], tab);
    }
  return (0);
}

static int	error(char **result)
{
  int	x;

  x = 0;
  if (strcmp(result[x], "||") == 0)
    {
      printf("Invalid null command.\n");
      return (1);
    }
  while (result[x] != NULL)
    {
      if ((my_strcmp(result[x], "||") == 0 && result[x + 1] == NULL) ||
	  (my_strcmp(result[x], "||") == 0 && my_strcmp(result[x + 1], "||") == 0))
	{
	  printf("Invalid null command.\n");
	  return (1);
	}
      x = x + 1;
    }
  return (0);
}

int	init_or(char **result)
{
  char	**path;
  int	x;
  int	a;
  int	pid;

  a = 0;
  error(result);
  if ((pid = fork()) == -1)
    return (84);
  if (pid == 0)
    {
      path = str_to_tab(getenv("PATH"), ':');
      while (result[a] != NULL)
	{
	  x = 0;
	  if (a == 0 || strcmp(result[a - 1], "||") == 0)
	    check(x, &a, result, path);
	  a = a + 1;
	}
      return (127);
    }
  else
    return (0);
  return (0);
}

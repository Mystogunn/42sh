/*
** call_access.c for call_access.c in /home/letoux/PSU_2016_42sh
** 
** Made by Bontoux Nicolas
** Login   <letoux@epitech.eu>
** 
** Started on  Tue May 16 13:58:33 2017 Bontoux Nicolas
** Last Update Fri May 19 11:25:16 2017 Bontoux Nicolas
** Last update Thu May 18 11:40:42 2017 Yuu
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/libmy.h"

static int	check(int x, int *a, char **result, char **path)
{
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
      return (1);
    }
  return (0);
}

int	call_access(char **result)
{
  char	**path;
  int	x;
  int	a;

  a = 0;
  path = str_to_tab(getenv("PATH"), ':');
  while (result[a] != NULL)
    {
      x = 0;
      if (a == 0 || result[a - 1][0] == '|')
	{
	  if (check(x, &a, result, path) == 1)
	    exit(1);
	}
      else if (result[a][0] == '>')
	break;
      a = a + 1;
    }
  if (result[a] == NULL)
    init_pipe(result);
  else
    init_pipe_redi(result, a);
  return (0);
}

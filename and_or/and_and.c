/*
** and_and.c for emacs in /home/yuu/PSU_2016_42sh/and_or
** 
** Made by Yuu
** Login   <yunhan.xia@epitech.eu>
** 
** Started on  Tue May 16 12:08:57 2017 Yuu
** Last update Sun May 21 23:30:52 2017 Josselin
*/

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

static char	**select_and(char **result, int place)
{
  char		**tab;
  int		x;
  int		i;

  i = 0;
  x = place - 1;
  while (x != 0 && result[x][0] != '|' && result[x][0] != ';'
	 && result[x][0] != '<' && result[x][0] != '>')
    x = x - 1;
  if ((tab = malloc(sizeof(char *) * (place - x + 1))) == NULL)
    failed_function("malloc");
  tab[place - x] = NULL;
  while (i < place - x)
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(result[x + i]) + 1)))
	  == NULL)
	failed_function("malloc");
      tab[i][my_strlen(result[x + i])] = '\0';
      tab[i] = my_strcpy(tab[i], result[x + i]);
      i = i + 1;
    }
  return (tab);
}

static char	**select_end_and(char **result, int place)
{
  char		**tab;
  int		x;
  int		i;

  i = 0;
  x = place + 1;
  while (result[x] != NULL && result[x][0] != '|' && result[x][0] != ';'
	 && result[x][0] != '<' && result[x][0] != '>')
    x = x + 1;
  x = x - 1;
  if ((tab = malloc(sizeof(char *) * (x - place + 1))) == NULL)
    failed_function("malloc");
  tab[x - place] = NULL;
  while (i < x - place)
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(result[place + i + 1])
					   + 1))) == NULL)
	failed_function("malloc");
      tab[i][my_strlen(result[place + i + 1])] = '\0';
      tab[i] = my_strcpy(tab[i], result[place + i + 1]);
      i = i + 1;
    }
  return (tab);
}

static int      find_and(char **result)
{
  int           x;

  x = 0;
  while  (strcmp(result[x], "&&") != 0)
    x = x + 1;
  return (x);
}

static char	**gest_error(char **result)
{
  char		**end;
  end = select_end_and(result, find_and(result));
  if (end[0] == NULL)
    {
      puts(AND_NULL);
      return (NULL);
    }
  return (end);
}

int		init_and(char **result)
{
  pid_t	pid;
  char	**start;
  char	**end;
  int	status;

  if ((end = gest_error(result)) == NULL)
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      if (strcmp(result[0], "&&") != 0)
	{
	  start = select_and(result, find_and(result));
	  if (execvp(start[0], start) == -1)
	    return (1);
	}
    }
  else
    {
      waitpid(pid, &status, WUNTRACED);
      if (execvp(end[0], end) == -1)
	return (1);
    }
  return (0);
}

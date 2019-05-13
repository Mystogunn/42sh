/*
** pipe.c for pipe.c in /home/letoux/PSU_2016_42sh/pipes
** 
** Made by Bontoux Nicolas
** Login   <letoux@epitech.eu>
** 
** Started on  Mon May  8 13:33:42 2017 Bontoux Nicolas
** Last Update Fri May 19 11:14:04 2017 Bontoux Nicolas
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/my.h"
#include "../include/libmy.h"

static char	**select_pipe(char **result, int place)
{
  char		**tab;
  int		x;
  int		a;

  a = 0;
  x = place - 1;
  while (x != 0 && result[x - 1][0] != '|' && result[x - 1][0] != ';'
	 && result[x - 1][0] != '<' && result[x - 1][0] != '>')
    x = x - 1;
  tab = malloc(sizeof(char *) * (place - x + 1));
  tab[place - x] = NULL;
  while (a < place - x)
    {
      tab[a] = malloc(sizeof(char) * (my_strlen(result[x + a]) + 1));
      tab[a][my_strlen(result[x + a])] = '\0';
      tab[a] = my_strcpy(tab[a], result[x + a]);
      a = a + 1;
    }
  return (tab);
}

static char	**select_end_pipe(char **result, int place)
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
  tab = malloc(sizeof(char *) * (x - place + 1));
  tab[x - place] = NULL;
  while (a < x - place)
    {
      tab[a] = malloc(sizeof(char) * (my_strlen(result[place + a + 1]) + 1));
      tab[a][my_strlen(result[place + a + 1])] = '\0';
      tab[a] = my_strcpy(tab[a], result[place + a + 1]);
      a = a + 1;
    }
  return (tab);
}

static int  	find_pipe(char **result)
{
  static int	x = 0;
  int		a;

  a = 0;
  while (result[a] != NULL)
    a = a + 1;
  if (x > 0)
    x = x + 1;
  if (x > a)
    return (-2);
  while (x < a && result[x][0] != '|')
    x = x + 1;
  if (x == a)
    return (-1);
  return (x);
}

static int	dady_son(int fd_in, int nb, int pip[2], char **tab)
{
  dup2(fd_in, 0);
  close(pip[0]);
  if (nb != -1)
    dup2(pip[1], 1);
  execvp(tab[0], tab);
  return (0);
}

int	init_pipe(char **result)
{
  char	**tab;
  int	nb[2];
  int	pip[2];
  int	pid;

  nb[1] = 0;
  nb[0] = find_pipe(result);
  tab = select_pipe(result, nb[0]);
  while (nb[0] != -2)
    {
      if (pipe(pip) == -1)
	return (84);
      if ((pid = fork()) == -1)
	return (84);
      if (pid == 0)
	dady_son(nb[1], nb[0], pip, tab);
      else
	{
	  close(pip[1]);
	  nb[1] = pip[0];
	  tab = select_end_pipe(result, nb[0]);
	  nb[0] = find_pipe(result);
	}
    }
  return (0);
}

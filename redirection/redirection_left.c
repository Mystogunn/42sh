/*
** redirection_left.c for redirection lft in /home/Lud/PSU_2016_42sh/redirection
** 
** Made by Lud Ame
** Login   <Lud@epitech.net>
** 
** Started on  Fri May 12 17:24:52 2017 Lud Ame
** Last update Sun May 21 20:52:00 2017 Josselin
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

static int	find_redi_left(char **tab, int *left)
{
  int		x;

  x = 0;
  while (tab[x])
    {
      if (tab[x][0] == '<')
	{
	  if (tab[x][1] == '<' && tab[x][2] == '\0')
	    {
	      *left = 2;
	      return (x);
	    }
	  *left = 1;
	  return (x);
	}
      x++;
    }
  return (-1);
}

static char	**get_redi(char **result, int place)
{
  char		**tab;
  int		x;
  int		a;

  a = 0;
  x = place - 1;
  while (x != 0 && result[x][0] != '|' && result[x][0] != ';'
	 && result[x][0] != '<' && result[x][0] != '>')
    x = x - 1;
  if ((tab = malloc(sizeof(char *) * (place - x + 1))) == NULL)
    return (NULL);
  tab[place - x] = NULL;
  while (a < place - x)
    {
      if ((tab[a] = malloc(sizeof(char)
			   * (my_strlen(result[x + a]) + 1))) == NULL)
	return (NULL);
      tab[a][my_strlen(result[x + a])] = '\0';
      tab[a] = my_strcpy(tab[a], result[x + a]);
      a = a + 1;
    }
  return (tab);
}

static int	left_redir_double(char **tab, int x, int left, char **start)
{
  struct stat	sb;
  int		fd;
  char		*str;

  (void)(sb);
  if (left == 1)
    {
      x = x + 1;
      fd = open(tab[x], O_RDWR);
      dup2(fd, 0);
      execvp(start[0], start);
    }
  else if (left == 2)
    {
      str = NULL;
      my_putstr("? ");
      str = get_next_line(0);
      while (str != NULL && my_strcmp(str, tab[x + 1]) != 0)
	{
	  my_putstr("? ");
	  str = get_next_line(0);
	}
      execvp(start[0], start);
    }
  return (0);
}

static int	redirection_error(char **tab, int place)
{
  if (tab[place + 1] == NULL)
    {
      my_putstr("Missing name for redirect.");
      return (1);
    }
  else if (place == 0)
    {
      my_putstr("Invalid null command.");
      return (1);
    }
  return (0);
}

int		left_redirection(char **tab)
{
  int		x;
  int		left;
  char		**start;

  x = 0;
  left = 0;
  if (tab[0] == NULL)
    return (0);
  if ((x = find_redi_left(tab, &left)) < 0)
    return (1);
  if ((redirection_error(tab, x)) != 0)
    return (1);
  if ((start = get_redi(tab, x)) == NULL)
    return (1);
  if ((left_redir_double(tab, x, left, start)) == -1)
    return (1);
  return (0);
}

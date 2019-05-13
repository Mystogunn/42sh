/*
** redirection.c for redirection.c  in /home/letoux/PSU_2016_42sh
** 
** Made by Bontoux Nicolas
** Login   <letoux@epitech.eu>
** 
** Started on  Thu May 11 15:08:17 2017 Bontoux Nicolas
** Last update Sun May 21 23:35:44 2017 Josselin
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/my.h"
#include "../include/libmy.h"

static char	**select_redi(char **result, int place)
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
    failed_function("malloc");
  tab[place - x] = NULL;
  while (a < place - x)
    {
      if ((tab[a] = malloc(sizeof(char) * (my_strlen(result[x + a]) + 1)))
	  == NULL)
	failed_function("malloc");
      tab[a][my_strlen(result[x + a])] = '\0';
      tab[a] = my_strcpy(tab[a], result[x + a]);
      a = a + 1;
    }
  return (tab);
}

static char	**select_end_redi(char **result, int place)
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

static int	find_redir(char **result)
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
  while (x < a && result[x][0] != '>')
    x = x + 1;
  if (x == a)
    return (-1);
  return (x);
}

static int	redirection(char **path, char **tab, char **res, int nb)
{
  struct stat	sb;
  int		fd;
  int		pid;

  if ((pid = fork()) == -1)
    return (84);
  if (pid == 0)
    {
      if (res[nb][1] == '>')
	end_double_redirection_right(tab, path);
      else
	{
	  if (stat(tab[0], &sb) == -1)
	    fd = open(tab[0], O_CREAT | O_RDWR, 0666);
	  else
	    fd = open(tab[0], O_RDWR);
	  dup2(fd, 1);
	  execvp(path[0], path);
	}
    }
  else
    return (0);
  return (0);
}

int		init_redi(char **result)
{
  char		**tab;
  char		**check;
  char		**path;
  int		nb;

  nb = find_redir(result);
  check = str_to_tab(getenv("PATH"), ':');
  path = select_redi(result, nb);
  if (check_the_way_believe_your_spirit(check, path) == 84)
    return (1);
  while (nb != -1)
    {
      tab = select_end_redi(result, nb);
      redirection(path, tab, result, nb);
      nb = find_redir(result);
    }
  return (0);
}

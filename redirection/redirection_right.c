/*
** redirection_right.c for redirection_right.c in /home/letoux/PSU_2016_42sh
** 
** Made by Bontoux Nicolas
** Login   <letoux@epitech.eu>
** 
** Started on  Wed May 17 09:31:01 2017 Bontoux Nicolas
** Last Update Fri May 19 11:38:08 2017 Bontoux Nicolas
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/my.h"
#include "../include/libmy.h"

int	check_the_way_believe_your_spirit(char **check, char **path)
{
  int	x;

  x = 0;
  while (check[x] != NULL)
    {
      if (access(my_srtcat(check[x], my_srtcat("/", path[0])), R_OK) == -1)
	x = x + 1;
      else
	break;
    }
  if (check[x] == NULL)
    {
      printf("%s: Command not found.\n", path[0]);
      return (1);
    }
  return (0);
}

int	end_double_redirection_right(char **tab, char **path)
{
  struct stat	sb;
  int		fd;

  if (stat(tab[0], &sb) == -1)
    fd = open(tab[0], O_CREAT | O_RDWR, 0666);
  else
    fd = open(tab[0], O_RDWR | O_APPEND);
  dup2(fd, 1);
  execvp(path[0], path);
  return (84);
}

/*
** my_exec2.c for my_exec2.c in /home/josselin/EPITECH/42sh/PSU_2016_42sh
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Mon May  8 06:08:51 2017 Josselin
** Last update Sun May 21 22:53:37 2017 Josselin
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int     access_error(char *cp, char *elem, int c)
{
  int   b;

  b = 0;
  if (c == -1)
    {
      my_error("Command not found.\n", elem);
      b = 1;
    }
  else if (cp != NULL && access(cp, X_OK) == -1)
    {
      my_error("Permission denied.\n", elem);
      b = 1;
    }
  return (b);
}

char    *my_access(char **path, char *elem)
{
  int   i;
  int   b;
  char  *cp;

  i = 0;
  b = 0;
  if ((cp = malloc(sizeof(char) * 1024)) == NULL)
    failed_function("malloc");
  while (path[i] != NULL && b == 0)
    {
      my_strcpy(cp, path[i]);
      my_strcat2(cp, "/");
      my_strcat2(cp, elem);
      (access(cp, F_OK) == 0) ? b = 1 : 0;
      (b == 0) ? i++ : 0;
      (path[i] == NULL) ? b = -1 : 0;
    }
  if (access_error(cp, elem, b) == 1)
    return (NULL);
  return (cp);
}

int     sig(pid_t pid)
{
  if (pid == 11)
    {
      my_putstr("Segmentation fault\n");
      return (139);
    }
  else if (pid == 8)
    {
      my_putstr("Floating exception\n");
      return (136);
    }
  else if (pid == 139)
    {
      my_putstr("Segmentation fault (core dumped)\n");
      return (139);
    }
  else if (pid == 136)
    {
      my_putstr("Floating exception (core dumped)\n");
      return (136);
    }
  return (0);
}

int	execute(char *path, char **opt, char **env)
{
  pid_t	pid;
  int	b;

  if ((pid = fork()) == -1)
    failed_function("Fork");
  b = 0;
  if (pid == 0)
    {
      if (execve(path, opt, env) == -1)
	exit(1);
    }
  else
    {
      if ((wait(&pid)) == -1)
	failed_function("wait");
      b = sig(pid);
    }
  return (b);
}

/*
** main2.c for home in /home/josselin/EPITECH/42sh/PSU_2016_42sh
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Thu May  4 14:43:56 2017 Josselin
** Last update Fri May 26 16:31:11 2017 Josselin
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int	func_exit(char *str, int return_value)
{
  char	**tab;

  tab = my_str_to_wordtab(str);
  if (tab[1] != NULL)
    return (my_getnbr(tab[1]));
  return (return_value);
}

void	my_signal(int sign)
{
  char	*prompt;

  if (sign == SIGINT)
    {
      prompt = get_prompt2();
      if (prompt == NULL)
	my_putstr("\n> ");
      else
	{
	  my_putstr("\n");
	  my_putstr(prompt);
	  my_putstr("> ");
	}
    }
}

int	command(char **env, char **arr, int return_value)
{
  if ((my_strcmp(arr[0], "echo") == 0) && my_strcmp(arr[1], "$?") == 0)
    {
      if ((printf("%d\n", return_value)) < 0)
	failed_function("printf");
    }
  else if (my_strcmp(arr[0], "cd") == 0)
    return_value = my_cd2(arr, env);
  else
    return_value = my_exec(arr, env);
  return (return_value);
}

int		home(char **env)
{
  char		*enter;
  t_copy_env	var;

  var.return_value = 0;
  signal(SIGINT, my_signal);
  while (1)
    {
      get_prompt();
      if ((enter = get_next_line(0)) == NULL)
	return (var.return_value);
      if (enter[0] == 0)
	continue;
      if (my_strncmp(enter, "exit", 4) == 0)
	{
	  var.return_value = func_exit(enter, var.return_value);
	  break;
	}
      var.return_value = parsing(enter, env, var);
    }
  free(enter);
  return (var.return_value);
}

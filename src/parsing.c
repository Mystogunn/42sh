/*
** parsing.c for parsing.c in /tmp/PSU_2016_42sh
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Tue May 16 06:41:06 2017 Josselin
** Last update Mon May 22 00:32:01 2017 Josselin
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

int	pipes_parsing(char **arr, int i, t_copy_env *var)
{
  int	end;
  char	**tab;

  end = nbr_of_pipes(arr, i);
  tab = my_str_to_wordtab(create_tab_pipes(arr, i, end));
  var->return_value = call_access(tab);
  return (end);
}

int	semicolon(char **arr, int i, char **env, t_copy_env *var)
{
  char	**tab;

  tab = my_str_to_wordtab(arr[i]);
  var->return_value = command(env, tab, var->return_value);
  i = i + 1;
  free_tab(tab);
  return (i);
}

int	init_redirection(char **arr, int i, t_copy_env *var)
{
  int	end;
  char	**tab;

  end = nbr_of_redirection(arr, i);
  tab = push_tab(arr, i, end);
  if (arr[i + 1][0] == '>')
    var->return_value = init_redi(tab);
  else
    var->return_value = left_redirection(tab);
  if (arr[end + 1] != NULL || arr[end + 2] != NULL)
    end = end + 1;
  return (end);
}

int	init_for_and(char **arr, int i, t_copy_env *var)
{
  int	end;
  char	**tab;

  end = i + 2;
  tab = push_tab(arr, i , end);
  var->return_value = init_and(tab);
  return (end);
}

int	parsing(char *str, char **env, t_copy_env var)
{
  char		**arr;

  var.i = 0;
  str = space_and_tab(str);
  arr = init_pars(str);
  while (arr[var.i] != NULL)
    {
      if (arr[var.i + 1] == NULL || arr[var.i + 1][0] == 0
	  || arr[var.i + 1][0] == ';')
	var.i = semicolon(arr, var.i, env, &var);
      else if ((arr[var.i + 1][0] == '|' && arr[var.i + 1][1] != '|') ||
	       (arr[var.i + 1][0] == '>' && arr[var.i + 3] != NULL && arr[var.i + 3][0] == '|') ||
	       (arr[var.i + 1][0] == '<' && arr[var.i + 3] != NULL && arr[var.i + 3][0] == '|'))
	       var.i = pipes_parsing(arr, var.i, &var);
      else if (arr[var.i + 1][0] == '>' || arr[var.i + 1][0] == '<')
	var.i = init_redirection(arr, var.i, &var);
      else if (arr[var.i + 1][0] == '&' && arr[var.i + 1][1] == '&')
	var.i = init_for_and(arr, var.i, &var);
      else if (arr[var.i + 1][0] == '|' && arr[var.i + 1][1] == '|')
	var.i = init_for_or(arr, var.i, &var);
      var.i = var.i + 1;
    }
  free_tab(arr);
  free (str);
  return (var.return_value);
}

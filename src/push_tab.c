/*
** push_tab.c for push_tab.c in /home/josselin/Music/PSU_2016_42sh
** 
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
** 
** Started on  Sat May 20 18:57:35 2017 Josselin
** Last update Mon May 22 00:32:32 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

int	init_for_or(char **arr, int i, t_copy_env *var)
{
  int	end;
  char	**tab;

  end = i + 2;
  tab = push_tab(arr, i, end);
  var->return_value = init_or(tab);
  return (end);
}

int	nbr_of_pipes(char **arr, int i)
{
  int	end;

  end = i;
  while (42)
    {
      if (arr[end + 1] == NULL || (arr[end + 1][0] == '|' &&
	   arr[end + 3] == NULL) || (end > 1 && arr[end + 1][0] == '>'
      	   && arr[end - 1][0] == '|' && arr[end + 3] == NULL) ||
	  (end > 1 && arr[end + 1][0] == '>' && arr[end - 1][0] == '|' &&
	   arr[end + 3][0] == '|') || (end > 1 && arr[end + 1][0] == '<'
      	   && arr[end - 1][0] == '|' && arr[end + 3] == NULL) ||
	  (end > 1 && arr[end + 1][0] == '<' && arr[end - 1][0] == '|' &&
	   arr[end + 3][0] != '|'))
	{
	  end = end + 2;
	  break;
	}
      else if (arr[end + 1] == NULL ||
	       (arr[end + 1][0] == '>' && arr[end + 3][0] != '|') ||
	       (arr[end + 1][0] == '<' && arr[end + 3][0] != '|') ||
	       (arr[end + 1][0] != '|' && arr[end + 1][0] != '<' &&
	       arr[end + 1][0] != '>'))
	break;
      end = end + 2;
    }
  return (end);
}

int	nbr_of_redirection(char **arr, int i)
{
  while (arr[i])
    {
      i = i + 2;
      if (arr[i + 1] == NULL)
	break;
      else if (arr[i + 1][0] != '<' && arr[i + 1][0] != '>')
	break;
    }
  return (i);
}

char	*copy_line(char *str)
{
  char	*line;
  int	i;

  i = 0;
  if ((line = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    failed_function("malloc");
  while (str[i])
    {
      line[i] = str[i];
      i++;
      if (str[i] == ' ' && str[i + 1] == 0)
	break;
      if (str[i] == ' ' && str[i + 1] != ' ')
	i = i + 1;
    }
  line[i] = '\0';
  return (line);
}

char	**push_tab(char **arr, int start, int end)
{
  char	**tab;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (end + 1))) == NULL)
    failed_function("malloc");
  while (arr[start] != NULL)
    {
      tab[i] = copy_line(arr[start]);
      if (start == end)
	{
	  i++;
	  break;
	}
      i++;
      start++;
    }
  tab[i] = NULL;
  return (tab);
}

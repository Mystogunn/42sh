/*
** init_tab.c for init_tab.c in /home/josselin/Music/PSU_2016_42sh
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Sat May 20 17:32:25 2017 Josselin
** Last update Mon May 22 00:17:54 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

char    **malloc_tab(char *str)
{
  char **arr;
  int   i;

  if ((arr = malloc(sizeof(char *) * 10000)) == NULL)
    failed_function("malloc");
  i = 0;
  while (str[i])
    {
      if ((arr[i] = malloc(sizeof(char) * 10000)) == NULL)
	failed_function("malloc");
      i++;
    }
  arr[i] = NULL;
  return (arr);
}

char    *push_spec(char *line, char *str, int i)
{
  int   j;

  j = 0;
  while (str[i] == ';' || str[i] == '|' || str[i] == '<' || str[i] == '>'
	 || str[i] == '&')
    {
      line[j] = str[i];
      j++;
      i++;
    }
  line[j] = '\0';
  return (line);
}

int     check_spec(char *str, int i)
{
  while ((str[i] == '|' && str[i + 2] != '|') ||
	 (str[i] == '<' && str[i + 2] != '<') ||
	 (str[i] == '>' && str[i + 2] != '>') ||
	 (str[i] == '&' && str[i + 2] != '&'))
    i++;
  i = i + 1;
  return (i);
}

char    **init_pars(char *str)
{
  char  **arr;
  int   i;
  int   j;
  int   a;

  a = 0;
  i = 0;
  arr = malloc_tab(str);
  while (str[i])
    {
      j = 0;
      while (str[i])
	{
	  arr[a][j] = str[i];
	  j++;
	  arr[a][j] = '\0';
	  i++;
	  if (str[i] == ';' || str[i] == '|' || str[i] == '<' || str[i] == '>'
	      || str[i] == '&')
	    {
	      a++;
	      arr[a] = push_spec(arr[a], str, i);
	      i = check_spec(str, i);
	      break;
	    }
	}
      a++;
    }
  arr[a] = NULL;
  arr[a + 1] = NULL;
  return (arr);
}

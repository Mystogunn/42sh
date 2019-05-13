/*
** my_function3.c for  in /home/josselin/EPITECH/42sh/PSU_2016_42sh
** 
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
** 
** Started on  Mon May  8 06:25:09 2017 Josselin
** Last update Mon May 22 00:21:24 2017 Josselin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int     my_getnbr(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 0;
  if (str[0] == '-' && str[1] != '\0')
    i = i + 1;
  while (str[i] != '\0')
    {
      n = n + str[i] - 48;
      n = n * 10;
      i = i + 1;
    }
  n = n / 10;
  if (str[0] == '-')
    return (-1 * n);
  else
    return (n);
}

void	failed_function(char *str)
{
  my_putstr_error("failed ");
  my_putstr_error(str);
  my_putstr_error("\n");
  exit (84);
}

char    *my_strcat2(char *dest, char *src)
{
  int   i;
  int   a;

  a = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[a + i] = src[i];
      i = i + 1;
    }
  dest[a + i] = '\0';
  return (dest);
}

void	print_tab(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      my_putstr(str[i++]);
      write(1, "\n", 1);
    }
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  while (i > 0)
    {
      free (tab[i]);
      i--;
    }
  free (tab);
}

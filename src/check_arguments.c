/*
** change_env.c for  in /home/josselin/EPITECH/42sh/PSU_2016_42sh
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Mon May  8 09:04:43 2017 Josselin
** Last update Mon May  8 09:24:19 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

int	check_setenv(char **arr)
{
  if (arr[3] != NULL)
    {
      my_putstr("setenv: Too many arguments.");
      return (1);
    }
  if (arr[1][0] >= '0' && arr[1][0] <= '9')
    {
      my_putstr("setenv: Variable name must begin with a letter.");
      return (1);
    }
  return (0);
}

int	check_unsetenv(char **arr)
{
  if (arr[1] == NULL)
    {
      my_putstr("unsetenv: Too few arguments.");
      return (1);
    }
  return (0);
}

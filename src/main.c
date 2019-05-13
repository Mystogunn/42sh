/*
** main2.c for main in /home/josselin/EPITECH/42sh/PSU_2016_42sh
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Thu May  4 14:46:27 2017 Josselin
** Last update Mon May 22 00:09:35 2017 Josselin
*/

#include "my.h"

int	main(int ac, char **av, char **env)
{
  int	i;

  (void)(ac);
  (void)(av);
  i = home(env);
  return (i);
}

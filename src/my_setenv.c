/*
** my_setenv.c for my_setenv in /tmp/PSU_2016_42sh
** 
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
** 
** Started on  Fri May 12 07:20:12 2017 Josselin
** Last update Fri May 12 15:16:15 2017 Yuu
*/

#include "my.h"

void	my_setenv(char **arr, char **env)
{
  if (check_setenv(arr) == 1)
    return (1);
}

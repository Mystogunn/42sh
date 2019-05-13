/*
** doble_malloc.c for yes in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Tue Feb 21 22:07:23 2017 Josselin
** Last update Sun May 21 20:44:48 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

char    **create_map(int l, int cl)
{
  char  **map;
  int   i;

  i = 0;
  if ((map = malloc(sizeof(char *) * (l + 5))) == NULL)
    failed_function("malloc");
  l = l + 3;
  while (l > 0)
    {
      if ((map[i] = malloc(sizeof(char) + (cl + 86))) == NULL)
	failed_function("malloc");
      i = i + 1;
      l = l - 1;
    }
  map[i + 1] = '\0';
  return (map);
}

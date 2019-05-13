/*
** my_swap.c for my_swap.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:10:33 2016 Nicolas Bontoux
** Last Update Tue Nov 29 11:57:52 2016 Bontoux Nicolas
*/

#include "libmy.h"

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}

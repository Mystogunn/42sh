/*
** my_isneg.c for my_isneg.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:00:15 2016 Nicolas Bontoux
** Last Update Mon Jan 16 14:36:31 2017 Bontoux Nicolas
*/

#include "libmy.h"

int	my_isneg(int n)
{
  if (n < 0)
    {
      my_putchar('N');
    }
  else
    {
      my_putchar('P');
    }
  return (0);
}

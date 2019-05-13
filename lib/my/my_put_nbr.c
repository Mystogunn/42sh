/*
** my_put_nbr.c for my_put_nbr.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:08:18 2016 Nicolas Bontoux
** Last Update Mon Dec  5 10:03:56 2016 Bontoux Nicolas
*/

#include "libmy.h"

int	my_put_nbr(int nb)
{
  int	o;

  o = 1;
  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
        {
          my_putchar('-');
          nb = nb * -1;
        }
      while ((nb / o) > 9)
        {
          o = o * 10;
        }
      while (o >= 1)
        {
          my_putchar((nb / o) % 10 + 48);
          o = o / 10;
        }
    }
  return (0);
}

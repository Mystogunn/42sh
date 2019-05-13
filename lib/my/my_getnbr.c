/*
** my_getnbr.c for my_getnbr.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 12:17:23 2016 Nicolas Bontoux
** Last Update Tue Dec 13 17:43:58 2016 Bontoux Nicolas
*/

#include "libmy.h"

int	my_getnbr(char *str)
{
  int	nb;
  int	r;
  int	signe;

  signe = 1;
  r = 1;
  nb = 0;
  while (str[r] != '\0' && (str[r - 1] == '-' && str[r - 2] != '-'))
    {
      signe = signe * -1;
      r = r + 1;
    }
  r = r - 1;
  nb = salut(str, nb, r, signe);
  nb = nb * signe;
  return (nb);
}

int	salut(char *str, int nb, int r, int signe)
{
  while (str[r] != '\0')
    {
      if (str[r] <= '9' && str[r] >= '0')
	{
	  nb = nb * 10;
	  nb = nb + (str[r] - 48);
	}
      r = r + 1;
      if (str[r] < '0' || str[r] > '9')
	{
	  nb = nb * signe;
	  return (nb);
	}
    }
  return (0);
}

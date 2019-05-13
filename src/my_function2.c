/*
** my_function2.c for my_function in /home/josselin/EPITECH/42sh/PSU_2016_42sh/src
** 
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
** 
** Started on  Fri May  5 18:09:09 2017 Josselin
** Last update Sun May 21 18:53:07 2017 Josselin
*/

#include <unistd.h>
#include "my.h"

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
  int	modulo;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb >= 0)
    {
      if ( nb > 9)
	{
	  modulo = nb % 10;
	  nb = (nb - modulo) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + modulo);
	}
      else
	{
	  my_putchar(nb + 48);
	}
    }
  return (nb);
}

void	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(2, &str[i], 1);
      i++;
    }
}

void    my_error(char *err, char *context)
{
  write(2, context, my_strlen(context));
  write(2, ": ", 2);
  write(2, err, my_strlen(err));
}

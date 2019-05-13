/*
** my_putchar.c for my_putchar.c in /home/letoux/mes_fichiers
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Wed Oct 12 11:58:23 2016 Nicolas Bontoux
** Last update Thu Oct 27 17:59:16 2016 Nicolas Bontoux
*/

#include <unistd.h>
#include "libmy.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

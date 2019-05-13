/*
** get_prompt.c for get_prompt in /home/josselin/EPITECH/42sh/PSU_2016_42sh
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Thu May  4 16:00:03 2017 Josselin
** Last update Sun May 21 20:34:25 2017 Josselin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char    *get_prompt2()
{
  char  *buf;
  char  *prompt;
  int   i;

  if (((buf = malloc(sizeof(char) * 4096)) == NULL)
      || (buf = getcwd(buf, 4096)) == NULL
      || (prompt = malloc(sizeof(char) * 4096)) == NULL)
    failed_function("malloc");
  i = 0;
  while (buf[i] != 0)
    {
      prompt[i] = buf[i];
      i = i + 1;
    }
  prompt[i] = 0;
  return (prompt);
}

void	get_prompt()
{
  char *prompt;

  prompt = get_prompt2();
  if (prompt != NULL)
    {
      my_putstr(prompt);
      my_putstr("> ");
    }
  else
    my_putstr("> ");
}

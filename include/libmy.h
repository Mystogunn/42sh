/*
** libmy.h for libmy.h in /home/letoux/CPool_infinadd/lib/my
** 
** Made by Nicolas Bontoux
** Login   <letoux@epitech.net>
** 
** Started on  Thu Nov  3 11:00:01 2016 Nicolas Bontoux
** Last Update Wed May 17 09:49:04 2017 Bontoux Nicolas
*/

#ifndef LIBMY_H_
# define LIBMY_H_

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	salut(char *str, int nb, int r, int signe);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_capitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_srtcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
void	my_putchar_error(char c);
void	my_putstr_error(char *str);

#endif /* !LIBMY_H_ */

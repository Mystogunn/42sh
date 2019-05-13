/*
** my.h for my.h in /home/letoux/PSU_2016_42sh
** 
** Made by Bontoux Nicolas
** Login   <letoux@epitech.eu>
** 
** Started on  Fri May 12 14:09:25 2017 Bontoux Nicolas
*/

#ifndef		MY_H_
# define	MY_H_

# define	READ_SIZE (1)
# define	SIZE_MALLOC (4096)

#define		AND_NULL "Invalid null command."

typedef struct	s_vars
{
  int	idx;
  int	idx_line;
  int	k;
  int	value_read;
  char	buf[READ_SIZE + 1];
  char	*line;
}		t_vars;

typedef struct	s_copy_env
{
  char	**copy_env;
  int	i;
  int	pid;
  int	return_value;
}		t_copy_env;

void    free_tab(char **tab);
char	**my_str_to_wordtab(char *str);
char	*get_next_line(const int fd);
int	my_putstr(char *str);
char    *my_strcat2(char *dest, char *src);
char    **push_tab(char **arr, int start, int end);
int     my_getnbr(char *str);
void    failed_function(char *str);
char    *create_tab_pipes(char **arr, int start, int end);
int     init_for_or(char **arr, int i, t_copy_env *var);
int     nbr_of_redirection(char **arr, int i);
char    *space_and_tab(char *str);
char    *my_strcpy(char *dest, char *src);
int     parsing(char *str, char **env, t_copy_env var);
void    my_error(char *err, char *context);
void    my_putstr_error(char *str);
int	my_strncmp(char *s1, char *s2, int n);
char	**path(char **env);
char    *get_prompt2();
int	my_exec(char **arr, char **env);
int	my_cd2(char **arr, char **env);
int     nbr_of_pipes(char **arr, int i);
void	get_prompt();
char	*search(char *str, char **env);
void	my_setenv(char **arr, char **env);
char    *my_strcat(char *dest, char *src);
int     my_strcmp(char *s1, char *s2);
int	home(char **env);
int     my_strlen(char *str);
int     command(char **env, char **arr, int return_value);
char    **init_pars(char *str);
char	**new_env(char **env);
void    detect_signal_child(int pid);
char    **create_map(int l, int cl);
char	**new_env(char **env);
void	print_tab(char **str);
int     execute(char *path, char **opt, char **env);
char    *my_access(char **path, char *elem);
int     access_error(char *cp, char *elem, int c);
char    **setenv_cd(char **arr, char **env);
int	redirection_left(char **tab);
int	init_pipe_redi(char **result, int a);
int	call_access(char **result);
int	init_pipe(char **result);
char	**str_to_tab(char *str, char signe);
int	init_redi(char **result);
int	init_and(char **result);

int	left_redirection(char **tab);

int	init_or(char **result);
int	check_the_way_believe_your_spirit(char **check, char **path);
int	end_double_redirection_right(char **tab, char **path);

#endif /* !MY_H_ */

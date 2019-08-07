/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:21:42 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/07 11:11:06 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define BUFF_SIZE 1024

# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include <dirent.h>

typedef struct		s_subdir
{
	char				*name;
	struct s_subdir		*next;
	struct s_subdir		*prev;
	struct s_subdir		*newlvl;
	struct stat			buf;
	time_t				atime;
	time_t				mtime;
	time_t				ctime;
}					t_subdir;

typedef struct		s_param
{
	char			*name;
	unsigned int	l : 1;
	unsigned int	k : 1;
	unsigned int	br : 1;
	unsigned int	a : 1;
	unsigned int	r : 1;
	unsigned int	t : 1;
	unsigned int	u : 1;
	unsigned int	f : 1;
	unsigned int	d : 1;
	struct s_param	*next;
	t_subdir		*newlvl;
}					t_param;

typedef	struct		s_ls
{
	t_param		*par;
}					t_ls;

t_subdir			*ft_push_back_subdir(t_subdir **head, char *name);
void				ft_fill(t_param **head, char **split);
void				levels_alph_sort(t_subdir **level, int rev);
void				ft_fill_param_list(int ac, char **av, t_ls *ls);
t_param				*ft_create_param(char *str);
t_param				*ft_push_back_param(t_param **head, char *str);
void				ft_fill_list(t_param **head);
t_subdir			*ft_fill_subdir(t_subdir **head, char *name, int can);
t_subdir			*ft_push_back_next_subdir(t_subdir **head, char *name);
t_subdir			*ft_create_next_subdir(char *name, t_subdir *prev);
char				*char_del(char *str, char c);
void				levels_atime_sort(t_subdir **level, int rev);
void				flag_sort(t_param *list);
void				print_level(t_subdir *level);
void				swap_1(t_subdir **head, t_subdir **a, t_subdir **b);
void				do_swap(t_subdir **head, t_subdir **a, t_subdir **b);
int					list_find(t_subdir *head, t_subdir *tmp);
void				levels_time_sort(t_subdir **level, int rev);
char				**flag_split(int ac, char **av);
void				l_flag(char *filename, struct stat file, int hidden, int t);
void				a_flag(char *filename, struct stat file, int k);
void				no_flag(char *filename, struct stat file, int k);
char				*new_strjoin(char **line);
void				no_such_dir(char *filename);
int					vanilla_ls(DIR *dir, int print_hidden, char **filename);
void				flag_return(int ac, char **av, char **split, int *i);
void				ft_firs_free(t_ls **ls);
void				ft_print_subdir(t_subdir *head, t_param *p);
void				*ft_error(t_subdir **head, char *name, int can);
void				b_head_condition(int flag_b, t_subdir **head,
					t_subdir **a, t_subdir **b_prev);
void				a_head_condition(int flag_a, t_subdir **head,
					t_subdir **b, t_subdir **a_prev);
int					a_flag_initil(t_subdir *a_prev,
					t_subdir **head, t_subdir **a);
int					b_flag_initil(t_subdir *b_prev,
					t_subdir **head, t_subdir **b);
t_param				*ft_noflag(t_param *list, char c);
t_param				*ft_nofile(t_param *list);
t_param				*ft_check_flags(t_param *list, int *k, char c);
char				*char_del(char *str, char c);
long int			total(t_subdir *level, int a);
int					is_hidden(const char *str);

#endif

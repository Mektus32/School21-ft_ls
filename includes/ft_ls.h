/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:21:42 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/31 11:23:47 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include <dirent.h>

typedef struct		s_subdir
{
	char				*name;
	char                *print;
	struct s_subdir		*next;
	struct s_subdir		*prev;
	struct s_subdir		*newlvl;
	time_t				atime;
	time_t				mtime;
	time_t				ctime;
}					t_subdir;

typedef struct		s_param
{
	char			*name;
	unsigned int	l : 1;
	unsigned int	R : 1;
	unsigned int	a : 1;
	unsigned int	r : 1;
	unsigned int	t : 1;
	unsigned int	u : 1;
	unsigned int	f : 1;
	unsigned int	g : 1;
	unsigned int	d : 1;
	unsigned int	G : 1;
	struct s_param	*next;
	t_subdir		*newlvl;
}					t_param;

typedef	struct		s_ls
{
	t_param		*par;
}					t_ls;

/*
 ** Функции для работы с основным списком
 */
void                levels_sort(t_subdir **level);
void                level_alph_sort(t_subdir **level);
void				ft_fill_param_list(int ac, char **av, t_ls *ls);
t_param				*ft_create_param(char *str);
t_param				*ft_push_back_param(t_param **head, char *str);
void				ft_fill_list(t_param **head);
t_subdir			*ft_fill_subdir(t_subdir **head, char *name);
t_subdir			*ft_push_back_next_subdir(t_subdir **head, char *name);
t_subdir			*ft_create_next_subdir(char *name, t_subdir *prev);
void				ft_fill(t_param **head, char **split);
t_subdir			*ft_push_back_subdir(t_subdir **head, char *name);

void	no_such_dir(char *filename);
int		vanilla_ls(DIR *dir, int print_hidden, char **filename);
void	flag_return(int ac, char **av, char **split, int *i);
char	**flag_split(int ac, char **av);

#endif

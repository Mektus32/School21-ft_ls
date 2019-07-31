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

# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include <dirent.h>

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
}					t_param;

typedef	struct		s_ls
{
	t_param		*par;
}					t_ls;

t_param				*ft_create_elem(char *str);
t_param				*ft_push_back(t_param **head, char *str);

void    no_such_dir(char *filename);
void    vanilla_ls(char *catalog);
char    *flag_return(int ac, char **av);

#endif

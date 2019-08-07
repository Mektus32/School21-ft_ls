/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:47:41 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/07 12:07:16 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		*ft_error(t_subdir **head, char *name, int can)
{
	char			*spec;

	if (!head)
		return (NULL);
	if ((spec = ft_strrchr(name, '/')))
		spec += 1;
	else
		spec = name;
	if (((spec[0] == '.' && spec[1] == '\0') ||
				(spec[0] == '.' && spec[1] == '.' && spec[2] == '\0')) && can)
		return (NULL);
	return (spec);
}

void		no_flag(char *filename, struct stat file, int k)
{
	if (!filename)
		return ;
	if (filename[0] != '.')
	{
		if (S_ISDIR(file.st_mode))
		{
			ft_putstr("\x1B[34m");
			ft_putstr(filename);
			ft_putstr("\x1b[0m");
		}
		else
			ft_putstr(filename);
		if (k == 0)
			write(1, &"  ", 2);
		else
			write(1, &"\n", 1);
	}
}

void		a_flag(char *filename, struct stat file, int k)
{
	if (!filename)
		return ;
	if (filename[0] == '.' && ft_strlen(filename) > 2)
	{
		ft_putstr("\x1B[32m");
		ft_putstr(filename);
		ft_putstr("\x1b[0m");
	}
	else if (S_ISDIR(file.st_mode))
	{
		ft_putstr("\x1B[34m");
		ft_putstr(filename);
		ft_putstr("\x1b[0m");
	}
	else
		ft_putstr(filename);
	if (k == 0)
		write(1, &"  ", 2);
	else
		write(1, &"\n", 1);
}

t_param		*ft_noflag(t_param *list, char c)
{
	list->name = NULL;
	list->newlvl = NULL;
	list->l = 0;
	list->br = 0;
	list->a = 0;
	list->r = 0;
	list->t = 0;
	list->u = 0;
	list->f = 0;
	list->d = 0;
	list->k = 0;
	ft_printf("ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-lRartufd1] [file ...]\n");
	return (list);
}

t_param		*ft_nofile(t_param *list)
{
	ft_printf("ls: %s: No such file or directory\n", list->name);
	list->name = NULL;
	list->newlvl = NULL;
	list->l = 0;
	list->br = 0;
	list->a = 0;
	list->r = 0;
	list->t = 0;
	list->u = 0;
	list->f = 0;
	list->d = 0;
	list->k = 0;
	return (list);
}

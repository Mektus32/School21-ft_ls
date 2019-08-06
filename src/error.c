/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:47:41 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/06 15:48:22 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*ft_error(t_subdir **head, char *name, int can)
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

void	no_flag(char *filename, struct stat file)
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
		write(1, &"  ", 2);
	}
}

void	a_flag(char *filename, struct stat file)
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
	write(1, &"  ", 2);
}

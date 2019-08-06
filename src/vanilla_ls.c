/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vanilla_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:10:57 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/06 16:11:15 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		vanilla_ls(DIR *dir, int print_hidden, char **filename)
{
	struct dirent	*entry;
	struct stat		file;

	if (!dir)
		return (0);
	entry = readdir(dir);
	if (!entry)
		return (0);
	lstat(entry->d_name, &file);
	if (print_hidden == 0 && (S_ISREG(file.st_mode) || S_ISDIR(file.st_mode))
		&& (entry->d_name[0] != '.'))
	{
		*filename = ft_strdup(entry->d_name);
		return (1);
	}
	else if (print_hidden == 1)
	{
		*filename = ft_strdup(entry->d_name);
		return (1);
	}
	*filename = NULL;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:24:56 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/12 11:54:05 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_param		*ft_create_param(char *str)
{
	t_param		*list;
	int			i;
	struct stat	buf;
	DIR			*dir;

	if (!(list = ft_memalloc(sizeof(t_param))))
		return (0);
	if (!ft_check_flags(list, str, &i))
		return (list = ft_noflag(list, str[i]));
	list = ft_check_flags(list, str, &i);
	list->name = ft_strdup(str + i + 1);
	errno = 0;
	lstat(list->name, &buf);
	list->file = S_ISREG(buf.st_mode) == 1 ? 1 : 0;
	if (!S_ISREG(buf.st_mode) && errno == 20)
		return (list = ft_not_a_directory(list));
	errno = 0;
	dir = opendir(list->name);
	dir ? closedir(dir) : 0;
	if (errno == 13)
		return (list = ft_permission(list));
	if (errno == 2)
		return (list = ft_nofile(list));
	list = ft_fill_param(list, buf);
	return (list);
}

t_param		*ft_push_back_param(t_param **head, char *str)
{
	t_param		*list;

	if (!head)
		return (NULL);
	list = *head;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_param(str);
	}
	else
	{
		list = ft_create_param(str);
		*head = list;
	}
	if (list->next)
		return (list->next);
	return (list);
}

void		ft_fill(t_param **head, char **split)
{
	int		i;
	t_param	*list;

	i = 0;
	while (split[i])
	{
		list = ft_push_back_param(head, split[i]);
		if (list->br == 1)
			ft_fill_subdir(&list->newlvl, list->name, 0);
		else
			ft_push_back_subdir(&list->newlvl, list->name);
		free(split[i]);
		i++;
	}
	free(split);
}

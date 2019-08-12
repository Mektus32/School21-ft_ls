/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:47:32 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/12 11:48:18 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_subdir	*ft_create_next_subdir(char *name, t_subdir *prev)
{
	t_subdir	*new;
	DIR			*dir;

	if (!(new = (t_subdir*)malloc(sizeof(t_subdir))))
		return (NULL);
	new->next = NULL;
	new->newlvl = NULL;
	new->prev = prev;
	new->name = name;
	errno = 0;
	lstat(name, &new->buf);
	errno = 0;
	dir = opendir(name);
	new->var_errno = errno == 13 ? 13 : 0;
	new->atime = new->buf.st_atime;
	new->mtime = new->buf.st_mtime;
	new->ctime = new->buf.st_ctime;
	dir ? closedir(dir) : 0;
	return (new);
}

t_subdir	*ft_push_back_next_subdir(t_subdir **head, char *name)
{
	t_subdir	*list;
	t_subdir	*tmp;

	if (!head)
		return (NULL);
	list = *head;
	if (list)
	{
		tmp = list;
		while (list->next)
		{
			tmp = list;
			list = list->next;
		}
		list->next = ft_create_next_subdir(name, tmp);
	}
	else
		return (*head = ft_create_next_subdir(name, NULL));
	return (list);
}

t_subdir	*ft_fill_subdir(t_subdir **head, char *name, int can)
{
	t_subdir		*list;
	DIR				*dir;
	struct dirent	*file;

	if (!ft_error(head, name, can))
		return (NULL);
	list = *head;
	if (!(dir = opendir(name)))
		return (NULL);
	while ((file = readdir(dir)))
	{
		if (!list)
			*head = ft_push_back_next_subdir(&list,
					ft_free_join(ft_strjoin(name, "/"), file->d_name));
		else
			ft_push_back_next_subdir(&list,
					ft_free_join(ft_strjoin(name, "/"), file->d_name));
	}
	closedir(dir);
	while (list)
	{
		ft_fill_subdir(&list->newlvl, list->name, 1);
		list = list->next;
	}
	return (list);
}

void		ft_fill_list(t_param **head)
{
	t_param		*list;

	if (!head || !*head)
		return ;
	list = *head;
	while (list)
	{
		ft_fill_subdir(&(list->newlvl), list->name, 1);
		list = list->next;
	}
}

t_subdir	*ft_push_back_subdir(t_subdir **head, char *name)
{
	t_subdir		*list;
	DIR				*dir;
	struct dirent	*file;

	if (!head)
		return (NULL);
	list = *head;
	if (!(dir = opendir(name)))
		return (NULL);
	while ((file = readdir(dir)))
	{
		if (!list)
			*head = ft_push_back_next_subdir(&list,
					ft_free_join(ft_strjoin(name, "/"), file->d_name));
		else
			ft_push_back_next_subdir(&list,
					ft_free_join(ft_strjoin(name, "/"), file->d_name));
	}
	closedir(dir);
	return (list);
}

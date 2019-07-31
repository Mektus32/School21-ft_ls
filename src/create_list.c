/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:47:32 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/31 18:47:33 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fill_param_list(int ac, char **av, t_ls *ls)
{

}

t_subdir	*ft_create_subdir(char *name, t_subdir *prev)
{
	t_subdir	*list;

	if (!(list = (t_subdir*)malloc(sizeof(t_subdir))))
		return (NULL);
	list->name = name;
	list->next = NULL;
	list->prev = prev;
	list->newlvl = NULL;
	return (list);
}

void		ft_push_back_subdir(t_subdir **head, char *name)
{
	t_subdir	*list;
	t_subdir	*tmp;

	if (!*head)
		return ;
	list = *head;
	if (list)
	{
		tmp = list;
		while (list->next)
			list = list->next;
		list->next = ft_create_subdir(name, tmp);
	}
	else
		list = ft_create_subdir(name, NULL);
}

t_subdir	*ft_push_newlvl(t_subdir **head, char *name, char *path)
{
	t_subdir	*list;
	int 		i;

	i = 0;
	while (path[i] != '/' && path[i] != '\0')
		i++;
	if (path[i] == '\0')
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:24:56 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/31 12:24:57 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_param		*ft_create_param(char *str)
{
	t_param		*list;
	int			i;

	if (!(list = ft_memalloc(sizeof(t_param))))
		return (0);
	i = 0;
	while (str[i] != '_' && str[i] != '\0')
	{
		str[i] == 'l' ? list->l = (unsigned int)1 : 0;
		str[i] == 'R' ? list->R = (unsigned int)1 : 0;
		str[i] == 'a' ? list->a = (unsigned int)1 : 0;
		str[i] == 'r' ? list->r = (unsigned int)1 : 0;
		str[i] == 't' ? list->t = (unsigned int)1 : 0;
		str[i] == 'u' ? list->u = (unsigned int)1 : 0;
		str[i] == 'f' ? list->f = (unsigned int)1 : 0;
		str[i] == 'g' ? list->g = (unsigned int)1 : 0;
		str[i] == 'd' ? list->d = (unsigned int)1 : 0;
		str[i] == 'G' ? list->G = (unsigned int)1 : 0;
		i++;
	}
	list->name = ft_strdup(str + i + 1);
	list->newlvl = NULL;
	//free(str);
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

void	ft_fill(t_param **head, char **split)
{
	int		i;
	t_param	*list;

	i = 0;
	while (split[i])
	{
		list = ft_push_back_param(head, split[i]);
		if (list->R == 1)
		{
			if (list->name[0] == '.' && list->name[1] == '\0')
				ft_fill_subdir(&list->newlvl, list->name, 0);
			else
				ft_fill_subdir(&list->newlvl, list->name, 1);
		}
		else
			ft_push_back_subdir(&list->newlvl, list->name);
		i++;
	}
}
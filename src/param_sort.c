/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 10:54:09 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/12 10:55:25 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		rev_sorted_alph_param(t_param *level)
{
	t_param	*tmp;
	t_param	*cur;

	if (level->next)
		tmp = level->next;
	else
		return (1);
	cur = level;
	while (tmp)
	{
		if (ft_stricmp(tmp->name, cur->name) > 0)
			return (0);
		cur = cur->next;
		tmp = tmp->next;
	}
	return (1);
}

int		sorted_alph_param(t_param *level)
{
	t_param *tmp;
	t_param *cur;

	if (level->next)
		tmp = level->next;
	else
		return (1);
	cur = level;
	while (tmp)
	{
		if (tmp->name && cur->name && ft_stricmp(tmp->name, cur->name) < 0)
			return (0);
		cur = cur->next;
		tmp = tmp->next;
	}
	return (1);
}

void	rev_param_sort(t_param **level)
{
	t_param		*tmp;
	t_param		*cur;
	int			cmp;

	tmp = *level;
	while (!rev_sorted_alph_param(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = ft_stricmp((tmp->name), (cur->name));
			if (cmp > 0 && p_list_find(*level, tmp) > p_list_find(*level, cur))
				p_do_swap(level, &tmp, &cur);
			else if (cmp < 0 && p_list_find(*level, tmp) <
					p_list_find(*level, cur))
				p_do_swap(level, &tmp, &cur);
			cur = cur->next;
		}
		if (tmp->next == NULL)
			tmp = (*level);
		else
			tmp = tmp->next;
	}
}

void	param_sort(t_param **level)
{
	t_param		*tmp;
	t_param		*cur;
	int			cmp;

	tmp = *level;
	while (!sorted_alph_param(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = ft_stricmp((tmp->name), (cur->name));
			if (cmp > 0 && p_list_find(*level, tmp) < p_list_find(*level, cur))
				p_do_swap(level, &tmp, &cur);
			else if (cmp < 0 && p_list_find(*level, tmp) >
					p_list_find(*level, cur))
				p_do_swap(level, &tmp, &cur);
			cur = cur->next;
		}
		if (tmp->next == NULL)
			tmp = (*level);
		else
			tmp = tmp->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alph_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:35:26 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/06 15:37:39 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		rev_sorted_alph_level(t_subdir *level)
{
	t_subdir	*tmp;
	t_subdir	*cur;

	tmp = level->next;
	cur = level;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, cur->name) > 0)
			return (0);
		cur = cur->next;
		tmp = tmp->next;
	}
	return (1);
}

int		sorted_alph_level(t_subdir *level)
{
	t_subdir *tmp;
	t_subdir *cur;

	tmp = level->next;
	cur = level;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, cur->name) < 0)
			return (0);
		cur = cur->next;
		tmp = tmp->next;
	}
	return (1);
}

void	rev_level_alph_sort(t_subdir **level)
{
	t_subdir	*tmp;
	t_subdir	*cur;
	int			cmp;

	tmp = *level;
	while (!rev_sorted_alph_level(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = ft_strcmp((tmp->name), (cur->name));
			if (cmp > 0 && list_find(*level, tmp) > list_find(*level, cur))
				do_swap(level, &tmp, &cur);
			else if (cmp < 0 && list_find(*level, tmp) < list_find(*level, cur))
				do_swap(level, &tmp, &cur);
			cur = cur->next;
		}
		if (tmp->next == NULL)
			tmp = (*level);
		else
			tmp = tmp->next;
	}
}

void	level_alph_sort(t_subdir **level)
{
	t_subdir	*tmp;
	t_subdir	*cur;
	int			cmp;

	tmp = *level;
	while (!sorted_alph_level(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = ft_strcmp((tmp->name), (cur->name));
			if (cmp > 0 && list_find(*level, tmp) < list_find(*level, cur))
				do_swap(level, &tmp, &cur);
			else if (cmp < 0 && list_find(*level, tmp) > list_find(*level, cur))
				do_swap(level, &tmp, &cur);
			cur = cur->next;
		}
		if (tmp->next == NULL)
			tmp = (*level);
		else
			tmp = tmp->next;
	}
}

void	levels_alph_sort(t_subdir **level, int rev)
{
	t_subdir *nlvl;

	nlvl = *level;
	if (rev == 0)
		level_alph_sort(&nlvl);
	else
		rev_level_alph_sort(&nlvl);
	(*level) = nlvl;
	while (nlvl)
	{
		if (nlvl->newlvl)
			levels_alph_sort(&(nlvl->newlvl), rev);
		nlvl = nlvl->next;
	}
}

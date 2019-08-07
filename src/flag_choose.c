/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_choose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:48:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/07 12:07:35 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		flag_sort(t_param *list)
{
	while (list)
	{
		while (list && !list->newlvl)
			list = list->next;
		if (!list)
			return ;
		if (list->u == 1 && list->r == 1 &&
		list->f == 0)
			levels_atime_sort(&list->newlvl, 1);
		else if (list->u == 1 &&
				list->r == 0 && list->f == 0)
			levels_atime_sort(&list->newlvl, 0);
		else if (list->t == 1 && list->r == 1 &&
		list->u == 0 && list->f == 0)
			levels_time_sort(&list->newlvl, 1);
		else if (list->t == 1 &&
		list->r == 0 && list->u == 0 && list->f == 0)
			levels_time_sort(&list->newlvl, 0);
		else if (list->r == 1 &&
		list->t == 0 && list->u == 0 && list->f == 0)
			levels_alph_sort(&list->newlvl, 1);
		else if (list->f == 0)
			levels_alph_sort(&list->newlvl, 0);
		list = list->next;
	}
}

t_param		*ft_check_flags(t_param *list, int *k, char c)
{
	c == 'l' ? list->l = (unsigned int)1 : (*k)++;
	c == 'R' ? list->br = (unsigned int)1 : (*k)++;
	c == 'a' ? list->a = (unsigned int)1 : (*k)++;
	c == 'r' ? list->r = (unsigned int)1 : (*k)++;
	c == 't' ? list->t = (unsigned int)1 : (*k)++;
	c == 'u' ? list->u = (unsigned int)1 : (*k)++;
	c == 'f' ? list->f = (unsigned int)1 : (*k)++;
	c == 'd' ? list->d = (unsigned int)1 : (*k)++;
	c == '1' ? list->k = (unsigned int)1 : (*k)++;
	return (list);
}

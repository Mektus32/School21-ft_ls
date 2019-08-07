/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_choose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:48:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/06 15:49:22 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_sort(t_param *list)
{
	while (list)
	{
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

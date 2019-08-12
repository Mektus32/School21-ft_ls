/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_flag_choose.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:05:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/12 11:06:45 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		param_flag_sort(t_param **list)
{
	if (!(*list))
		return ;
	if ((*list)->u == 1 && (*list)->r == 1 &&
			(*list)->f == 0)
		rev_param_atime_sort(&(*list));
	else if ((*list)->u == 1 &&
			(*list)->r == 0 && (*list)->f == 0)
		param_atime_sort(&(*list));
	else if ((*list)->t == 1 && (*list)->r == 1 &&
			(*list)->u == 0 && (*list)->f == 0)
		rev_param_time_sort(&(*list));
	else if ((*list)->t == 1 &&
			(*list)->r == 0 && (*list)->u == 0 && (*list)->f == 0)
		param_time_sort(&(*list));
	else if ((*list)->r == 1 &&
			(*list)->t == 0 && (*list)->u == 0 && (*list)->f == 0)
		rev_param_sort(&(*list));
	else if ((*list)->f == 0)
		param_sort(list);
}

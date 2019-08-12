/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_sort_list2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:06:54 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/12 11:07:18 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	pa_head_condition(int flag_a, t_param **head,
		t_param **b, t_param **a_prev)
{
	if (flag_a == 0)
		(*a_prev)->next = (*b);
	else
		(*head) = (*b);
}

void	pb_head_condition(int flag_b, t_param **head,
		t_param **a, t_param **b_prev)
{
	if (flag_b == 0)
		(*b_prev)->next = (*a);
	else
		(*head) = (*a);
}

int		pa_flag_initil(t_param *a_prev, t_param **head, t_param **a)
{
	int		flag_a;

	flag_a = 0;
	if (a_prev && a_prev == *head && a_prev->next != (*a))
		flag_a = 1;
	return (flag_a);
}

int		pb_flag_initil(t_param *b_prev, t_param **head, t_param **b)
{
	int		flag_b;

	flag_b = 0;
	if (b_prev && b_prev == *head && b_prev->next != (*b))
		flag_b = 1;
	return (flag_b);
}

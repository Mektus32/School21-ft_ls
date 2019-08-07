/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:04:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/07 11:11:41 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	a_head_condition(int flag_a, t_subdir **head,
		t_subdir **b, t_subdir **a_prev)
{
	if (flag_a == 0)
		(*a_prev)->next = (*b);
	else
		(*head) = (*b);
}

void	b_head_condition(int flag_b, t_subdir **head,
		t_subdir **a, t_subdir **b_prev)
{
	if (flag_b == 0)
		(*b_prev)->next = (*a);
	else
		(*head) = (*a);
}

int		a_flag_initil(t_subdir *a_prev, t_subdir **head, t_subdir **a)
{
	int		flag_a;

	flag_a = 0;
	if (a_prev && a_prev == *head && a_prev->next != (*a))
		flag_a = 1;
	return (flag_a);
}

int		b_flag_initil(t_subdir *b_prev, t_subdir **head, t_subdir **b)
{
	int		flag_b;

	flag_b = 0;
	if (b_prev && b_prev == *head && b_prev->next != (*b))
		flag_b = 1;
	return (flag_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:03:12 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/06 16:04:17 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		cmp(const char *str1, const char *str2)
{
	int		i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if ((unsigned char)str1[i] != (unsigned char)str2[i])
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}

void	swap_1(t_subdir **head, t_subdir **a, t_subdir **b)
{
	t_subdir	*first;
	t_subdir	*second;
	t_subdir	*third;
	t_subdir	*a_prev;
	int			flag;

	a_prev = *head;
	flag = 0;
	while (a_prev != (*a) && a_prev && a_prev->next != (*a))
		a_prev = a_prev->next;
	if (a_prev && a_prev == *head && a_prev->next != (*a))
		flag = 1;
	first = (*a);
	second = (*a)->next;
	third = (*a)->next->next;
	first->next = third;
	second->next = (*a);
	if (flag == 1)
		(*head) = (*b);
	else
		a_prev->next = (*b);
}

void    prev_initil(t_subdir **a, t_subdir **b, t_subdir **a_prev, t_subdir **b_prev)
{
	t_subdir *tmp_a;
	t_subdir *tmp_b;

	tmp_a = *a_prev;
	tmp_b = *b_prev;
	while (tmp_a != (*a) && tmp_a && tmp_a->next != (*a))
		tmp_a = tmp_a->next;
	while (tmp_b != (*b) && tmp_b && tmp_b->next != (*b))
		tmp_b = tmp_b->next;
	*a_prev = tmp_a;
	*b_prev = tmp_b;
}

int     a_flag_initil(t_subdir *a_prev, t_subdir **head, t_subdir **a)
{
	int flag_a;

	flag_a = 0;
	if (a_prev && a_prev == *head && a_prev->next != (*a))
		flag_a = 1;
	return (flag_a);
}

int     b_flag_initil(t_subdir *b_prev, t_subdir **head, t_subdir **b)
{
	int flag_b;

	flag_b = 0;
	if (b_prev && b_prev == *head && b_prev->next != (*b))
		flag_b = 1;
	return (flag_b);
}

void    a_head_condition(int flag_a, t_subdir **head, t_subdir **b, t_subdir **a_prev)
{
	if (flag_a == 0)
		(*a_prev)->next = (*b);
	else
		(*head) = (*b);
}

void    do_swap(t_subdir **head, t_subdir **a, t_subdir **b)
{
	t_subdir *a_prev;
	t_subdir *b_prev;
	t_subdir *a_next;
	int      flag_a;
	int      flag_b;

	if ((*a)->next == (*b))
		swap_1(head, a, b);
	else if ((*b)->next == (*a))
		swap_1(head, b, a);
	else
	{
		a_prev = *head;
		b_prev = *head;
		prev_initil(a, b, &a_prev, &b_prev);
		flag_a = a_flag_initil(a_prev, head, a);
		flag_b = b_flag_initil(b_prev, head, b);
		a_next = (*a)->next;
		(*a)->next = (*b)->next;
		(*b)->next = a_next;
		a_head_condition(flag_a, head, b, &a_prev);
		if (flag_b == 0)
			b_prev->next = (*a);
		else
			(*head) = (*a);
	}
}

int		list_find(t_subdir *head, t_subdir *tmp)
{
	int		len;

	len = 0;
	while (head && cmp(head->name, tmp->name))
	{
		len++;
		head = head->next;
	}
	return (len);
}

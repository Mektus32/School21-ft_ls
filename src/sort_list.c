/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:03:12 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/07 10:59:58 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_stricmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (ft_toupper((unsigned char)str1[i]) != ft_toupper((unsigned char)str2[i]))
			return (ft_toupper((unsigned char)str1[i]) - ft_toupper((unsigned char)str2[i]));
		i++;
	}
	if (ft_toupper((unsigned char)str1[i]) != ft_toupper((unsigned char)str2[i]))
		return (ft_toupper((unsigned char)str1[i]) - ft_toupper((unsigned char)str2[i]));
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

void	prev_initil(t_subdir **a, t_subdir **b,
		t_subdir **a_prev, t_subdir **b_prev)
{
	t_subdir	*tmp_a;
	t_subdir	*tmp_b;

	tmp_a = *a_prev;
	tmp_b = *b_prev;
	while (tmp_a != (*a) && tmp_a && tmp_a->next != (*a))
		tmp_a = tmp_a->next;
	while (tmp_b != (*b) && tmp_b && tmp_b->next != (*b))
		tmp_b = tmp_b->next;
	*a_prev = tmp_a;
	*b_prev = tmp_b;
}

void	do_swap(t_subdir **head, t_subdir **a, t_subdir **b)
{
	t_subdir	*a_prev;
	t_subdir	*b_prev;
	t_subdir	*a_next;
	int			flag_a;
	int			flag_b;

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
		b_head_condition(flag_b, head, a, &b_prev);
	}
}

int		list_find(t_subdir *head, t_subdir *tmp)
{
	int		len;

	len = 0;
	while (head && ft_strcmp(head->name, tmp->name))
	{
		len++;
		head = head->next;
	}
	return (len);
}

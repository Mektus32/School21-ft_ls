#include "ft_ls.h"

void	p_swap_1(t_param **head, t_param **a, t_param **b)
{
	t_param	*first;
	t_param	*second;
	t_param	*third;
	t_param	*a_prev;
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
	else if (a_prev && a_prev->next)
		a_prev->next = (*b);
}

void	p_prev_initil(t_param **a, t_param **b,
                    t_param **a_prev, t_param **b_prev)
{
	t_param	*tmp_a;
	t_param	*tmp_b;

	tmp_a = *a_prev;
	tmp_b = *b_prev;
	while (tmp_a != (*a) && tmp_a && tmp_a->next != (*a))
		tmp_a = tmp_a->next;
	while (tmp_b != (*b) && tmp_b && tmp_b->next != (*b))
		tmp_b = tmp_b->next;
	*a_prev = tmp_a;
	*b_prev = tmp_b;
}

void	p_do_swap(t_param **head, t_param **a, t_param **b)
{
	t_param	*a_prev;
	t_param	*b_prev;
	t_param	*a_next;
	int			flag_a;
	int			flag_b;

	if ((*a)->next == (*b))
		p_swap_1(head, a, b);
	else if ((*b)->next == (*a))
		p_swap_1(head, b, a);
	else
	{
		a_prev = *head;
		b_prev = *head;
		p_prev_initil(a, b, &a_prev, &b_prev);
		flag_a = pa_flag_initil(a_prev, head, a);
		flag_b = pb_flag_initil(b_prev, head, b);
		a_next = (*a)->next;
		(*a)->next = (*b)->next;
		(*b)->next = a_next;
		pa_head_condition(flag_a, head, b, &a_prev);
		pb_head_condition(flag_b, head, a, &b_prev);
	}
}

int		p_list_find(t_param *head, t_param *tmp)
{
	int		len;

	len = 0;
	while (head && head != tmp)
	{
		len++;
		head = head->next;
	}
	return (len);
}

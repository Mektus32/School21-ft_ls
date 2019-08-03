#include "ft_ls.h"

int		cmp(const char *str1, const char *str2)
{
	int	i;

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

void    print_level(t_subdir *level)
{
	t_subdir *tmp;

	tmp = NULL;
	printf("-----------------\n");
	while (level)
	{
		printf("%s---->%ld\n", level->name, level->mtime);
		tmp = level;
		level = level->next;
	}
	printf("-----------------\n");
}

void    swap_1(t_subdir **head, t_subdir **a, t_subdir **b)
{
	t_subdir *first;
	t_subdir *second;
	t_subdir *third;
	t_subdir *a_prev;
	int     flag;

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

void    do_swap(t_subdir **head, t_subdir **a, t_subdir **b)
{
	t_subdir *a_prev;
	t_subdir *b_prev;
	t_subdir *a_next;
	t_subdir *b_next;
	int      flag_a;
	int      flag_b;

	if ((*a)->next == (*b))
		swap_1(head, a, b);
	else if ((*b)->next == (*a))
		swap_1(head, b, a);
	else
	{
		flag_a = 0;
		flag_b = 0;
		a_prev = *head;
		b_prev = *head;
		while (a_prev != (*a) && a_prev && a_prev->next != (*a))
			a_prev = a_prev->next;
		while (b_prev != (*b) && b_prev && b_prev->next != (*b))
			b_prev = b_prev->next;
		if (a_prev && a_prev == *head && a_prev->next != (*a))
			flag_a = 1;
		if (b_prev && b_prev == *head && b_prev->next != (*b))
			flag_b = 1;
		a_next = (*a)->next;
		b_next = (*b)->next;
		(*a)->next = b_next;
		(*b)->next = a_next;
		if (flag_a == 0)
			a_prev->next = (*b);
		else
			(*head) = (*b);
		if (flag_b == 0)
			b_prev->next = (*a);
		else
			(*head) = (*a);
	}
}

int     list_find(t_subdir *head, t_subdir *tmp)
{
	int len;

	len = 0;
	while (head && cmp(head->name, tmp->name))
	{
		len++;
		head = head->next;
	}
	return (len);
}
#include "ft_ls.h"

void    print_level(t_subdir *level)
{
	t_subdir *tmp;

	tmp = NULL;
	printf("-----------------\n");
	while (level)
	{
		printf("%s\n", level->name);
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
	//printf("a_prev = %s\na_prev_next = %s\n", a_prev->name, a_prev->next->name);
	//printf("%d\n", flag);
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
	int      i;
	int      j;

	if ((*a)->next == (*b))
		swap_1(head, a, b);
	else if ((*b)->next == (*a))
		swap_1(head, b, a);
	else
	{
		printf("here\n");
		a_prev = *head;
		b_prev = *head;
		i = 0;
		j = 0;
		while (a_prev != (*a) && a_prev && a_prev->next != (*a))
		{
			i = 1;
			a_prev = a_prev->next;
		}
		while (b_prev != (*b) && b_prev && b_prev->next != (*b))
		{
			j = 1;
			b_prev = b_prev->next;
		}
		if (a_prev)
			printf("a_prev = %s\n", a_prev->name);
		if (b_prev)
			printf("b_prev = %s\n", b_prev->name);
		printf("ok\n");
		a_next = (*a)->next;
		b_next = (*b)->next;
		(*a)->next = b_next;
		(*b)->next = a_next;
		if (a_prev && a_prev != *head)
			a_prev->next = (*b);
		else
			(*head) = (*b);
		if (b_prev && b_prev != *head)
			b_prev->next = (*a);
		else
			(*head) = (*a);
		//printf("%s\n%s\n%s\n", (*head)->name, (*head)->next->name, (*head)->next->next->name);
		//exit(0);
	}
}

int     sorted_level(t_subdir *level)
{
	t_subdir *tmp;
	t_subdir *cur;

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

void    alph_sort(t_subdir **level)
{
	t_subdir *head;
	t_subdir *tmp;
	t_subdir *cur;
	t_subdir *cp;

	tmp = *level;
	head = *level;
	print_level(*level);
	while (tmp)
	{
		cur = head;
		printf("tmp = %s\n", tmp->name);
		while (cur)
		{
			//print_level(*level);
			if (ft_strcmp((tmp->name), (cur->name)) > 0)
			{
				//printf("a = %s\nb = %s\n", tmp->name, cur->name);
				do_swap(level, &tmp, &cur);
			}
			printf("cur = %s\n", cur->name);
			cur = cur->next;
		}
		tmp = tmp->next;
	}
	print_level(*level);
}
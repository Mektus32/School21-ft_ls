#include "ft_ls.h"

int     rev_sorted_atime_level(t_subdir *level)
{
	t_subdir *tmp;
	t_subdir *cur;

	tmp = level->next;
	cur = level;
	while (tmp)
	{
		if ((tmp->atime - cur->atime) < 0)
			return (0);
		cur = cur->next;
		tmp = tmp->next;
	}
	return (1);
}

int     sorted_atime_level(t_subdir *level)
{
	t_subdir *tmp;
	t_subdir *cur;

	tmp = level->next;
	cur = level;
	while (tmp)
	{
		if ((tmp->atime - cur->atime) > 0)
			return (0);
		cur = cur->next;
		tmp = tmp->next;
	}
	return (1);
}

void    rev_level_atime_sort(t_subdir **level)
{
	t_subdir    *tmp;
	t_subdir    *cur;
	long        cmp;

	tmp = *level;
	while (!rev_sorted_atime_level(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = tmp->atime - cur->atime;
			if (cmp > 0 && list_find(*level, tmp) < list_find(*level, cur))
				do_swap(level, &tmp, &cur);
			else if (cmp < 0 && list_find(*level, tmp) > list_find(*level, cur))
				do_swap(level, &tmp, &cur);
			cur = cur->next;
		}
		if (tmp->next == NULL)
			tmp = (*level);
		else
			tmp = tmp->next;
	}
}

void    level_atime_sort(t_subdir **level)
{
	t_subdir    *tmp;
	t_subdir    *cur;
	long        cmp;

	tmp = *level;
	while (!sorted_atime_level(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = tmp->atime - cur->atime;
			if (cmp > 0 && list_find(*level, tmp) > list_find(*level, cur))
				do_swap(level, &tmp, &cur);
			else if (cmp < 0 && list_find(*level, tmp) < list_find(*level, cur))
				do_swap(level, &tmp, &cur);
			cur = cur->next;
		}
		if (tmp->next == NULL)
			tmp = (*level);
		else
			tmp = tmp->next;
	}
}

void levels_atime_sort(t_subdir **level, int rev)
{
	t_subdir *nlvl;

	nlvl = *level;
	if (rev == 0)
		level_atime_sort(&nlvl);
	else
		rev_level_atime_sort(&nlvl);
	(*level) = nlvl;
	while (nlvl)
	{
		if (nlvl->newlvl)
			levels_time_sort(&(nlvl->newlvl), rev);
		nlvl = nlvl->next;
	}
}
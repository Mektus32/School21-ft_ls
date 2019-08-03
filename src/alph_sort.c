#include "ft_ls.h"

int     sorted_alph_level(t_subdir *level)
{
	t_subdir *tmp;
	t_subdir *cur;

	tmp = level->next;
	cur = level;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, cur->name) < 0)
			return (0);
		cur = cur->next;
		tmp = tmp->next;
	}
	return (1);
}

void    level_alph_sort(t_subdir **level)
{
	t_subdir    *tmp;
	t_subdir    *cur;
	int         cmp;

	tmp = *level;
	while (!sorted_alph_level(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = ft_strcmp((tmp->name), (cur->name));
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

void    levels_alph_sort(t_subdir **level)
{
	t_subdir *nlvl;

	nlvl = *level;
	level_alph_sort(&nlvl);
	(*level) = nlvl;
	while (nlvl)
	{
		if (nlvl->newlvl)
			levels_alph_sort(&(nlvl->newlvl));
		nlvl = nlvl->next;
	}
}
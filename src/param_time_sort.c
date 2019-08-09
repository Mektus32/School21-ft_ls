#include "ft_ls.h"

int		rev_sorted_time_param(t_param *level)
{
	t_param	*tmp;
	t_param	*cur;

	if (level->next)
		tmp = level->next;
	else
		return (1);
	cur = level;
	while (tmp)
	{
		if ((tmp->buf.st_mtime - cur->buf.st_mtime) < 0)
			return (0);
		cur = cur->next;
		tmp = tmp->next;
	}
	return (1);
}

int		sorted_time_param(t_param *level)
{
	t_param	*tmp;
	t_param	*cur;

	if (level->next)
		tmp = level->next;
	else
		return (1);
	cur = level;
	while (tmp)
	{
		if ((tmp->buf.st_mtime - cur->buf.st_mtime) > 0)
			return (0);
		cur = cur->next;
		tmp = tmp->next;
	}
	return (1);
}

void	rev_param_time_sort(t_param **level)
{
	t_param	*tmp;
	t_param	*cur;
	long		cmp;

	tmp = *level;
	while (!rev_sorted_time_param(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = tmp->buf.st_mtime - cur->buf.st_mtime;
			if (cmp > 0 && p_list_find(*level, tmp) < p_list_find(*level, cur))
				p_do_swap(level, &tmp, &cur);
			else if (cmp < 0 && p_list_find(*level, tmp) > p_list_find(*level, cur))
				p_do_swap(level, &tmp, &cur);
			cur = cur->next;
		}
		if (tmp->next == NULL)
			tmp = (*level);
		else
			tmp = tmp->next;
	}
}

void	param_time_sort(t_param **level)
{
	t_param	*tmp;
	t_param	*cur;
	long		cmp;

	tmp = *level;
	while (!sorted_time_param(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = tmp->buf.st_mtime - cur->buf.st_mtime;
			if (cmp > 0 && p_list_find(*level, tmp) > p_list_find(*level, cur))
				p_do_swap(level, &tmp, &cur);
			else if (cmp < 0 && p_list_find(*level, tmp) < p_list_find(*level, cur))
				p_do_swap(level, &tmp, &cur);
			cur = cur->next;
		}
		if (tmp->next == NULL)
			tmp = (*level);
		else
			tmp = tmp->next;
	}
}

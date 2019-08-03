#include "ft_ls.h"

int     rev_sorted_time_level(t_subdir *level)
{
	t_subdir *tmp;
	t_subdir *cur;

	tmp = level->next;
	cur = level;
	while (tmp)
	{
		if ((tmp->mtime - cur->mtime) < 0)
			return (0);
		cur = cur->next;
		tmp = tmp->next;
	}
	return (1);
}

int     sorted_time_level(t_subdir *level)
{
	t_subdir *tmp;
	t_subdir *cur;

	tmp = level->next;
	cur = level;
	//printf("dafuq\n");
	//printf("%s\n", tmp->name);
	//printf("%s\n", cur->name);
	while (tmp)
	{
		if ((tmp->mtime - cur->mtime) > 0)
		{
			//printf("%ld\n%ld\n", tmp->mtime, cur->mtime);
			//printf("%s\n%s\n", tmp->name, cur->name);
			return (0);
		}
		//printf("dafuq\n%ld\n%ld\n", tmp->mtime, cur->mtime);
		cur = cur->next;
		tmp = tmp->next;
	}
	//printf("return 1\n");
	return (1);
}

void    rev_level_time_sort(t_subdir **level)
{
	t_subdir    *tmp;
	t_subdir    *cur;
	long        cmp;

	tmp = *level;
	while (!rev_sorted_time_level(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = tmp->mtime - cur->mtime;
			/*printf("cmp = %ld\n", cmp);
			printf("tmp = %s\ncur = %s\n", tmp->name, cur->name);
			printf("tmp = %lu\ncur = %lu\n", tmp->mtime, cur->mtime);
			printf("tmp_len = %d\ncur_len = %d\n", list_find(*level, tmp), list_find(*level, cur));*/
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

void    level_time_sort(t_subdir **level)
{
	t_subdir    *tmp;
	t_subdir    *cur;
	long        cmp;

	tmp = *level;
	while (!sorted_time_level(*level))
	{
		cur = (*level);
		while (cur)
		{
			cmp = tmp->mtime - cur->mtime;
			/*print_level(*level);
			printf("cmp = %ld\n", cmp);
			printf("tmp = %s\ncur = %s\n", tmp->name, cur->name);
			printf("tmp = %lu\ncur = %lu\n", tmp->mtime, cur->mtime);
			printf("tmp_len = %d\ncur_len = %d\n", list_find(*level, tmp), list_find(*level, cur));*/
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

void levels_time_sort(t_subdir **level, int rev)
{
	t_subdir *nlvl;

	nlvl = *level;
	if (rev == 0)
		level_time_sort(&nlvl);
	else
		rev_level_time_sort(&nlvl);
	(*level) = nlvl;
	while (nlvl)
	{
		if (nlvl->newlvl)
			levels_time_sort(&(nlvl->newlvl), rev);
		nlvl = nlvl->next;
	}
}
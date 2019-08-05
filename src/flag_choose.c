#include "ft_ls.h"

void    flag_sort(t_param *list)
{
	while (list)
	{
		if (list->t == 1 && list->r == 1 &&
		list->u == 0 && list->f == 0)
		{
			levels_alph_sort(&list->newlvl, 1);
			levels_time_sort(&list->newlvl, 1);
		}
		else if (list->t == 1 &&
		list->r == 0 && list->u == 0 && list->f == 0)
		{
			levels_alph_sort(&list->newlvl, 0);
			levels_time_sort(&list->newlvl, 0);
		}
		else if (list->r == 1 &&
		list->t == 0 && list->u == 0 && list->f == 0)
			levels_alph_sort(&list->newlvl, 1);
		else if (list->f == 0)
			levels_alph_sort(&list->newlvl, 0);
		list = list->next;
	}
}
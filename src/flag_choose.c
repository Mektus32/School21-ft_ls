#include "ft_ls.h"

void    flag_choose(t_param *list)
{
	if (list->g == 0 && list->a == 0 &&
			list->l == 0 && list->d == 0 &&
			list->f == 0 && list->R == 0 &&
			list->r == 0 && list->t == 0 &&
			list->u == 0 && list->G == 0)
		vanilla_ls(list->name);
}
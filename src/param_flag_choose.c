#include "ft_ls.h"

void		param_flag_sort(t_param **list)
{
	if (!(*list))
		return ;
		/*if ((list)->u == 1 && (list)->r == 1 &&
		    (list)->f == 0)
			rev_param_atime_sort(&(list));
		else if ((list)->u == 1 &&
		         (list)->r == 0 && (list)->f == 0)
			param_atime_sort(&(list));
		else if ((list)->t == 1 && (list)->r == 1 &&
		         (list)->u == 0 && (list)->f == 0)
			rev_param_time_sort(&(list));
		else if ((list)->t == 1 &&
		         (list)->r == 0 && (list)->u == 0 && (list)->f == 0)
			param_time_sort(&(list));
		else if ((list)->r == 1 &&
		         (list)->t == 0 && (list)->u == 0 && (list)->f == 0)
			rev_param_sort(&(list));*/
	if ((*list)->f == 0)
		param_sort(list);
}
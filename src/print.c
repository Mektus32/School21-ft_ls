/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 10:58:44 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/12 11:05:34 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_l_flag(t_param *head, t_param *tmp)
{
	if (tmp->br == 1 && tmp->l != 1 && tmp->name && tmp->k != 1 &&
	!S_ISREG(tmp->buf.st_mode))
		ft_printf("%s:\n", head->name);
	if (tmp->l == 1 && tmp->name && tmp->k != 1)
	{
		if (!S_ISREG(tmp->buf.st_mode))
		{
			ft_printf("%s:\n", head->name);
			ft_printf("total %d\n", total(head->newlvl, head->a));
		}
		if (S_ISREG(tmp->buf.st_mode))
			l_flag(tmp->name, tmp->buf, 1, 0);
	}
}

void		ft_print_files(t_param *tmp1)
{
	t_param		*tmp;
	t_param		*dir;

	tmp = tmp1;
	while (tmp)
	{
		if (tmp->name && tmp->file && tmp->var_errno == 0)
		{
			ft_print_list(tmp);
			tmp->l ? write(1, "\n", 1) : 0;
		}
		tmp = tmp->next;
	}
	dir = tmp1;
	while (dir)
	{
		if (dir->name && !dir->file && (!dir->var_errno ||
		dir->var_errno == 13))
		{
			ft_print_list(dir);
			dir->l ? write(1, "\n", 1) : 0;
		}
		dir = dir->next;
	}
}

t_param		*ft_fill_param(t_param *list, struct stat buf)
{
	list->next = NULL;
	list->newlvl = NULL;
	list->var_errno = 0;
	list->buf = buf;
	return (list);
}

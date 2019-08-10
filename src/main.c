
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:22:46 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/07 14:56:51 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_hidden(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '/')
		i++;
	if (str[i] && str[i + 1] != '.')
		return (0);
	return (1);
}

void	ft_next_print_subdir(t_subdir *head, t_param *p)
{
	while (head)
	{
		if (head->newlvl)
		{
			if (p->l == 1 && p->br == 1)
			{
				ft_printf("kek->%s\n", head->name);
				ft_printf("\n%s:\n", head->name);
				ft_printf("total %ld\n", total(head->newlvl, p->a));
			}
			else if (p->br == 1)
				ft_printf("\n\n%s:\n", head->name);
			ft_print_subdir(head->newlvl, p);
		}
		head = head->next;
	}
}

void	ft_print_subdir(t_subdir *head, t_param *p)
{
	t_subdir	*tmp;

	tmp = head;
	while (tmp)
	{
		if (p->l == 1 && p->a == 1 && p->u == 0 && p->k != 1)
			l_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, 1, 0);
		else if (p->l == 1 && p->a == 0 && p->u == 0 && p->k != 1)
			l_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, 0, 0);
		else if (p->l == 1 && p->a == 1 && p->u == 1 && p->k != 1)
			l_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, 1, 1);
		else if (p->l == 1 && p->a == 0 && p->u == 1 && p->k != 1)
			l_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, 0, 1);
		else if (p->a == 1)
			a_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, p->k);
		else
			no_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, p->k);
		if (tmp->var_errno == 13)
			ft_printf("ls: %s: Permission denied\n", tmp->name);
		tmp = tmp->next;
	}
	ft_next_print_subdir(head, p);
}

void	ft_print_list(t_param *head)
{
	t_param		*tmp;

	tmp = head;
	if (tmp->d && tmp->name)
	{
		if (tmp->l && tmp->k != 1)
			l_flag(head->name, head->newlvl->buf, 1, 0);
		else
			a_flag(head->name, tmp->newlvl->buf, 0);
		if (!tmp->l)
			write(1, &"\n", 1);
		return ;
	}
	if (tmp->br == 1 && tmp-> l != 1 && tmp->name && tmp->k != 1 && !S_ISREG(tmp->buf.st_mode))
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
	if (head->newlvl && head->name)
		ft_print_subdir(head->newlvl, head);
	else if (!head->newlvl && head->k == 0 && !tmp->l)
		ft_printf("%s  ", head->name);
	else if (!head->newlvl && head->k == 1)
		ft_printf("%s\n", head->name);
	if (tmp->l == 0 && tmp->k != 1)
		write(1, &"\n", 1);
}

int		main(int ac, char **av)
{
	char		**split;
	t_ls		*ls;
	t_param		*tmp;
	t_param		*dir;

	ls = ft_memalloc(sizeof(t_ls));
	split = flag_split(ac, av);
	ft_fill(&ls->par, split);
	tmp = ls->par;
	param_flag_sort(&tmp);
	flag_sort(tmp);
	dir = tmp;
	while (tmp)
	{

		if (tmp->name && tmp->file && tmp->var_errno == 0)
		{
			ft_print_list(tmp);
			tmp->l ? write(1, "\n", 1) : 0 ;
		}
		tmp = tmp->next;
	}
	while (dir)
	{
		if (dir->name && !dir->file && (!dir->var_errno || dir->var_errno == 13))
		{
			ft_print_list(dir);
			dir->l ? write(1, "\n", 1) : 0 ;
		}
		dir = dir->next;
	}
	ft_firs_free(&ls);
	return (0);
}

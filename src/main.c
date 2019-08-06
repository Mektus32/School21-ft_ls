/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:22:46 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/06 12:59:59 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    *char_del(char *str, char c)
{
	int i;
	int j;

	j = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			j = i;
		i++;
	}
	if (j >= 0)
		str[j] = '\0';
	return (str);
}

void	ft_print_subdir(t_subdir *head, t_param *p)
{
	t_subdir	*tmp;

	tmp = head;
	while (tmp)
	{
		if (p->l == 1 && p->a == 1 && p->u == 0)
			l_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, 1, 0);
		else if (p->l == 1 && p->a == 0 && p->u == 0)
			l_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, 0, 0);
		else if (p->l == 1 && p->a == 1 && p->u == 1)
			l_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, 1, 1);
		else if (p->l == 1 && p->a == 0 && p->u == 1)
			l_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, 0, 1);
		else if (p->a == 1)
			a_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf);
		else
			no_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf);
		tmp = tmp->next;
	}
	while (head)
	{
		if (head->newlvl)
		{
			if (p->l == 1 && p->br == 1)
			{
				ft_printf("\n%s:\n", head->name);
				ft_printf("total %d\n", head->newlvl->buf.st_blocks);
			}
			else if (p->br == 1)
				ft_printf("\n\n%s:\n", head->name);
			ft_print_subdir(head->newlvl, p);
		}
		head = head->next;
	}
}

void	ft_print_list(t_param *head)
{
	t_param *tmp;

	tmp = head;
	if (tmp->d)
	{
		if (tmp->l)
			l_flag(head->name, head->newlvl->buf, 1, 0);
		else
			a_flag(head->name, tmp->newlvl->buf);
		if (!tmp->l)
			write(1, &"\n", 1);
		return;
	}
	if (tmp->br == 1)
			ft_printf("%s:\n", head->name);
	if (tmp->l == 1)
		ft_printf("total %d\n", head->newlvl->buf.st_blocks);
	while (head)
	{
		if (head->newlvl)
			ft_print_subdir(head->newlvl, head);
		head = head->next;
	}
	if (tmp->l == 0)
		write(1, &"\n", 1);
}

int		main(int ac, char **av)
{
	char    **split;
	t_ls	*ls;
	t_param *tmp;

	ls = ft_memalloc(sizeof(t_ls));
	split = flag_split(ac, av);
	ft_fill(&ls->par, split);
	tmp = ls->par;
	while (tmp)
	{
		flag_sort(tmp);
		ft_print_list(tmp);
		tmp = tmp->next;
	}
	ft_firs_free(&ls);
	return (0);
}

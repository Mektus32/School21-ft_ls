/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:22:46 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/31 11:23:12 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char    *new_strchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	str[i] = '\0';
	return (str);
}

void	ft_print_subdir(t_subdir *head, t_param *p)
{
	t_subdir	*tmp;

	tmp = head;
	while (tmp)
	{
		if (p->l == 1 && p->a == 1)
			l_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, 1);
		else if (p->l == 1 && p->a == 0)
			l_flag(ft_strrchr(tmp->name, '/') + 1, tmp->buf, 0);
		else if (p->a == 1)
			a_flag(ft_strrchr(tmp->name, '/') + 1);
		else
			no_flag(ft_strrchr(tmp->name, '/') + 1);
		tmp = tmp->next;
	}
	while (head)
	{
		if (head->newlvl)
		{
			ft_printf("\n%s:\n", head->name);
			ft_print_subdir(head->newlvl, p);
		}
		head = head->next;
	}
}

void	ft_print_list(t_param *head)
{
	t_param *tmp;

	tmp = head;
	if (tmp->l == 1)
		ft_printf("%s:\n", new_strchr(head->name, '/'));
	while (head)
	{
		if (head->newlvl)
		{
			ft_print_subdir(head->newlvl, head);
		}
		head = head->next;
	}
	if (tmp->l == 0)
		write(1, &"\n", 1);
}

int		main(int ac, char **av)
{
	char    **split;
	t_ls	*ls;

	ls = ft_memalloc(sizeof(t_ls));
	split = flag_split(ac, av);
	ft_fill(&ls->par, split);
	flag_sort(ls->par);
	ft_print_list(ls->par);
	return (0);
}

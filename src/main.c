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

void	ft_print_subdir(t_subdir *head)
{
	t_subdir	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%s\n", tmp->print);
		//if (tmp->name)
		//	ft_printf("%s--", tmp->name);
		//ft_printf("-a->%ld", tmp->atime);
		//ft_printf("-m->%ld", tmp->mtime);
		//ft_printf("-c->%ld\n", tmp->ctime);
		tmp = tmp->next;
	}
	while (head)
	{
		if (head->newlvl)
			ft_print_subdir(head->newlvl);
		head = head->next;
	}
}

void	ft_print_list(t_param *head)
{
	printf("\n\n");
	while (head)
	{
		if (head->newlvl)
			ft_print_subdir(head->newlvl);
		ft_printf("%s\n", head->name);
		head = head->next;
	}
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

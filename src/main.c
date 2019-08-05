/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:22:46 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/05 15:57:15 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_subdir(t_subdir *head)
{
	t_subdir	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->name)
			ft_printf("%s--", tmp->name);
		ft_printf("-a->%ld", tmp->atime);
		ft_printf("-m->%ld", tmp->mtime);
		ft_printf("-c->%ld\n", tmp->ctime);
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
	t_ls	*ls;
	char	**split;
	int		count;

	ls = ft_memalloc(sizeof(t_ls));
	split = flag_split(ac, av);
	ft_fill(&ls->par, split);
//	ls->par = ft_create_param("_/Users/ojessi/Desktop/myft_ls/src/");
	//ft_fill_subdir(&ls->par->newlvl, ls->par->name);
	//ft_print_list(ls->par);
	//levels_sort(&ls->par->newlvl);
	//ft_print_list(ls->par);
//	for (count = 0; split[count]; count++)
//		ft_printf("%s\n", split[count]);
//	for (int i = 0; i < count; i++)
//		ft_printf("%s\n", split[i]);
	ft_print_flags(ls->par);
	printf("l->%d\n", ls->par->l);
	printf("a->%d\n", ls->par->a);
	printf("r->%d\n", ls->par->r);
	printf("t->%d\n", ls->par->t);
	printf("u->%d\n", ls->par->u);
	printf("f->%d\n", ls->par->f);
	printf("g->%d\n", ls->par->g);
	printf("d->%d\n", ls->par->d);
	printf("G->%d\n", ls->par->G);
	printf("R->%d\n", ls->par->R);
	return (0);
}

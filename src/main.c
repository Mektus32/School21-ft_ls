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

int		main(int ac, char **av)
{
	t_ls	*ls;

	ac = 0;
	av[0] = NULL;
	ls = ft_memalloc(sizeof(t_ls));
	ls->par = ft_create_elem(ft_strdup("filename_lRartufgdG"));
	printf("nam->[%s]\n", ls->par->name);
	printf("l->[%u]\n", ls->par->l);
	printf("R->[%u]\n", ls->par->R);
	printf("a->[%u]\n", ls->par->a);
	printf("r->[%u]\n", ls->par->r);
	printf("t->[%u]\n", ls->par->t);
	printf("u->[%u]\n", ls->par->u);
	printf("f->[%u]\n", ls->par->f);
	printf("g->[%u]\n", ls->par->g);
	printf("f->[%u]\n", ls->par->f);
	printf("G->[%u]\n", ls->par->G);
	return (0);
}

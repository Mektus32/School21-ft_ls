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

char    *flag_return(int ac, char **av)
{
	int     i;
	char    *filename;
	char    *flags;
	char    *tmp;
	i = 1;
	filename = NULL;
	flags = NULL;
	if (ac == 1)
		return (ft_strjoin("_","."));
	while (i < ac && av[i][0] == '-')
	{
		if (flags)
			tmp = ft_strdup(flags);
		else
			tmp = ft_strdup("");
		ft_strdel(&flags);
		flags = ft_strjoin(tmp, av[i] + 1);
		ft_strdel(&tmp);
		i++;
	}
	if (flags && i < ac)
	{
		tmp = ft_strdup(flags);
		ft_strdel(&flags);
		flags = ft_strjoin(tmp, "_");
		filename = ft_strjoin(flags, av[i]);
	}
	else if (flags && i == ac)
	{
		tmp = ft_strdup(flags);
		ft_strdel(&flags);
		flags = ft_strjoin(tmp, "_");
		filename = ft_strjoin(flags, ".");
	}
	else
	{
		tmp = ft_strdup(av[i]);
		filename = ft_strjoin("_", tmp);
	}
	ft_strdel(&tmp);
	return (filename);
}

int		main(int ac, char **av)
{
	t_ls	*ls;

	ac = 0;
	av[0] = NULL;
	ls = ft_memalloc(sizeof(t_ls));
	ft_push_back(&ls->par, flag_return(ac, av));
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

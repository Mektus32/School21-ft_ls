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
	char    *line;
	t_ls	*ls;
	DIR     *fd;
	int 	j = 1;

	//vanilla_ls(av[1]);
	ls = ft_memalloc(sizeof(t_ls));
	ft_fill_param_list(ac, av, ls);
	//ls->par = ft_create_elem(flag_return(ac, av, &j));
	fd = opendir(ls->par->name);
	while (vanilla_ls(fd, 1, &line))
	{
		if (line)
			printf("%s\n", line);
		ft_strdel(&line);
	}
	return (0);
}

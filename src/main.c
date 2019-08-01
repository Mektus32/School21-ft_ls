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
		ft_printf("%s--", tmp->name);
		ft_printf("-a->%ld", tmp->atime);
		ft_printf("-m->%ld", tmp->mtime);
		ft_printf("-c->%ld\n", tmp->ctime);
		tmp = tmp->next;
	}
	while (head)
	{
		ft_print_subdir(head->newlvl);
		head = head->next;
	}
}

void	ft_print_list(t_param *head)
{
	printf("\n\n");
	while (head)
	{
		ft_print_subdir(head->newlvl);
		head = head->next;
	}
}

int		main(int ac, char **av)
{
	char    *line;
	t_ls	*ls;
	DIR     *fd;
	int 	j = 1;

	//vanilla_ls(av[1]);
	ls = ft_memalloc(sizeof(t_ls));
//	ft_fill_param_list(ac, av, ls);
	ls->par = ft_create_param("_/Users/ojessi/Desktop/ft_ls/subdir");
	ft_fill_subdir(&ls->par->newlvl, ls->par->name);
	ft_print_list(ls->par);
//	fd = opendir(ls->par->name);
//	while (vanilla_ls(fd, 1, &line))
//	{
//		if (line)
//			printf("%s\n", line);
//		ft_strdel(&line);
//	}
	return (0);
}

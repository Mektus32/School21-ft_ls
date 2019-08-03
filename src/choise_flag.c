/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choise_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:45:53 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/03 21:45:54 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_flags(t_param *par)
{
	while (par)
	{
		if (par->l)
			return ;
		if (par->a)
			return ;
		if (par->r)
			return ;
		if (par->t)
			return ;
		if (par->u)
			return ;
		if (par->f)
			return ;
		if (par->g)
			return ;
		if (par->d)
			ft_printf("%s", par->name);
		if (par->G)
			return ;
		par->d ? 0 : ft_print_list(par);
		par = par->next;
	}
}


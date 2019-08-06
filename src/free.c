/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:07:06 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/06 13:07:07 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
static void	ft_free_newlvl(t_subdir **head)
{
	t_subdir	*tmp;
	t_subdir	*del;

	if (!head || !*head)
		return ;
	tmp = *head;
	while (tmp)
	{
		ft_free_newlvl(&tmp->newlvl);
		del = tmp;
		tmp = tmp->next;
		free(del->name);
		free(del);
	}
}

void		ft_firs_free(t_ls **ls)
{
	t_param	*tmp;
	t_param	*del;

	if (!ls || !*ls)
		return ;
	tmp = (*ls)->par;
	while (tmp)
	{
		ft_free_newlvl(&tmp->newlvl);
		del = tmp;
		tmp = tmp->next;
		free(del->name);
		free(del);
	}
	free(*ls);
}

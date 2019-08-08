/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:47:13 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/08 16:47:16 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_param		*ft_not_a_directory(t_param *list)
{
	ft_printf("ls: %s: Not a directory\n", list->name);
	list->name ? free(list->name) : 0;
	list->name = NULL;
	list->newlvl = NULL;
	list->l = 0;
	list->br = 0;
	list->a = 0;
	list->r = 0;
	list->t = 0;
	list->u = 0;
	list->f = 0;
	list->d = 0;
	list->k = 0;
	list->var_errno = errno;
	return (list);
}

t_param		*ft_permission(t_param *list)
{
	ft_printf("ls: %s: Permission denied\n", list->name);
	list->name ? free(list->name) : 0;
	list->name = NULL;
	list->newlvl = NULL;
	list->l = 0;
	list->br = 0;
	list->a = 0;
	list->r = 0;
	list->t = 0;
	list->u = 0;
	list->f = 0;
	list->d = 0;
	list->k = 0;
	list->var_errno = errno;
	return (list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:57:00 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/06 16:02:05 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*new_strjoin(char **line)
{
	int		len;
	int		i;
	char	*str;

	if (!(line))
		return (NULL);
	len = 0;
	i = 0;
	while (line[i])
	{
		len += ft_strlen(line[i]) + 1;
		i++;
	}
	i = 0;
	str = ft_strnew(len);
	len = 0;
	while (line[i])
	{
		ft_strcpy(str + len, line[i]);
		len += ft_strlen(line[i]);
		str[len] = ' ';
		len++;
		i++;
	}
	return (str);
}

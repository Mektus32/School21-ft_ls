/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:57:00 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/07 14:56:56 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*new_strjoin(char **line)
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

long int	total(t_subdir *level, int a)
{
	long int total;

	total = 0;
	while (level)
	{
		if (a == 0 && !is_hidden(level->name))
			total += level->buf.st_blocks;
		else if (a == 1)
			total += level->buf.st_blocks;
		level = level->next;
	}
	return (total);
}

char		*char_del(char *str, char c)
{
	int		i;
	int		j;

	j = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			j = i;
		i++;
	}
	if (j >= 0)
		str[j] = '\0';
	return (str);
}

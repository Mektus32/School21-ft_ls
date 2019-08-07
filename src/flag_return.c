/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:54:46 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/06 15:55:55 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*filename_case1(char *flags, char *av)
{
	char	*tmp;

	tmp = ft_strjoin(flags, "_");
	return (ft_free_join(tmp, char_del(av, '/')));
}

static char		*filename_case2(char *flags)
{
	char	*tmp;

	tmp = ft_strjoin(flags, "_");
	return (ft_free_join(tmp, "."));
}

static char		*filename_case3(char *av)
{
	char	*tmp;
	char	*filename;

	tmp = ft_strdup(av);
	filename = ft_strjoin("_", tmp);
	ft_strdel(&tmp);
	return (filename);
}

void			flag_return(int ac, char **av, char **split, int *i)
{
	static char	*flags;
	char	*tmp;
	int     j;

	j = 0;
	while (*i < ac && av[*i][0] == '-')
	{
		if (j == 0 && flags)
			ft_strdel(&flags);
		if (flags)
			tmp = ft_strdup(flags);
		else
			tmp = ft_strdup("");
		ft_strdel(&flags);
		flags = ft_strjoin(tmp, av[*i] + 1);
		ft_strdel(&tmp);
		(*i)++;
		j++;
	}
	if (flags && *i < ac)
		*split = filename_case1(flags, av[*i]);
	else if (flags && *i == ac)
		*split = filename_case2(flags);
	else
		*split = filename_case3(av[*i]);
}

char			**flag_split(int ac, char **av)
{
	char	**split;
	int		i;
	int		count;

	split = (char **)malloc(sizeof(char *) * ac);
	i = 1;
	count = 0;
	if (ac == 1)
	{
		split[count] = ft_strdup("_.");
		split[1] = NULL;
		return (split);
	}
	while (i < ac)
	{
		flag_return(ac, av, &split[count], &i);
		i++;
		count++;
	}
	split[count] = NULL;
	return (split);
}

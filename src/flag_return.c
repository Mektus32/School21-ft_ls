#include "ft_ls.h"

static char    *filename_case1(char *flags, char *av)
{
	char *tmp;

	tmp = ft_strdup(flags);
	ft_strdel(&flags);
	flags = ft_strjoin(tmp, "_");
	ft_strdel(&tmp);
	return (ft_strjoin(flags, av));
}

static char    *filename_case2(char *flags)
{
	char *tmp;

	tmp = ft_strdup(flags);
	ft_strdel(&flags);
	flags = ft_strjoin(tmp, "_");
	ft_strdel(&tmp);
	return (ft_strjoin(flags, "."));
}

static char    *filename_case3(char *av)
{
	char *tmp;
	char *filename;

	tmp = ft_strdup(av);
	filename = ft_strjoin("_", tmp);
	ft_strdel(&tmp);
	return (filename);
}

void flag_return(int ac, char **av, char **split, int *i)
{
	char    *flags;
	char    *tmp;

	flags = NULL;
	if (ac == 1)
	{
		*split = ft_strjoin("_", ".");
		return ;
	}
	while (*i < ac && av[*i][0] == '-')
	{
		if (flags)
			tmp = ft_strdup(flags);
		else
			tmp = ft_strdup("");
		ft_strdel(&flags);
		flags = ft_strjoin(tmp, av[*i] + 1);
		ft_strdel(&tmp);
		(*i)++;
	}
	if (flags && *i < ac)
		*split = filename_case1(flags, av[*i]);
	else if (flags && *i == ac)
		*split = filename_case2(flags);
	else
		*split = filename_case3(av[*i]);
}

char **flag_split(int ac, char **av)
{
	char    **split;
	int     i;
	int     count;

	split = (char **)malloc(sizeof(char *) * ac);
	i = 1;
	count = 0;
	while (i < ac && count < ac)
	{
		flag_return(ac, av, &split[count], &i);
		i++;
		count++;
	}
	split[count] = NULL;
	return (split);
}
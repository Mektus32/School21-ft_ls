#include "ft_ls.h"

char    *filename_case1(char *flags, char *av)
{
	char *tmp;

	tmp = ft_strdup(flags);
	ft_strdel(&flags);
	flags = ft_strjoin(tmp, "_");
	ft_strdel(&tmp);
	return (ft_strjoin(flags, av));
}

char    *filename_case2(char *flags)
{
	char *tmp;

	tmp = ft_strdup(flags);
	ft_strdel(&flags);
	flags = ft_strjoin(tmp, "_");
	ft_strdel(&tmp);
	return (ft_strjoin(flags, "."));
}

char    *filename_case3(char *av)
{
	char *tmp;
	char *filename;

	tmp = ft_strdup(av);
	filename = ft_strjoin("_", tmp);
	ft_strdel(&tmp);
	return (filename);
}

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
		filename = filename_case1(flags, av[i]);
	else if (flags && i == ac)
		filename = filename_case2(flags);
	else
		filename = filename_case3(av[i]);
	return (filename);
}
#include "ft_ls.h"

char    *flag_return(int ac, char **av)
{
	int     i;
	char    *filename;
	char    *flags;
	char    *tmp;

	i = 1;
	filename = NULL;
	flags = NULL;
	if (ac < 1)
		return (NULL);
	while (av[i][0] == '-')
	{
		if (flags)
			tmp = ft_strdup(flags);
		else
			tmp = ft_strdup(" ");
		ft_strdel(&flags);
		flags = ft_strjoin(tmp, av[i] + 1);
		ft_strdel(&tmp);
		i++;
	}
	if (flags && i <= ac)
		filename = ft_strjoin(av[i], flags);
	else
		filename = ft_strdup(av[i]);
	return (filename);
}
#include "ft_ls.h"

void    vanilla_ls(char *filename)
{
	DIR             *dir;
	struct dirent   *entry;

	dir = opendir(filename);
	if (!dir)
	{
		no_such_dir(filename);
		return ;
	}
	while ((entry = readdir(dir)))
	{
		ft_putstr(entry->d_name);
		write(1, &" ", 1);
	}
	write(1, &"\n", 1);
	closedir(dir);
}
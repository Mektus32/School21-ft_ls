#include "ft_ls.h"

void    vanilla_ls(char *catalog)
{
	DIR             *dir;
	struct dirent   *entry;
	struct stat     file;

	dir = opendir(catalog);
	if (!dir)
	{
		no_such_dir(catalog);
		return ;
	}
	while ((entry = readdir(dir)))
	{
		lstat(entry->d_name, &file);
		//printf("%o  %s\n", file.st_mode, entry->d_name);
		if ((S_ISREG(file.st_mode) || S_ISDIR(file.st_mode))
		&& (entry->d_name[0] != '.'))
		{
			ft_putstr(entry->d_name);
			write(1, &"  ", 2);
		}
	}
	write(1, &"\n", 1);
	closedir(dir);
}
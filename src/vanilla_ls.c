#include "ft_ls.h"

int vanilla_ls(DIR *dir, int flag, int flag2)
{
	struct dirent   *entry;
	struct stat     file;

	if (!dir)
		return (0);
	entry = readdir(dir);
	if (!entry)
		return (0);
	lstat(entry->d_name, &file);
	if (flag == 0 && (S_ISREG(file.st_mode) || S_ISDIR(file.st_mode))
		&& (entry->d_name[0] != '.'))
	{
		ft_putstr(entry->d_name);
		if (flag2 == 0)
			write(1, &"\n", 1);
		else
			write(1, &"  ", 2);
	}
	else if (flag == 1)
	{
		ft_putstr(entry->d_name);
		if (flag2 == 0)
			write(1, &"\n", 1);
		else
			write(1, &"  ", 2);
	}
	return (1);
}
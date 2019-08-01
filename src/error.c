#include "ft_ls.h"

void    no_such_dir(char *filename)
{
	ft_printf("ft_ls: cannot access '%s': No such file or directory\n", filename);
}
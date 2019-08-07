/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:49:45 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/06 15:51:28 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	file_type(struct stat file, char **ac_rights)
{
	if (S_ISDIR(file.st_mode))
		(*ac_rights)[0] = 'd';
	else if (S_ISCHR(file.st_mode))
		(*ac_rights)[0] = 'c';
	else if (S_ISBLK(file.st_mode))
		(*ac_rights)[0] = 'b';
	else if (S_ISLNK(file.st_mode))
		(*ac_rights)[0] = 'l';
	else if (S_ISSOCK(file.st_mode))
		(*ac_rights)[0] = 's';
	else if (S_ISFIFO(file.st_mode))
		(*ac_rights)[0] = 'p';
}

void	uid_rights(struct stat file, char **ac_rights)
{
	if (file.st_mode & S_ISVTX)
		(*ac_rights)[3] = 't';
	if (file.st_mode & S_ISUID || file.st_mode & S_ISGID)
		(*ac_rights)[3] = 's';
	if (file.st_mode & S_IXUSR)
		(*ac_rights)[3] = 'x';
	if (file.st_mode & S_IWUSR)
		(*ac_rights)[2] = 'w';
	if (file.st_mode & S_IRUSR)
		(*ac_rights)[1] = 'r';
}

void	grp_rights(struct stat file, char **ac_rights)
{
	if (file.st_mode & S_ISVTX)
		(*ac_rights)[6] = 't';
	if (file.st_mode & S_ISUID || file.st_mode & S_ISGID)
		(*ac_rights)[6] = 's';
	if (file.st_mode & S_IXGRP)
		(*ac_rights)[6] = 'x';
	if (file.st_mode & S_IWGRP)
		(*ac_rights)[5] = 'w';
	if (file.st_mode & S_IRGRP)
		(*ac_rights)[4] = 'r';
}

void	oth_rights(struct stat file, char **ac_rights)
{
	if (file.st_mode & S_ISVTX)
		(*ac_rights)[9] = 't';
	if (file.st_mode & S_ISUID || file.st_mode & S_ISGID)
		(*ac_rights)[9] = 's';
	if (file.st_mode & S_IXOTH)
		(*ac_rights)[9] = 'x';
	if (file.st_mode & S_IWOTH)
		(*ac_rights)[8] = 'w';
	if (file.st_mode & S_IROTH)
		(*ac_rights)[7] = 'r';
}

void	l_flag(char *filename, struct stat file, int hidden, int t)
{
	char	*ac_rights;
	char	*time;

	if (!filename || (hidden == 0 && filename[0] == '.'))
		return ;
	lstat(filename, &file);
	ac_rights = ft_strdup("----------");
	file_type(file, &ac_rights);
	uid_rights(file, &ac_rights);
	grp_rights(file, &ac_rights);
	oth_rights(file, &ac_rights);
	ft_printf("%s %3ld %s %s %6ld ", ac_rights, file.st_nlink,
			getpwuid(file.st_uid)->pw_name, getgrgid(file.st_gid)->gr_name,
			file.st_size);
	ft_strdel(&ac_rights);
	if (t == 0)
		time = ft_strdup(ctime(&file.st_mtime));
	else
		time = ft_strdup(ctime(&file.st_atime));
	time[ft_strlen(time) - 1] = '\0';
	ft_putstr(time);
	ft_strdel(&time);
	write(1, &" ", 1);
	hidden == 1 ? a_flag(filename, file, 0) : no_flag(filename, file, 0);
	write(1, &"\n", 1);
}

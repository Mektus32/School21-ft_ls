#include "ft_ls.h"

void    file_type(struct stat file, char **ac_rights)
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

void    uid_rights(struct stat file, char **ac_rights)
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

void    grp_rights(struct stat file, char **ac_rights)
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

void    oth_rights(struct stat file, char **ac_rights)
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

char **l_flag(char *filename)
{
	char        *ac_rights;
	char        **result;
	struct stat file;

	lstat(filename, &file);
	result = (char **)malloc(sizeof(char *) * 8);
	ac_rights = ft_strdup("----------");
	file_type(file, &ac_rights);
	uid_rights(file, &ac_rights);
	grp_rights(file, &ac_rights);
	oth_rights(file, &ac_rights);
	result[0] = ac_rights;
	result[1] = ft_strdup(ft_itoa(file.st_nlink));
	result[2] = ft_strdup(getpwuid(file.st_uid)->pw_name);
	result[3] = ft_strdup(getgrgid(file.st_gid)->gr_name);
	result[4] = ft_strdup(ft_itoa(file.st_size));
	result[5] = ft_strdup(ctime(&file.st_mtime));
	result[5][25 - 1] = '\0';
	result[6] = ft_strdup(filename);
	result[7] = NULL;
	return (result);
}

char *no_flag(char *filename)
{
	if (!filename)
		return (0);
	if (filename[0] != '.')
		return (ft_strdup(filename));
	return (ft_strdup(""));
}

char *a_flag(char *filename)
{
	if (!filename)
		return (0);
	return (ft_strdup(filename));
}
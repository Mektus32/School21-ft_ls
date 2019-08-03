#include "ft_ls.h"

char    *new_strjoin(char **line)
{
	int     len;
	int     i;
	char    *str;

	if (!(line))
		return (NULL);
	len = 0;
	i = 0;
	while (line[i])
	{
		len += ft_strlen(line[i]) + 1;
		i++;
	}
	i = 0;
	str = ft_strnew(len);
	len = 0;
	while (line[i])
	{
		ft_strcpy(str + len, line[i]);
		len += ft_strlen(line[i]);
		str[len] = ' ';
		len++;
		i++;
	}
	return (str);
}
#include "ft_ls.h"

t_param		*ft_create_elem(char *str)
{
	t_param		*list;
	int			i;

	if (!(list = ft_memalloc(sizeof(t_param))))
		return (0);
	i = 0;
	while (str[i] != '_' && str[i] != '\0')
	{
		str[i] == 'l' ? list->l = (unsigned int)1 : 0;
		str[i] == 'R' ? list->R = (unsigned int)1 : 0;
		str[i] == 'a' ? list->a = (unsigned int)1 : 0;
		str[i] == 'r' ? list->r = (unsigned int)1 : 0;
		str[i] == 't' ? list->t = (unsigned int)1 : 0;
		str[i] == 'u' ? list->u = (unsigned int)1 : 0;
		str[i] == 'f' ? list->f = (unsigned int)1 : 0;
		str[i] == 'g' ? list->g = (unsigned int)1 : 0;
		str[i] == 'd' ? list->d = (unsigned int)1 : 0;
		str[i] == 'G' ? list->G = (unsigned int)1 : 0;
		i++;
	}
	list->name = ft_strdup(str + i + 1);
	free(str);
	return (list);
}

t_param		*ft_push_back(t_param **head, char *str)
{
	t_param	*list;

	if (!head)
		return (NULL);
	list = *head;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(str);
	}
	else
		list = ft_create_elem(str);
	return (list);
}
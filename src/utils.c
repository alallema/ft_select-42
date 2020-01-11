#include "select.h"

int		print_error(char *err)
{
	ft_putendl_fd(err, 2);
	return (EXIT_FAILURE);
}

t_lst	*lstnew(char *content, int i, int key)
{
	t_lst *elem;

	if (!(elem = ft_memalloc(sizeof(t_lst))))
		return (NULL);
	if (content == NULL)
	{
		elem->content = NULL;
		elem->i = 0;
		elem->key = 0;
	}
	else
	{
		elem->content = ft_memalloc(sizeof(char *) * ft_strlen(content));
		if (elem->content == NULL)
			return (NULL);
        elem->content = ft_strdup(content);
		elem->i = i;
		elem->key = key;
	}
	elem->next = NULL;
    elem->prev = NULL;
	return (elem);
}

void	lstpushback(t_lst **alst, char *content, int i, int key, int len)
{
	t_lst	*elem;

	elem = *alst;
	if (*alst != NULL)
	{
		while (elem->next)
        {
			elem = elem->next;
        }
	}
	elem->next = lstnew(content, i, key);
    elem->next->prev = elem;
    if (i == len - 1)
    {
        elem->next->next = *alst;
        (*alst)->prev = elem->next;
    }
}

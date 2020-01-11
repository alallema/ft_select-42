#include "select.h"

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
    if (i == len)
    {
        elem->next->next = *alst;
        (*alst)->prev = elem->next;
    }
}
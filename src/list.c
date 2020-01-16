#include "select.h"

static t_lst	*lstnew(char *content, int i, int key)
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

static void	lstpushback(t_lst **alst, char *content, int i, int key, int len)
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

int     stock_data(int ac, char **av)
{
  int     i;
  size_t  j;
  t_data  *data;

  i = 0;
  j = 0;
  if (!(data = ft_memalloc(sizeof(t_data)))
    && !(data->list = ft_memalloc(sizeof(t_list *))))
    return (print_error(ERR_MALL));
  while (ac > i)
  {
    if (i == 1)
			data->list = lstnew(av[i], i, 1);
		if (i > 1)
			lstpushback(&(data->list), av[i], i, 0, ac - 1);
    if (ft_strlen(av[i]) > j)
      j = ft_strlen(av[i]);
    if (ac == 2 && data->list)
    {
      data->list->next = data->list;
      data->list->prev = data->list;
    }
    i++;
  }
  data->len = ac - 1;
  data->len_max = j;
  data->color = ft_strdup("\033[39m");
  data->color_nb = 7;
  get_data(data);
  return (EXIT_SUCCESS);
}
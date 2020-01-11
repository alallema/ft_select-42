#include "select.h"

void    print_list(t_data *data)
{
  t_lst  *elem;
  int    i;

  i = 0;
  elem = data->list;
  while(elem && elem->next)
  {
    ft_putendl((char *)elem->content);
    // if (elem->i == data->len)
    //   break;
    if (i == 10)
      break;
    elem = elem->next;
    i++;
  }
  i = 0;
  while(elem)
  {
    ft_putendl((char *)elem->content);
    // if (elem->i == 1)
    //   break;
    if (i == 14)
      break;
    elem = elem->prev;
    i++;
  }
}

t_data		*get_data(t_data *data)
{
	static t_data	*elem;

  if (!elem && !data)
    return (NULL);
	if (!data)
		return (elem);
	else
	{
		elem = data;
		return (elem);
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
    i++;
  }
  data->len = ac - 1;
  data->len_max = j;
  get_data(data);
  return (EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
  t_data  *data;

  data = NULL;
  if (ac < 2)
	  return (EXIT_SUCCESS);
  printf("Begin\n");
  signal_handler();
  get_window();
  if (stock_data(ac, av) == EXIT_FAILURE)
    return(EXIT_FAILURE);
  data = get_data(data);
  // print_list(data);
  if (init_termios() == EXIT_FAILURE)
	  return (EXIT_FAILURE);
  brain_print();
  key_press();
  close_termios();
  free_data();
  ft_putstr("End\n");
  return (EXIT_SUCCESS);
}
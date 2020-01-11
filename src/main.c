#include "select.h"

void    print_list(t_data *data)
{
  t_lst  *elem;

  elem = data->list;
  while(elem && elem->next)
  {
    elem = elem->next;
    ft_putendl((char *)elem->content);
  }
  while(elem)
  {
    ft_putendl((char *)elem->content);
    elem = elem->prev;
  }
}

t_data		*get_data(t_data *data)
{
	static t_data	*elem;

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
			lstpushback(&(data->list), av[i], i, 0, ac);
    if (ft_strlen(av[i]) > j)
      j = ft_strlen(av[i]);
    i++;
  }
  data->len = ac;
  data->len_max = j;
  get_data(data);
  return (EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
  t_data  *data;

  (void)av;
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
  ft_putstr("End\n");
  return (EXIT_SUCCESS);
}
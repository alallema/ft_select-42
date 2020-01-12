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

int			main(int ac, char **av)
{
  t_data  *data;

  data = NULL;
  if (ac < 2)
	  return (print_usage());
  signal_handler();
  if (stock_data(ac, av) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  data = get_data(data);
  get_window();
  // print_list(data);
  if (init_termios() == EXIT_FAILURE)
	  return (EXIT_FAILURE);
  brain_print();
  key_press();
  close_termios();
  free_data();
  return (EXIT_SUCCESS);
}
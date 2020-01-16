#include "select.h"

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
  if (init_termios() == EXIT_FAILURE)
	  return (EXIT_FAILURE);
  display();
  key_press();
  close_termios();
  free_data();
  return (EXIT_SUCCESS);
}
#include "select.h"

int     stock_args(int ac, char **av, t_data *data)
{
  int     i;
  size_t  j;

  i = 0;
  j = 0;
  if (!(data = ft_memalloc(sizeof(t_data))))
    return (print_error(ERR_MALL));
  if (!(data->args = ft_memalloc(sizeof(char *) * (ac + 1))))
    return (print_error(ERR_MALL));
  data->args[ac + 1] = NULL;
  data->len = ac;
  while (ac > i)
  {
    data->args[i] = ft_strdup(av[i]);
    if (ft_strlen(av[i]) > j)
      j = ft_strlen(av[i]);
    i++;
  }
  data->len_max = j;
  return (EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
  t_data  *data;

  (void)av;
  data = NULL;
  if (ac < 2)
	  return (EXIT_SUCCESS);
  printf("Begin %d\n", ac);
  signal_handler();
  get_window();
  if (stock_args(ac, av, data) == EXIT_FAILURE)
    return(EXIT_FAILURE);
  if (init_termios() == EXIT_FAILURE)
	  return (EXIT_FAILURE);
  ft_putstr("Term active !!!\n");
  key_press(data);
  close_termios();
  ft_putstr("End\n");
  return (EXIT_SUCCESS);
}
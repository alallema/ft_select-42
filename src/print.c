#include "select.h"

int			t_putchar(int i)
{
	write(STDERR_FILENO, &i, 1);
	return (0);
}

int		print_error(char *err)
{
	ft_putendl_fd(err, 2);
	return (EXIT_FAILURE);
}

int     print_usage(void)
{
    ft_putendl_fd("usage: ./ft_select [args]", 2);
	return (EXIT_SUCCESS);
}
#include "select.h"

int			t_putchar(int i)
{
	write(1, &i, 1);
	return (0);
}

// void		t_puts(char *s, int i)
// {
// 	tputs(tgetstr(s, NULL), i, t_putchar);
// }

int		print_error(char *err)
{
	ft_putendl_fd(err, 2);
	return (EXIT_FAILURE);
}

int     print_usage(void)
{
    ft_putendl_fd("usage: ./ft_select [args]", 2);
	return (EXIT_FAILURE);
}
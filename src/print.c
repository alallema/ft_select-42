#include "select.h"

int			t_putchar(int i)
{
	write(1, &i, 1);
	return (0);
}

void		t_puts(char *s, int i)
{
	tputs(tgetstr(s, NULL), i, t_putchar);
}

void	print_elem(char *s)
{
	ft_putstr_fd("\033[1;35m", 2);
	ft_putendl_fd(s, 2);
}

// static void	print_underline(char *s)
// {
// 	tputs(tgetstr("us", NULL), 1, t_putchar);
// 	ft_putstr_fd("\033[1;35m", 2);
// 	ft_putendl_fd(s, 2);
// 	tputs(tgetstr("ue", NULL), 1, t_putchar);
// }

// static void    print_stdout(char *s)
// {
// 	tputs(tgetstr("so", NULL), 1, t_putchar);
// 	ft_putstr_fd("\033[1;35m", 2);
// 	ft_putendl_fd(s, 2);
// 	tputs(tgetstr("se", NULL), 1, t_putchar);
// }

// static void	print_underout(char *s)
// {
// 	tputs(tgetstr("so", NULL), 1, t_putchar);
// 	tputs(tgetstr("us", NULL), 1, t_putchar);
// 	ft_putstr_fd("\033[1;35m", 2);
// 	ft_putendl_fd(s, 2);
// 	tputs(tgetstr("se", NULL), 1, t_putchar);
// 	tputs(tgetstr("ue", NULL), 1, t_putchar);
// }

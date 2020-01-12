#include "select.h"

static t_term	*get_term(void)
{
	static t_term	term;

	return (&term);
}

int				init_termios(void)
{
	t_term			*st_term;

	st_term = get_term();
	if (!getenv("TERM"))
		tgetent(NULL, "xterm-256color");
	else if (tgetent(NULL, getenv("TERM")) < 1)
		return (EXIT_FAILURE);
	if (tcgetattr(STDERR_FILENO, &st_term->old) == -1)
		return (EXIT_FAILURE);
	if (tcgetattr(STDERR_FILENO, &st_term->new) == -1)
		return (EXIT_FAILURE);
	st_term->new.c_lflag &= ~(ICANON | ECHO | TOSTOP);
	st_term->new.c_cc[VMIN] = 1;
	st_term->new.c_cc[VTIME] = 0;
	if (tcsetattr(STDERR_FILENO, TCSANOW, &st_term->new) == -1)
		return (EXIT_FAILURE);
	tputs(tgetstr("ti", NULL), 1, t_putchar);
	tputs(tgetstr("vi", NULL), 1, t_putchar);
	// tputs(tgetstr("cl", NULL), 0, t_putchar);
	return (EXIT_SUCCESS);
}

int				close_termios(void)
{
	t_term			*st_term;

	st_term = get_term();
	if (tcsetattr(0, TCSANOW, &st_term->old) == -1)
		return (EXIT_FAILURE);
	tputs(tgetstr("te", NULL), 1, t_putchar);
	tputs(tgetstr("ve", NULL), 1, t_putchar);
	return (EXIT_SUCCESS);
}
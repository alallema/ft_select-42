#include "select.h"

void    get_sigwinch(int sig)
{
    (void)sig;
    // tputs(tgetstr("cl", NULL), 0, t_putchar);
    get_window();
    return;
}

void    get_sigcont(int sig)
{
    (void)sig;
    init_termios();
    printf("Continu\n");
    signal_handler();
    return;
}

void    get_sigquit(int sig)
{
    (void)sig;
    printf("SEGFAULT\n");
    close_termios();
    exit(0);
    return;
}

void    get_sigint(int sig)
{
    (void)sig;
    printf("CTRL C\n");
    // printf("ctrl c\n");
    close_termios();
    exit(0);
    return;
}

void    get_sigtstp(int sig)
{
    (void)sig;
    close_termios();
	signal(SIGTSTP, SIG_DFL);
    ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
    return;
}

void    signal_handler(void)
{
    signal(SIGWINCH, get_sigwinch);
	signal(SIGCONT, get_sigcont);
	signal(SIGINT, get_sigint);
	signal(SIGQUIT, get_sigquit);
    signal(SIGTSTP, get_sigtstp);
    // signal(SIGABRT);
    // signal(SIGSTOP);
    return;
}

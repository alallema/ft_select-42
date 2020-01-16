#include "select.h"

void    get_sigwinch(int sig)
{
    (void)sig;
    get_window();
    display();
    return;
}

void    get_sigcont(int sig)
{
    (void)sig;
    init_termios();
    signal_handler();
    display();
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
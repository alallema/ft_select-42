#include "select.h"

static void    get_sigwinch(int sig)
{
    (void)sig;
    tputs(tgetstr("cl", NULL), 0, t_putchar);
    get_window();
    brain_print();
    return;
}

static void    get_sigcont(int sig)
{
    (void)sig;
    init_termios();
    signal_handler();
    brain_print();
    return;
}

static void    get_sigtstp(int sig)
{
    (void)sig;
    close_termios();
	signal(SIGTSTP, SIG_DFL);
    ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
    return;
}

static void     signal_ign(int sig)
{
    if ((sig >= SIGCHLD && sig <= SIGUSR2) || sig == SIGURG)
	    signal(sig, SIG_IGN);
    return;
}

static void     signal_fatal(int sig)
{
    if (sig >= SIGHUP && sig <= SIGFPE)
    {
        free_data();
        close_termios();
        if (sig == SIGHUP)
            exit(print_error(SIG_SIGHUP));
        if (sig == SIGINT)
            exit(print_error(SIG_SIGINT));
        if (sig == SIGQUIT)
            exit(print_error(SIG_SIGQUIT));
        if (sig == SIGILL)
            exit(print_error(SIG_SIGILL));
        if (sig == SIGTRAP)
            exit(print_error(SIG_SIGTRAP));
        if (sig == SIGABRT)
            exit(print_error(SIG_SIGABRT));
        if (sig == SIGEMT)
            exit(print_error(SIG_SIGEMT));
        if (sig == SIGFPE)
            exit(print_error(SIG_SIGFPE));
        exit(0);
    }
    return;   
}

static void     signal_fatal2(int sig)
{
    if (sig >= SIGKILL && sig <= SIGTERM)
    {
        free_data();
        close_termios();
        if (sig == SIGKILL)
            exit(print_error(SIG_SIGKILL));
        if (sig == SIGBUS)
            exit(print_error(SIG_SIGBUS));
        if (sig == SIGSEGV)
            exit(print_error(SIG_SIGSEGV));
        if (sig == SIGSYS)
            exit(print_error(SIG_SIGSYS));
        if (sig == SIGTERM)
            exit(print_error(SIG_SIGTERM));
        exit(0);
    }
    return;   
}

void    signal_handler2()
{
    signal(SIGURG, signal_ign);
    signal(SIGCHLD, signal_ign);
    signal(SIGTTIN, signal_ign);
    signal(SIGTTOU, signal_ign);
    signal(SIGIO, signal_ign);
    signal(SIGXCPU, signal_ign);
    signal(SIGXFSZ, signal_ign);
    signal(SIGVTALRM, signal_ign);
    signal(SIGPROF, signal_ign);
    signal(SIGWINCH, signal_ign);
    signal(SIGINFO, signal_ign);
    signal(SIGUSR1, signal_ign);
    signal(SIGUSR2, signal_ign);
    return;
}

void    signal_handler(void)
{
    signal(SIGWINCH, get_sigwinch);
	signal(SIGCONT, get_sigcont);
    signal(SIGTSTP, get_sigtstp);
    signal(SIGHUP, signal_fatal);
    signal(SIGINT, signal_fatal);
    signal(SIGQUIT, signal_fatal);
    signal(SIGILL, signal_fatal);
    signal(SIGTRAP, signal_fatal);
    signal(SIGABRT, signal_fatal);
    signal(SIGEMT, signal_fatal);
    signal(SIGFPE, signal_fatal);
    signal(SIGKILL, signal_fatal2);
    signal(SIGBUS, signal_fatal2);
    signal(SIGSEGV, signal_fatal2);
    signal(SIGSYS, signal_fatal2);
    signal(SIGPIPE, signal_fatal2);
    signal(SIGALRM, signal_fatal2);
    signal(SIGTERM, signal_fatal2);
    signal_handler2();
    return;
}
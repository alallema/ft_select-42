/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:53:47 by alallema          #+#    #+#             */
/*   Updated: 2020/03/05 16:12:06 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void		signal_fatal(int sig)
{
	if (sig >= SIGHUP && sig <= SIGFPE)
	{
		if (sig == SIGHUP)
			exit_program_error(SIG_SIGHUP);
		if (sig == SIGINT)
			exit_program_error(SIG_SIGINT);
		if (sig == SIGQUIT)
			exit_program_error(SIG_SIGQUIT);
		if (sig == SIGILL)
			exit_program_error(SIG_SIGILL);
		if (sig == SIGTRAP)
			exit_program_error(SIG_SIGTRAP);
		if (sig == SIGABRT)
			exit_program_error(SIG_SIGABRT);
		if (sig == SIGEMT)
			exit_program_error(SIG_SIGEMT);
		if (sig == SIGFPE)
			exit_program_error(SIG_SIGFPE);
		exit(0);
	}
	return ;
}

static void		signal_fatal2(int sig)
{
	if (sig >= SIGKILL && sig <= SIGTERM)
	{
		if (sig == SIGKILL)
			exit_program_error(SIG_SIGKILL);
		if (sig == SIGBUS)
			exit_program_error(SIG_SIGBUS);
		if (sig == SIGSEGV)
			exit_program_error(SIG_SIGSEGV);
		if (sig == SIGSYS)
			exit_program_error(SIG_SIGSYS);
		if (sig == SIGTERM)
			exit_program_error(SIG_SIGTERM);
		exit(0);
	}
	return ;
}

static void		signal_ign(int sig)
{
	if ((sig >= SIGCHLD && sig <= SIGPROF) || sig == SIGURG
	|| (sig >= SIGINFO && sig <= SIGUSR2))
		signal(sig, SIG_IGN);
	return ;
}

static void		signal_handler2(void)
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
	signal(SIGINFO, signal_ign);
	signal(SIGUSR1, signal_ign);
	signal(SIGUSR2, signal_ign);
	return ;
}

void			signal_handler(void)
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
	return ;
}

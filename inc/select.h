/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:45:51 by alallema          #+#    #+#             */
/*   Updated: 2020/03/05 16:05:51 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <curses.h>
# include <termios.h>
# include <term.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include "libft.h"

/*
** keyboard keys
*/
# define LEFT  4479771
# define RIGHT  4414235
# define UP  4283163
# define DOWN  4348699
# define ESC  27
# define SPACE  32
# define DEL  127
# define RETR  10
# define SUP  2117294875
# define HOME  4741915
# define END  4610843
# define PAGE_UP  2117425947
# define PAGE_DOWN  2117491483
# define TAB  9
# define CRTL  1
# define CTRL_D  4
# define RET_CTRL_D  147

# define CTRL_B 2
# define CTRL_E 5
# define CTRL_K 11
# define CTRL_W 23
# define CTRL_L 12
# define CTRL_N 14
# define CTRL_A 1
# define CTRL_F 6
# define CTRL_P 16

# define CTRL_Y 16
# define CTRL_T 20
# define ALT_C  42947
# define ALT_V  10127586
# define ALT_X  8948194
# define ALT_RIGHT  1130044187
# define ALT_LEFT  1146821403
# define ALT_UP 1096489755
# define ALT_DOWN 1113266971

/*
** color
*/

typedef enum	e_enum
{
	RED,
	PIN,
	BLU,
	PUR,
	PRR,
	GRE,
	YEL,
	STD,
	BLK,
}				t_enum;

# define COLOR_NB 8

/*
** signal
*/
# define SIG_SIGHUP   "Receive Signal : terminal line hangup"
# define SIG_SIGINT   "Receive Signal : interrupt program"
# define SIG_SIGQUIT  "Receive Signal : quit program"
# define SIG_SIGILL   "Receive Signal : illegal instruction"
# define SIG_SIGTRAP  "Receive Signal : trace trap"
# define SIG_SIGABRT  "Receive Signal : abort program (formerly SIGIOT)"
# define SIG_SIGEMT   "Receive Signal : emulate instruction executed"
# define SIG_SIGFPE   "Receive Signal : floating-point exception"
# define SIG_SIGKILL  "Receive Signal : kill program"
# define SIG_SIGBUS   "Receive Signal : bus error"
# define SIG_SIGSEGV  "Receive Signal : segmentation violation"
# define SIG_SIGSYS   "Receive Signal : non-existent system call invoked"
# define SIG_SIGPIPE  "Receive Signal : write on a pipe with no reader"
# define SIG_SIGALRM  "Receive Signal : real-time timer expired"
# define SIG_SIGTERM  "Receive Signal : software termination signal"

/*
** error
*/
# define ERR_MALL "Memory error"
# define ERR_READ "Read error"
# define ERR_IOCTL "Ioctl error"

/*
** print format
*/
# define DEFAULT 	0
# define UNDERLINE 	1
# define HIGHTLIGHT 2
# define UNDERLIGHT 3

typedef struct	s_win
{
	int		ws_col;
	int		ws_row;
}				t_win;

typedef struct	s_lst
{
	int				i;
	int				key;
	char			*content;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

typedef struct	s_data
{
	int		len;
	int		len_max;
	int		col;
	int		row;
	char	*color;
	int		color_nb;
	t_lst	*list;
}				t_data;

typedef struct	s_term
{
	struct termios	old;
	struct termios	new;
}				t_term;

int				init_termios(void);
int				close_termios(void);
int				print_usage(void);
int				t_putchar(int i);
void			signal_handler(void);
void			get_window(void);
int				key_press(void);
void			print_key_stdout(int i);
int				print_error(char *err);
int				display(void);
t_data			*get_data(t_data *data);
int				stock_data(int ac, char **av);
void			free_data(void);
void			clear_elem(void);
void			check_iterator(t_data *data, int len);
void			exit_program_error(char *error);
void			exit_program(int ret);
void			change_color(int action);
void			return_result(void);
void			remove_underline_elem(t_lst *elem);
void			underline_elem(t_lst *elem);
int				compute_right(int i, int col, int row, int len);
int				compute_left(int i, int col, int row, int len);
int				brain_print(t_data *data, t_lst *elem, int i, int j);
void			get_sigwinch(int sig);
void			get_sigcont(int sig);
void			get_sigtstp(int sig);

#endif

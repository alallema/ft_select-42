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

# define ERR_MALL "Memory error"

typedef struct	s_win
{
	int		col;
	int		row;
	int		letter;
	int		elem;
}				t_win;

typedef struct	s_curs
{
	int 	col;
	int 	row;
	int 	win_col;
	int 	win_row;
}				t_curs;

typedef struct 	s_data
{
	int		len;
	int		len_max;
	char	**args;
}				t_data;

typedef struct	s_term
{
	struct termios	old;
	struct termios	new;
}				t_term;

int				init_termios(void);
int				close_termios(void);
int				t_putchar(int i);
void			signal_handler(void);
t_win			*get_window(void);
int				key_press(t_data *data);
void			print_key_stdout(int i);
int				print_error(char *err);
void			print_elem(char *s);

#endif
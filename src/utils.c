#include "select.h"

void    exit_program_error(char *error)
{
    close_termios();
    free_data();
    exit(print_error(error));
}

void    exit_program(int ret)
{
    close_termios();
    free_data();
    exit(ret);
}

void    check_iterator(t_data *data, int len)
{
    t_lst   *elem;
    int     i;

    i = 1;
    elem = data->list;
    while (elem)
    {
        elem->i = i;
        if (elem->i == len)
            break;
        elem = elem->next;
        i++;
    }
}

void    return_result(void)
{
    t_data  *data;
    t_lst  *elem;
    int     i;

    data = get_data(NULL);
    elem = data->list;
    close_termios();
    i = 0;
    while (elem)
    {
        if (elem->key == HIGHTLIGHT || elem->key == UNDERLIGHT)
        {
            if (i == 1)
                ft_putstr_fd(" ", STDOUT_FILENO);
            ft_putstr_fd(elem->content, STDOUT_FILENO);
            i = 1;
        }
        elem = elem->next;
        if (elem->i == data->len)
            break;
    }
    if (i == 1)
        ft_putstr_fd("\n", STDOUT_FILENO);
    free_data();
    exit(EXIT_SUCCESS);
}

t_data		*get_data(t_data *data)
{
    static t_data	*elem;

    if (!elem && !data)
        return (NULL);
	if (!data)
		return (elem);
	else
	{
		elem = data;
		return (elem);
	}
}
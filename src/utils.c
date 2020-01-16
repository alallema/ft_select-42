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
    // size_t  j;

    i = 1;
    // j = 0;
    elem = data->list;
    while (elem)
    {
        elem->i = i;
        // if (ft_strlen(elem->content) > j)
            // j = ft_strlen(elem->content);
        if (elem->i == len)
        {
            // data->len_max = j;
            break;
        }
        elem = elem->next;
        i++;
    }
}

void    return_result(void)
{
    t_data  *data;
    t_lst  *elem;

    data = get_data(NULL);
    elem = data->list;
    close_termios();
    while (elem)
    {
        if (elem->key == HIGHTLIGHT || elem->key == UNDERLIGHT)
        {
            ft_putstr_fd(elem->content, 1);
            ft_putstr_fd(" ", 1);
        }
        elem = elem->next;
        if (elem->i == data->len)
            break;
    }
    ft_putstr_fd("\n", 1);
    free_data();
    exit(EXIT_SUCCESS);
}
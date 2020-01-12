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

void    free_elem(t_lst *elem)
{
    ft_memdel((void *)&elem->content);
    ft_memdel((void *)&elem);
}

void    free_data(void)
{
    t_data  *data;
    t_lst   *elem;
    t_lst   *tmp;

    elem = NULL;
    tmp = NULL;
    data = get_data(NULL);
    if (!data)
        return ;
    elem = data->list;
    while (elem)
    {
        data->len = data->len - 1;
        if (data->len != 0)
            tmp = elem->next;
        else
            tmp = NULL;
        free_elem(elem);
        elem = tmp;
    }
    ft_memdel((void *)&data);
}

void    clear_elem(void)
{
    t_data  *data;
    t_lst   *elem;

    data = get_data(NULL);
    if (!data)
        return ;
    elem = data->list;
    while (elem)
    {
        if (elem->key == UNDERLINE || elem->key == UNDERLIGHT)
        {
            if (elem->next->key == DEFAULT)
				elem->next->key = UNDERLINE;
			else if (elem->next->key == HIGHTLIGHT)
				elem->next->key = UNDERLIGHT;
            elem->prev->next = elem->next;
            elem->next->prev = elem->prev;
            if (elem->i == 1)
                data->list = elem->next;
            free_elem(elem);
            break;
        }
        elem = elem->next;
    }
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
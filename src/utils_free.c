#include "select.h"

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
    // ft_memdel((void *)&data->color);
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
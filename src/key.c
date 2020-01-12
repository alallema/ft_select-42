#include "select.h"

static void		down_cursor(void)
{
	t_data *data;
	t_lst *elem;

	data = get_data(NULL);
	elem = data->list;
	while (elem)
	{
		if (elem->key == UNDERLINE || elem->key == UNDERLIGHT)
		{
			if (elem->key == UNDERLINE)
				elem->key = DEFAULT;
			else if (elem->key == UNDERLIGHT)
				elem->key = HIGHTLIGHT;
			if (elem->next->key == DEFAULT)
				elem->next->key = UNDERLINE;
			else if (elem->next->key == HIGHTLIGHT)
				elem->next->key = UNDERLIGHT;
			break;
		}
		elem = elem->next;
	}
	brain_print();
}

static void		up_cursor(void)
{
	t_data 	*data;
	t_lst 	*elem;

	data = get_data(NULL);
	elem = data->list;
	while (elem)
	{
		if (elem->key == UNDERLINE || elem->key == UNDERLIGHT)
		{
			if (elem->key == UNDERLINE)
				elem->key = DEFAULT;
			else if (elem->key == UNDERLIGHT)
				elem->key = HIGHTLIGHT;
			if (elem->prev->key == DEFAULT)
				elem->prev->key = UNDERLINE;
			else if (elem->prev->key == HIGHTLIGHT)
				elem->prev->key = UNDERLIGHT;
			break;
		}
		elem = elem->next;
	}
	brain_print();
}

static void		select_cursor(void)
{
	t_data 	*data;
	t_lst 	*elem;

	data = get_data(NULL);
	elem = data->list;
	while (elem)
	{
		if (elem->key == UNDERLINE)
			elem->key = UNDERLIGHT;
		else if (elem->key == UNDERLIGHT)
			elem->key = UNDERLINE;
		if (elem->i == data->len)
			break;
		elem = elem->next;
	}
	down_cursor();
}

static void    delete_cursor(void)
{
    t_data  *data;

    data = get_data(NULL);
    if (data->len == 1)
        exit_program(EXIT_SUCCESS);
    data->len = data->len - 1;
    clear_elem();
    check_iterator(data, data->len);
    brain_print();
}

int			key_press(void)
{
	unsigned int	x;

	while (1)
	{
		x = 0;
		if (read(STDERR_FILENO, (char *)(unsigned long)&x, 4) < 0)
			exit_program_error(ERR_READ);
		if (x == CTRL_D || x == ESC || x == RETR)
			exit_program(EXIT_SUCCESS);
		if (x == DOWN)
			down_cursor();
		if (x == UP)
			up_cursor();
		if (x == SPACE)
			select_cursor();
		if (x == DEL || x == SUP)
			delete_cursor();
		if (x == TAB || x == ALT_C)
			change_color(x);
	}
	return (EXIT_SUCCESS);
}
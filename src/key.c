#include "select.h"

void		down_cursor(void)
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

void		up_cursor(void)
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

void		select_cursor(void)
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
		if (elem->i == data->len - 1)
			break;
		elem = elem->next;
	}
	down_cursor();
}

int			key_press(void)
{
	unsigned int	x;

	while (1)
	{
		x = 0;
		read(0, (char *)(unsigned long)&x, 4);
		if (x == CTRL_D || x == ESC || x == RETR)
		{
			close_termios();
			exit(EXIT_SUCCESS);
		}
		if (x == DOWN)
			down_cursor();
		if (x == UP)
			up_cursor();
		if (x == SPACE)
			select_cursor();
		// if (x == DEL || x == SUP)
		// 	ft_clear_elem();
	}
	return (EXIT_SUCCESS);
}
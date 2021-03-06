/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:48:50 by alallema          #+#    #+#             */
/*   Updated: 2020/03/05 16:19:59 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void		side_cursor(int x)
{
	t_data	*data;
	t_lst	*elem;
	int		i;

	data = get_data(NULL);
	elem = data->list;
	i = 0;
	while (elem)
	{
		if (elem->key == UNDERLINE || elem->key == UNDERLIGHT)
		{
			if (x == RIGHT)
				i = compute_right(elem->i, data->col, data->row, data->len);
			else if (x == LEFT)
				i = compute_left(elem->i, data->col, data->row, data->len);
			remove_underline_elem(elem);
		}
		if (elem->i == i)
		{
			underline_elem(elem);
			break ;
		}
		elem = elem->next;
	}
	display();
	return ;
}

static void		move_cursor(int x)
{
	t_data	*data;
	t_lst	*elem;

	data = get_data(NULL);
	elem = data->list;
	while (elem)
	{
		if (elem->key == UNDERLINE || elem->key == UNDERLIGHT)
		{
			remove_underline_elem(elem);
			if (x == DOWN)
				underline_elem(elem->next);
			if (x == UP)
				underline_elem(elem->prev);
			break ;
		}
		elem = elem->next;
	}
	display();
}

static void		select_cursor(void)
{
	t_data	*data;
	t_lst	*elem;

	data = get_data(NULL);
	elem = data->list;
	while (elem)
	{
		if (elem->key == UNDERLINE)
			elem->key = UNDERLIGHT;
		else if (elem->key == UNDERLIGHT)
			elem->key = UNDERLINE;
		if (elem->i == data->len)
			break ;
		elem = elem->next;
	}
	move_cursor(DOWN);
}

static void		delete_cursor(void)
{
	t_data	*data;

	data = get_data(NULL);
	if (data->len == 1)
		exit_program(EXIT_SUCCESS);
	data->len = data->len - 1;
	clear_elem();
	check_iterator(data, data->len);
	display();
}

int				key_press(void)
{
	unsigned int	x;

	while (1)
	{
		x = 0;
		if (read(STDERR_FILENO, (char *)(unsigned long)&x, 4) < 0)
			exit_program_error(ERR_READ);
		if (x == CTRL_D || x == ESC)
			exit_program(EXIT_SUCCESS);
		if (x == DOWN || x == UP)
			move_cursor(x);
		if (x == SPACE)
			select_cursor();
		if (x == DEL || x == SUP)
			delete_cursor();
		if (x == TAB || x == ALT_C)
			change_color(x);
		if (x == RETR)
			return_result();
		if (x == LEFT || x == RIGHT)
			side_cursor(x);
	}
	return (EXIT_SUCCESS);
}

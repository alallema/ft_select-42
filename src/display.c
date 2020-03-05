/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:48:12 by alallema          #+#    #+#             */
/*   Updated: 2020/03/05 16:08:01 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	print_elem(char *s, char *color)
{
	ft_putstr_fd(color, STDERR_FILENO);
	ft_putendl_fd(s, STDERR_FILENO);
	ft_putstr_fd("\033[0;39m", STDERR_FILENO);
}

static void	print_underline(char *s, char *color)
{
	tputs(tgetstr("us", NULL), 1, t_putchar);
	ft_putstr_fd(color, STDERR_FILENO);
	ft_putendl_fd(s, STDERR_FILENO);
	tputs(tgetstr("ue", NULL), 1, t_putchar);
}

static void	print_hightlight(char *s, char *color)
{
	tputs(tgetstr("so", NULL), 1, t_putchar);
	ft_putstr_fd(color, STDERR_FILENO);
	ft_putendl_fd(s, STDERR_FILENO);
	tputs(tgetstr("se", NULL), 1, t_putchar);
}

static void	print_underlight(char *s, char *color)
{
	tputs(tgetstr("so", NULL), 1, t_putchar);
	tputs(tgetstr("us", NULL), 1, t_putchar);
	ft_putstr_fd(color, STDERR_FILENO);
	ft_putendl_fd(s, STDERR_FILENO);
	tputs(tgetstr("se", NULL), 1, t_putchar);
	tputs(tgetstr("ue", NULL), 1, t_putchar);
}

int			brain_print(t_data *data, t_lst *elem, int i, int j)
{
	while (elem)
	{
		tputs(tgoto(tgetstr("cm", NULL), i, j), 1, t_putchar);
		if (elem->key == DEFAULT)
			print_elem(elem->content, data->color);
		if (elem->key == UNDERLINE)
			print_underline(elem->content, data->color);
		if (elem->key == HIGHTLIGHT)
			print_hightlight(elem->content, data->color);
		if (elem->key == UNDERLIGHT)
			print_underlight(elem->content, data->color);
		if (elem->i == data->len)
			break ;
		elem = elem->next;
		j++;
		if (j == data->row)
		{
			i = i + data->len_max + 2;
			j = 0;
		}
	}
	return (EXIT_SUCCESS);
}

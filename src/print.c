/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:53:19 by alallema          #+#    #+#             */
/*   Updated: 2020/03/05 16:11:38 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		t_putchar(int i)
{
	write(STDERR_FILENO, &i, 1);
	return (0);
}

int		print_error(char *err)
{
	ft_putendl_fd(err, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int		print_usage(void)
{
	ft_putendl_fd("usage: ./ft_select [args]\n\
	⬅︎  ➡︎ ⬆︎ ⬇︎ move cursor with arrow direction\n\
	TAB change color\n\
	SPACE select item", STDERR_FILENO);
	return (EXIT_SUCCESS);
}

int		display(void)
{
	t_lst	*elem;
	t_data	*data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	data = get_data(NULL);
	elem = data->list;
	tputs(tgetstr("cl", NULL), 1, t_putchar);
	if (data->col == 0 && data->row == 0)
	{
		ft_putendl_fd("Too small", STDERR_FILENO);
		return (EXIT_SUCCESS);
	}
	brain_print(data, elem, i, j);
	return (EXIT_SUCCESS);
}

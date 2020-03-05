/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:40:22 by alallema          #+#    #+#             */
/*   Updated: 2020/03/05 16:11:13 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int			main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac < 2)
		return (print_usage());
	signal_handler();
	if (stock_data(ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data = get_data(data);
	get_window();
	if (init_termios() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	display();
	key_press();
	close_termios();
	free_data();
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cursor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:59:53 by alallema          #+#    #+#             */
/*   Updated: 2020/03/05 16:15:23 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	remove_underline_elem(t_lst *elem)
{
	if (elem->key == UNDERLINE)
		elem->key = DEFAULT;
	else if (elem->key == UNDERLIGHT)
		elem->key = HIGHTLIGHT;
	return ;
}

void	underline_elem(t_lst *elem)
{
	if (elem->key == DEFAULT)
		elem->key = UNDERLINE;
	else if (elem->key == HIGHTLIGHT)
		elem->key = UNDERLIGHT;
	return ;
}

int		compute_right(int i, int col, int row, int len)
{
	int		j;

	(void)col;
	j = 0;
	if (i != 0 && i + row <= len)
	{
		j = i + row;
		if (j > len)
			j = j - row;
	}
	else
		j = i % row;
	if (j == 0)
		j = row;
	return (j);
}

int		compute_left(int i, int col, int row, int len)
{
	int		j;

	j = 0;
	if (i != 0 && i > row)
		j = i - row;
	else
	{
		j = ((col - 1) * row) + i;
		if (j > len)
			j = j - row;
	}
	return (j);
}

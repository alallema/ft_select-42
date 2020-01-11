/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:38:49 by alallema          #+#    #+#             */
/*   Updated: 2018/12/12 23:39:02 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_nbrlen(long n, int base)
{
	long	length;

	length = 0;
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n > 0)
	{
		n = n / base;
		length++;
	}
	return (length);
}

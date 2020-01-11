/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <alallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 22:25:45 by alallema          #+#    #+#             */
/*   Updated: 2018/12/12 23:43:09 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reverse(char *str)
{
	char	buf;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (!str || len < 2)
		return ;
	while (i < (len / 2))
	{
		buf = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = buf;
		i++;
	}
}

char	*ft_itoa_base(long n, int base)
{
	char	*str;
	int		i;
	int		length;

	if (base == 10)
		return (ft_itoa(n));
	length = ft_nbrlen(n, base);
	str = (char*)malloc(sizeof(*str) * (length + 1));
	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (i < length)
	{
		if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + 'a';
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	reverse(str);
	return (str);
}

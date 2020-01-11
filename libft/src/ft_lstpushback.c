/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 18:11:44 by alallema          #+#    #+#             */
/*   Updated: 2016/04/21 19:05:57 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, void const *content, size_t size, int i)
{
	t_list	*elem;

	elem = *alst;
	if (*alst != NULL)
	{
		while (elem->next)
			elem = elem->next;
	}
	elem->next = ft_lstnew(content, size, i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:06:19 by alallema          #+#    #+#             */
/*   Updated: 2015/12/02 17:40:49 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charsplit(char *s, char c, int j)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (len < j && s[len])
	{
		if (s[len] != c && len < j && s[len])
		{
			while (s[len] != c && len < j && s[len])
				len++;
			i++;
		}
		while (s[len] == c && len < j && s[len])
			len++;
	}
	return (i);
}

static char	**ft_tab(char **tab, const char *s, int len, char c)
{
	int		letter;
	int		i;

	letter = 0;
	i = 0;
	while (len > 0 && *s)
	{
		tab[i] = (char *)malloc(sizeof(char) * (len + 1));
		while (*s != c && len > 0)
		{
			tab[i][letter++] = (const char)*s;
			len--;
			s++;
		}
		while (*s == c && *s)
			s++;
		tab[i][letter] = '\0';
		letter = 0;
		i++;
	}
	tab[i] = (char *)malloc(sizeof(char));
	tab[i] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		len;
	int		i;
	int		letter;
	char	**tab;

	len = 0;
	letter = 0;
	len = ft_strlen((char *)s);
	i = ft_charsplit((char *)s, c, len);
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (tab == NULL)
		return (NULL);
	tab[0] = NULL;
	if (!s || !c || !len)
		return (tab);
	while (*s == c)
		s++;
	tab = ft_tab(tab, s, len, c);
	return (tab);
}

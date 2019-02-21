/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 02:37:25 by ppetitea          #+#    #+#             */
/*   Updated: 2018/11/14 05:50:12 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char *s, char c)
{
	int		wc;
	size_t	i;

	i = 0;
	wc = 0;
	if (s[i] && s[i] != c)
		wc++;
	while (s[i])
	{
		wc += (s[i] == c && s[i + 1] != c) ? 1 : 0;
		if (s[i] == c)
			s[i] = '\0';
		i++;
	}
	if (i > 0 && s[i - 1] == '\0')
		wc--;
	return (wc);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	char	*ss;
	int		wc;
	int		i;

	if (!(ss = ft_strdup(s)))
		return (NULL);
	wc = ft_word_count(ss, c);
	if (!(t = (char**)malloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	i = 0;
	while (i < wc)
	{
		if (*ss)
		{
			if (!(t[i] = ft_strdup(ss)))
				return (NULL);
			ss += ft_strlen(ss) + 1;
			i++;
		}
		else
			ss++;
	}
	t[wc] = NULL;
	return (t);
}

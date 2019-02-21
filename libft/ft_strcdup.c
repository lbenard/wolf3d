/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:18:50 by ppetitea          #+#    #+#             */
/*   Updated: 2019/01/24 20:23:57 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(char *string, char c)
{
	char	*new_string;
	int		lenght;
	int		i;

	i = 0;
	lenght = ft_strlen(string);
	if (!string)
		return (NULL);
	if (!(new_string = malloc(sizeof(char) * lenght)))
		return (NULL);
	while (*string && *string != c)
	{
		new_string[i] = *string;
		string++;
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

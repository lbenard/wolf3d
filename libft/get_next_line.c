/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:18:50 by ppetitea          #+#    #+#             */
/*   Updated: 2019/01/24 20:27:14 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	fill_next_line(int fd, int *ret, char **line)
{
	static char		*lines = NULL;
	static int		i = 0;
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	int				size;
	
	size = 42;
	while (size > 0 && !contains_char(&lines[i], '\n'))
	{
		size = read(fd, buffer, BUFF_SIZE);
		buffer[size] = '\0';
		temp = ft_strjoin(lines, buffer);
		if (lines)
			free(lines);
		lines = temp;
	}
	*line = ft_strcdup(&lines[i], '\n');
	i += ft_strlen(*line);
	if (lines[i])
		i++;
	else
		*ret = 0;
}

int		get_next_line(const int fd, char **line)
{
	int		ret;

	ret = 1;
	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	fill_next_line(fd, &ret, line);
	return (ret);
}

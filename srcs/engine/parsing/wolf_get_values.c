/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_get_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:17:22 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/26 19:16:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/parsing.h"
#include "engine/error.h"
#include "ft/str.h"

char	**wolf_get_values(char *kv_line, char split)
{
	char	*value;
	char	**values;

	if (!(value = wolf_get_value(kv_line)))
		return (throw_error_str("wolf_get_values()", "failed to get value"));
	if (!(values = ft_strsplit(value, split)))
	{
		free(value);
		return (throw_error_str("wolf_get_values()", "failed to split values"));
	}
	free(value);
	return (values);
}
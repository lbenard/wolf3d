/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_is_line_correct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:14:10 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/25 18:56:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/parsing.h"
#include "engine/error.h"

t_result	wolf_is_line_correct(char *line)
{
	if (!line)
		return (throw_result_str("wolf_is_line_correct(): ""invalid line"));
	if (*line == '\0')
		return (OK);
	else if (*line == '-')
		return (wolf_is_flag_correct(line));
	else if (wolf_is_kv_correct(line, '\0'))
		return (OK);
	else
		return (ERROR);
}
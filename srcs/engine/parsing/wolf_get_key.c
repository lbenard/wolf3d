/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_get_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:06:09 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 12:56:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/parsing.h"
#include "ft/str.h"

char	*wolf_get_key(char *kv_line)
{
	return (ft_strndup(kv_line, ft_strstr(kv_line, ": ") - kv_line));
}

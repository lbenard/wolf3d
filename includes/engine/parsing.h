/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:18:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 17:59:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <string.h>
# include "types.h"

/*
** Wolf data file parsing utilities
*/
char		*wolf_read_file(const char *path);

t_result	wolf_is_flag_correct(char *line);
t_result	wolf_is_kv_correct(char *line, char end);
t_result	wolf_is_line_correct(char *line);

char		*wolf_new_flag(char *flag_name);
char		*wolf_select_flag(char *map_str, char *flag_name);

char		*wolf_get_key(char *wolf_data_line);

char		*wolf_get_value(char *wolf_data_line);
char		**wolf_get_values(char *wolf_data_line, char split);
void		wolf_free_values(char **values);

size_t		wolf_strsplit_length(char **strings);

#endif

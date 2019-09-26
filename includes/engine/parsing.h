/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:18:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/25 17:58:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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

// char	*add_newline(char *text)

// char	*join_next_line(char *text, char *next_line)


#endif
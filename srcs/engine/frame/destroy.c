/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:29:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/08 15:49:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/frame.h"

void	destroy_frame(t_frame *const self)
{
	free(self->frame);
	destroy_module(&self->module);
}

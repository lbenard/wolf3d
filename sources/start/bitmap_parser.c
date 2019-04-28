/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:20:33 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/28 19:18:44 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/bitmap.h"

static uint32_t		bgr_to_int_pixel(unsigned char *bgr_pixel)
{
	return (256 * 256 * bgr_pixel[2] + 256 * bgr_pixel[1] + bgr_pixel[0]);
}

static int			fill_image_pixels(t_bitmap_image *bmp, FILE *file)
{
	unsigned char	bgr_pixel[3];
	int				h_i;
	int				w_i;
	int				h;
	int				w;

	h = bmp->head.height;
	w = bmp->head.width;
	h_i = -1;
	while (++h_i < h)
	{
		w_i = -1;
		while (++w_i < w)
		{
			if (!fread(&bgr_pixel, 1, 3, file))
				return (-1);
			bmp->pixels[w_i + (h - h_i - 1) * w] = bgr_to_int_pixel(bgr_pixel);
		}
		fseek(file, w % 4, SEEK_CUR);
	}
	return (0);
}

t_bitmap_image		*bitmap_parser(char *bmp_pathname)
{
	t_bitmap_image		*bmp;
	FILE				*file;

	file = NULL;
	if (!(bmp = malloc(sizeof(t_bitmap_image))))
		return (NULL);
	if (!(file = fopen(bmp_pathname, "rb")))
		return (NULL);
	if (!fread(&bmp->head, sizeof(t_bitmap_header), 1, file))
		return (NULL);
	if (!(bmp->pixels = malloc(sizeof(uint32_t) * (bmp->head.width
		* bmp->head.height))))
		return (NULL);
	fseek(file, bmp->head.offset, SEEK_SET);
	if (fill_image_pixels(bmp, file))
		return (NULL);
	return (bmp);
}

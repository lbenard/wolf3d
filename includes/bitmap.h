/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:25:54 by ppetitea          #+#    #+#             */
/*   Updated: 2019/03/28 18:09:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H
# pragma pack(push)
# pragma pack(1)

typedef int				int32_t;
typedef short			int16_t;
typedef int				int32_t;
typedef unsigned int	uint32_t;
typedef unsigned short	uint16_t;

typedef struct 		s_bitmap_header
{
	char			type[2];
	uint32_t		size;
	uint16_t		reserved1;
	uint16_t		reserved2;
	uint32_t 		offset;
	uint32_t		header_size;
	int32_t			width;
	int32_t			height;
	uint16_t		num_planes;
	uint16_t		bits_per_pixel;
	uint32_t		compression;
	uint32_t		image_size_bytes;
	int32_t			x_resolution_ppm;
	int32_t			y_resolution_ppm;
	uint32_t		num_colors;
	uint32_t		important_colors;
}					t_bitmap_header;

# pragma pack(pop)

typedef struct		s_bitmap_image
{
    t_bitmap_header head;
    uint32_t		*pixels;
}					t_bitmap_image;

t_bitmap_image		*bitmap_parser(char *bmp_pathname);

#endif

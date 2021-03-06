/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/08 16:08:41 by dvan-boc       #+#    #+#                */
/*   Updated: 2019/12/17 18:11:47 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_event(enum e_keys key, struct s_param *ptr)
{
	if (key == ESC)
		close_frame(ptr);
	if (key == LEFT)
		ptr->beta -= 0.087;
	if (key == RIGHT)
		ptr->beta += 0.087;
	if (key == DOWN)
		ptr->alpha += 0.087;
	if (key == UP)
		ptr->alpha -= 0.087;
	if (key == A)
		ptr->gamma -= 0.087;
	if (key == D)
		ptr->gamma += 0.087;
	if (key == PLUS || key == PLUS_NUM)
		ptr->tile_size += 1;
	if ((key == MINUS || key == MINUS_NUM) && ptr->tile_size > 1)
		ptr->tile_size -= 1;
	mlx_destroy_image(ptr->mlx_ptr, ptr->img);
	draw_map(ptr);
	return (0);
}

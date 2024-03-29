/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:42:17 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/20 13:39:02 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

t_rect	get_rect(int x, int y, int dx, int dy)
{
	t_rect	newrect;

	newrect.y = y;
	newrect.dy = dy;
	newrect.x = x;
	newrect.dx = dx;
	return (newrect);
}

void	draw_bot(t_data *data, t_rect a)
{
	int	y;
	int	x;

	y = a.y + a.dy;
	while (y < data->window_height)
	{
		data->alpha -= 1;
		if (data->alpha < 0)
			data->alpha = 0;
		x = a.x;
		while (x < a.x + a.dx)
			my_mlx_pixel_put(data, x++, y, data->f_color);
		y++;
	}
}

void	draw_top(t_data *data, t_rect a)
{
	int	y;
	int	x;

	y = 0;
	while (y < a.y)
	{
		x = a.x;
		while (x < a.x + a.dx)
			my_mlx_pixel_put(data, x++, y, data->c_color);
		y++;
	}
}

void	draw_wall(t_data *data, t_rect rect, int idx)
{
	int	i;
	int	j;
	int	x_offset;
	int	y_offset;
	int	max;

	max = rect.y + rect.dy;
	i = rect.y;
	if (i < 0)
		i = -1;
	init_offset(data, &x_offset, idx, &max);
	while (++i < max)
	{
		y_offset = (i - rect.y) * ((double)TILE_SIZE / rect.dy);
		if (y_offset > TILE_SIZE)
			y_offset = TILE_SIZE;
		j = rect.x;
		while (j < rect.x + rect.dx)
		{
			if (i >= 0 && i < data->window_height)
				my_mlx_pixel_put(data, j, i,
					get_wall_color(data, idx, x_offset, y_offset));
			j++;
		}
	}
}

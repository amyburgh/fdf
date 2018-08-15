/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:21:44 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:42:28 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "fdf.h"
#include "mlx.h"

static void	map_step(t_map *map)
{
	double	step;

	step = IMG1_X / sqrt(pow(map->width - 1, 2) + pow(map->height - 1, 2));
	while ((map->height - 1) * step > IMG1_Y)
		step--;
	map->step = (int)step;
	map->step = map->step - map->step % 10;
	if (map->step < 10)
		map->step = 10;
}

static void	init_xy(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->tab[i][j].x = map->start_x + map->step * j;
			map->tab[i][j].y = map->start_y + map->step * i;
		}
	}
}

static void	map_start(t_map *map)
{
	map->start_x = (IMG1_X -
			ABS(map->tab[0][map->width - 1].x - map->tab[0][0].x)) / 2;
	map->start_y = (IMG1_Y -
			ABS(map->tab[map->height - 1][0].y - map->tab[0][0].y)) / 2;
}

int			render(t_rt *root)
{
	clear_image(root->img1, 1);
	map_step(root->map);
	init_xy(root->map);
	map_start(root->map);
	perspective_calc(root->map, root->cam, -1);
	draw_map(root->map, root, root->mouse->color);
	clear_image(root->img2, 2);
	image_pallet(root->img2, root->colors);
	if (root->mouse->active == 1)
	{
		color_select(root, 0, 0);
		rotation_select(root->cam, root->mouse);
		rotation_adj(root->cam, root->mouse);
	}
	mlx_put_image_to_window(root->mlx, root->win, root->img1->ptr, 0, 0);
	mlx_put_image_to_window(root->mlx, root->win, root->img2->ptr,
			(WIN_X - IMG2_X) / 2, WIN_Y - IMG2_Y - BD);
	mlx_put_image_to_window(root->mlx, root->win, root->img_m->ptr, BD, BD);
	mlx_put_image_to_window(root->mlx, root->win, root->img_a->ptr,
			WIN_X - 110, BD);
	display_info(root);
	return (0);
}

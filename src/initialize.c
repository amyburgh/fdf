/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 13:10:44 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:44:52 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void		init_map(t_map *map)
{
	map->title = NULL;
	map->width = 0;
	map->height = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->tab = NULL;
}

void		init_cam(t_cam *cam)
{
	cam->ex = WIN_X / 2;
	cam->ey = WIN_Y / 2;
	cam->ez = 100;
	cam->cx = 0;
	cam->cy = 0;
	cam->cz = 0;
	cam->ax = 0;
	cam->ay = 0;
	cam->az = 0;
	cam->adj = 0.2;
	cam->scale = 1;
	cam->n = 1;
}

void		init_mouse(t_mouse *mouse)
{
	mouse->active = 0;
	mouse->color = WHITE;
	mouse->x = WIN_X / 2;
	mouse->y = WIN_Y / 2;
	mouse->oldx = WIN_X / 2;
	mouse->oldy = WIN_Y / 2;
}

static void	init_colors(int *colors)
{
	colors[0] = BLACK;
	colors[1] = WHITE;
	colors[2] = RED;
	colors[3] = YELLOW;
	colors[4] = GREEN;
	colors[5] = PINK;
	colors[6] = BLUE;
	colors[7] = AQUA;
}

int			init_all(t_rt *root)
{
	t_cam		*cam;
	t_mouse		*mouse;
	int			*colors;

	MCHECK(!(cam = (t_cam*)ft_memalloc(sizeof(t_cam))));
	MCHECK(!(mouse = (t_mouse*)ft_memalloc(sizeof(t_mouse))));
	MCHECK(!(colors = (int*)ft_memalloc(sizeof(int) * 8)));
	init_cam(cam);
	init_mouse(mouse);
	init_colors(colors);
	root->cam = cam;
	root->mouse = mouse;
	root->colors = colors;
	return (0);
}

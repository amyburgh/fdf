/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:48:50 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:43:18 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <math.h>

void		ft_tabdel(void **tab, size_t rows)
{
	size_t	i;

	if (!tab || !rows)
		return ;
	i = -1;
	while (++i < rows)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}

void		rotation_adj(t_cam *cam, t_mouse *mouse)
{
	if (mouse->x > WIN_X - 90 && mouse->x < WIN_X - 30)
	{
		if (mouse->y > 25 && mouse->y < 85)
			cam->ey -= 100;
		else if (mouse->y > 85 && mouse->y < 145)
			cam->ey += 100;
		else if (mouse->y > 155 && mouse->y < 215)
			cam->ex += 100;
		else if (mouse->y > 215 && mouse->y < 275)
			cam->ex -= 100;
	}
}

void		rotation_select(t_cam *cam, t_mouse *mouse)
{
	if (mouse->x > WIN_X - 90 && mouse->x < WIN_X - 30)
	{
		if (mouse->y > 25 && mouse->y < 85)
			cam->ax += 0.005;
		else if (mouse->y > 85 && mouse->y < 145)
			cam->ax -= 0.005;
		else if (mouse->y > 155 && mouse->y < 215)
			cam->ay += 0.005;
		else if (mouse->y > 215 && mouse->y < 275)
			cam->ay -= 0.005;
		else if (mouse->y > 285 && mouse->y < 345)
			cam->az += 0.5;
		else if (mouse->y > 345 && mouse->y < 405)
			cam->az -= 0.5;
	}
}

static void	angles(t_calc *m, t_cam *cam)
{
	m->cx = cos(RAD(cam->ax));
	m->cy = cos(RAD(cam->ay));
	m->cz = cos(RAD(cam->az));
	m->sx = sin(RAD(cam->ax));
	m->sy = sin(RAD(cam->ay));
	m->sz = sin(RAD(cam->az));
}

void		perspective_calc(t_map *map, t_cam *cam, int i)
{
	t_calc	m;
	int		j;

	angles(&m, cam);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			m.x = map->tab[i][j].x - cam->cx;
			m.y = map->tab[i][j].y - cam->cy;
			m.z = map->tab[i][j].z * cam->adj - cam->cz;
			m.dx = m.cy * (m.sz * m.y + m.cz * m.x) - m.sy * m.z;
			m.dy = m.sx * (m.cy * m.z + m.sy * (m.sz * m.y + m.cz * m.x))
				+ m.cx * (m.cz * m.y - m.sz * m.x);
			m.dz = m.cx * (m.cy * m.z + m.sy * (m.sz * m.y + m.cz * m.x))
				- m.sx * (m.cz * m.y - m.sz * m.x);
			map->tab[i][j].x = (m.dx - (cam->ex / cam->ez) * m.dz) /
				(cam->scale - (1 / cam->ez) * m.dz);
			map->tab[i][j].y = (m.dy - (cam->ey / cam->ez) * m.dz) /
				(cam->scale - (1 / cam->ez) * m.dz);
		}
	}
}

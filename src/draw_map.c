/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:07:01 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:29:14 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	zoom(t_rt *root, int button)
{
	if (button == 4)
		root->cam->cz += (root->cam->n += 0.5);
	else if (button == 5)
		root->cam->cz -= (root->cam->n += 0.5);
}

void	translate(t_rt *root)
{
	if (root->mouse->button == 1)
	{
		if (root->mouse->oldx > root->mouse->x)
			root->cam->cx += ABS(root->mouse->oldx - root->mouse->x);
		else
			root->cam->cx -= ABS(root->mouse->oldx - root->mouse->x);
		if (root->mouse->oldy > root->mouse->y)
			root->cam->cy += ABS(root->mouse->oldy - root->mouse->y);
		else
			root->cam->cy -= ABS(root->mouse->oldy - root->mouse->y);
	}
	else if (root->mouse->button == 2)
	{
		if (root->mouse->oldx > root->mouse->x)
			root->cam->ex += 2 * ABS(root->mouse->oldx - root->mouse->x);
		else
			root->cam->ex -= 2 * ABS(root->mouse->oldx - root->mouse->x);
		if (root->mouse->oldy > root->mouse->y)
			root->cam->ey += 2 * ABS(root->mouse->oldy - root->mouse->y);
		else
			root->cam->ey -= 2 * ABS(root->mouse->oldy - root->mouse->y);
	}
}

void	draw_map(t_map *map, t_rt *root, int color)
{
	int i;
	int j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (j < map->width - 1)
				draw_line_img(root->img1, &map->tab[i][j],
						&map->tab[i][j + 1], color);
			if (i < map->height - 1)
				draw_line_img(root->img1, &map->tab[i][j],
						&map->tab[i + 1][j], color);
		}
	}
}

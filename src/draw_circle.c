/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 03:53:56 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:41:21 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void		pixel_put_circle(t_image *img, t_line *p, int color)
{
	pixel_put_image(img, p->d1 + p->sx, p->d2 + p->sy, color);
	pixel_put_image(img, p->d1 + p->sy, p->d2 + p->sx, color);
	pixel_put_image(img, p->d1 - p->sy, p->d2 + p->sx, color);
	pixel_put_image(img, p->d1 - p->sx, p->d2 + p->sy, color);
	pixel_put_image(img, p->d1 - p->sx, p->d2 - p->sy, color);
	pixel_put_image(img, p->d1 - p->sy, p->d2 - p->sx, color);
	pixel_put_image(img, p->d1 + p->sy, p->d2 - p->sx, color);
	pixel_put_image(img, p->d1 + p->sx, p->d2 - p->sy, color);
}

void		draw_circle(t_image *img, t_circle *pt, int color)
{
	t_line p;

	p.sx = pt->r - 1;
	p.sy = 0;
	p.d1 = pt->x;
	p.d2 = pt->y;
	p.dx = 1;
	p.dy = 1;
	p.d = p.dx - (pt->r << 1);
	while (p.sx >= p.sy)
	{
		pixel_put_circle(img, &p, color);
		if (p.d <= 0)
		{
			p.sy++;
			p.d += p.dy;
			p.dy += 2;
		}
		if (p.d > 0)
		{
			p.sx--;
			p.dx += 2;
			p.d += p.dx - (pt->r << 1);
		}
	}
}

static void	pixel_put_circle_win(t_rt *root, t_line *p, int color)
{
	mlx_pixel_put(root->mlx, root->win, p->d1 + p->sx, p->d2 + p->sy, color);
	mlx_pixel_put(root->mlx, root->win, p->d1 + p->sy, p->d2 + p->sx, color);
	mlx_pixel_put(root->mlx, root->win, p->d1 - p->sy, p->d2 + p->sx, color);
	mlx_pixel_put(root->mlx, root->win, p->d1 - p->sx, p->d2 + p->sy, color);
	mlx_pixel_put(root->mlx, root->win, p->d1 - p->sx, p->d2 - p->sy, color);
	mlx_pixel_put(root->mlx, root->win, p->d1 - p->sy, p->d2 - p->sx, color);
	mlx_pixel_put(root->mlx, root->win, p->d1 + p->sy, p->d2 - p->sx, color);
	mlx_pixel_put(root->mlx, root->win, p->d1 + p->sx, p->d2 - p->sy, color);
}

void		draw_circle_win(t_rt *root, t_circle *pt, int color)
{
	t_line p;

	p.sx = pt->r - 1;
	p.sy = 0;
	p.dx = 1;
	p.d1 = pt->x;
	p.d2 = pt->y;
	p.dy = 1;
	p.d = p.dx - (pt->r << 1);
	while (p.sx >= p.sy)
	{
		pixel_put_circle_win(root, &p, color);
		if (p.d <= 0)
		{
			p.sy++;
			p.d += p.dy;
			p.dy += 2;
		}
		if (p.d > 0)
		{
			p.sx--;
			p.dx += 2;
			p.d += p.dx - (pt->r << 1);
		}
	}
}

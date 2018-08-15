/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 20:28:46 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:42:49 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_star(t_image *img, t_circle *pt, int color)
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
			p.dy += 6;
		}
		if (p.d > 0)
		{
			p.sx--;
			p.dx += 6;
			p.d += p.dx - (pt->r << 1);
		}
	}
}

static void	draw_arrows(t_image *img)
{
	t_circle	pt;
	int			i;
	int			j;

	pt.x = 580;
	pt.y = 50;
	pt.r = 21;
	while (--pt.r)
		draw_star(img, &pt, GREY);
	pt.y = 100;
	pt.r = 21;
	while (--pt.r)
		draw_star(img, &pt, GREY);
	pt.y = 50;
	i = pt.y + 30;
	while (++i < pt.y + 70)
	{
		j = pt.x - 20;
		while (++j < pt.x + 20)
			if (i < pt.y + 42 || i > pt.y + 58)
				pixel_put_image(img, j, i, BLACK);
	}
}

static void	draw_reset(t_image *img)
{
	t_circle	pt;

	pt.y = IMG2_Y / 2;
	pt.x = 695;
	pt.r = 35;
	while (pt.r--)
		if (pt.r > 32 || pt.r < 30)
			draw_circle(img, &pt, RED);
}

void		image_pallet(t_image *img, int *colors)
{
	t_circle	pt;
	int			i;

	pt.x = 200;
	i = 0;
	while (i < 8)
	{
		pt.y = 50;
		pt.r = 21;
		while (--pt.r)
			draw_star(img, &pt, colors[i]);
		pt.r = 21;
		pt.y = 100;
		while (--pt.r)
			draw_star(img, &pt, colors[i + 1]);
		i += 2;
		pt.x += 60;
	}
	pt.x = 200;
	pt.y = 50;
	pt.r = 21;
	draw_star(img, &pt, colors[1]);
	draw_arrows(img);
	draw_reset(img);
}

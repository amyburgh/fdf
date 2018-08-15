/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:11:26 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:44:00 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	image_protect(int x, int y)
{
	return ((x < 0 || x >= IMG1_X) || (y < 0 || y >= IMG1_Y) ? 1 : 0);
}

static void	line_case1(t_image *img, t_line *line, t_point *p0)
{
	int x;
	int y;

	line->i = 0;
	line->d = (line->dy << 1) - line->dx;
	line->d1 = line->dy << 1;
	line->d2 = (line->dy - line->dx) << 1;
	if (!image_protect(p0->x, p0->y))
		pixel_put_image(img, p0->x, p0->y, line->color);
	x = p0->x + line->sx;
	y = p0->y;
	while (++line->i <= line->dx)
	{
		if (line->d > 0)
		{
			line->d += line->d2;
			y += line->sy;
		}
		else
			line->d += line->d1;
		if (!image_protect(x, y))
			pixel_put_image(img, x, y, line->color);
		x += line->sx;
	}
}

static void	line_case2(t_image *img, t_line *line, t_point *p0)
{
	int x;
	int y;

	line->i = 0;
	line->d = (line->dx << 1) - line->dy;
	line->d1 = line->dx << 1;
	line->d2 = (line->dx - line->dy) << 1;
	if (!image_protect(p0->x, p0->y))
		pixel_put_image(img, p0->x, p0->y, line->color);
	y = p0->y + line->sy;
	x = p0->x;
	while (++line->i <= line->dy)
	{
		if (line->d > 0)
		{
			line->d += line->d2;
			x += line->sx;
		}
		else
			line->d += line->d1;
		if (!image_protect(x, y))
			pixel_put_image(img, x, y, line->color);
		y += line->sy;
	}
}

void		draw_line_img(t_image *img, t_point *p0, t_point *p1, int color)
{
	t_line line;

	line.color = color;
	line.dx = (p1->x - p0->x) < 0 ? (p0->x - p1->x) : (p1->x - p0->x);
	line.dy = (p1->y - p0->y) < 0 ? (p0->y - p1->y) : (p1->y - p0->y);
	line.sx = p1->x >= p0->x ? 1 : -1;
	line.sy = p1->y >= p0->y ? 1 : -1;
	line.i = 0;
	line.d = 0;
	line.d1 = 0;
	line.d2 = 0;
	if (line.dy <= line.dx)
		line_case1(img, &line, p0);
	else
		line_case2(img, &line, p0);
}

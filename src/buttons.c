/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 00:15:59 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:42:09 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	switch_active1(t_rt *root, t_circle *pt, int x, int y)
{
	if (root->mouse->x > x - 20 && root->mouse->x < x + 20)
		draw_circle(root->img2, pt, YELLOW);
	else if (root->mouse->x > x + 40 && root->mouse->x < x + 80)
	{
		pt->x += 60;
		draw_circle(root->img2, pt, YELLOW);
	}
	else if (root->mouse->x > x + 100 && root->mouse->x < x + 140)
	{
		pt->x += 120;
		draw_circle(root->img2, pt, YELLOW);
	}
	else if (root->mouse->x > x + 160 && root->mouse->x < x + 200)
	{
		pt->x += 180;
		draw_circle(root->img2, pt, YELLOW);
	}
	else if (root->mouse->x > x + 360 && root->mouse->x < x + 400)
	{
		pt->x += 380;
		draw_circle(root->img2, pt, RED);
	}
}

static void	color_select_case1(t_mouse *mouse, t_cam *cam, int x, int y)
{
	if (mouse->x > x - 20 && mouse->x < x + 20)
		mouse->color = BLACK;
	else if (mouse->x > x + 40 && mouse->x < x + 80)
		mouse->color = RED;
	else if (mouse->x > x + 100 && mouse->x < x + 140)
		mouse->color = GREEN;
	else if (mouse->x > x + 160 && mouse->x < x + 200)
		mouse->color = BLUE;
	else if (mouse->x > x + 360 && mouse->x < x + 400)
		cam->adj += 0.005;
}

static void	switch_active2(t_rt *root, t_circle *pt, int x, int y)
{
	if (root->mouse->x > x - 20 && root->mouse->x < x + 20)
		draw_circle(root->img2, pt, YELLOW);
	else if (root->mouse->x > x + 40 && root->mouse->x < x + 80)
	{
		pt->x += 60;
		draw_circle(root->img2, pt, YELLOW);
	}
	else if (root->mouse->x > x + 100 && root->mouse->x < x + 140)
	{
		pt->x += 120;
		draw_circle(root->img2, pt, YELLOW);
	}
	else if (root->mouse->x > x + 160 && root->mouse->x < x + 200)
	{
		pt->x += 180;
		draw_circle(root->img2, pt, YELLOW);
	}
	else if (root->mouse->x > x + 360 && root->mouse->x < x + 400)
	{
		pt->x += 380;
		draw_circle(root->img2, pt, RED);
	}
}

static void	color_select_case2(t_mouse *mouse, t_cam *cam, int x, int y)
{
	if (mouse->x > x - 20 && mouse->x < x + 20)
		mouse->color = WHITE;
	else if (mouse->x > x + 40 && mouse->x < x + 80)
		mouse->color = YELLOW;
	else if (mouse->x > x + 100 && mouse->x < x + 140)
		mouse->color = PINK;
	else if (mouse->x > x + 160 && mouse->x < x + 200)
		mouse->color = AQUA;
	else if (mouse->x > x + 360 && mouse->x < x + 400)
		cam->adj -= 0.005;
}

void		color_select(t_rt *root, int x, int y)
{
	t_circle	pt;

	pt.x = 200;
	pt.y = 50;
	pt.r = 25;
	x = ((WIN_X - IMG2_X) / 2) + 200;
	y = (WIN_Y - IMG2_Y - 10) + 50;
	if (root->mouse->y > 960 && root->mouse->y < 1030 &&
			root->mouse->x > 1220 && root->mouse->x < 1290)
	{
		init_cam(root->cam);
		init_mouse(root->mouse);
	}
	else if (root->mouse->y > y - 20 && root->mouse-> y < y + 20)
	{
		color_select_case1(root->mouse, root->cam, x, y);
		switch_active1(root, &pt, x, y);
	}
	else if (root->mouse->y > y + 30 && root->mouse->y < y + 70)
	{
		pt.y += 50;
		color_select_case2(root->mouse, root->cam, x, y);
		switch_active2(root, &pt, x, y);
	}
}

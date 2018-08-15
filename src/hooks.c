/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:06:07 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/09 17:34:32 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

int		key_press(int key, t_rt *root)
{
	if (key == 53)
		exit(0);
	else if (key == 91)
		root->cam->ez += 1;
	else if (key == 87)
		root->cam->ez -= 1;
	else if (key == 92)
		root->cam->cz += 1;
	else if (key == 88)
		root->cam->cz -= 1;
	else if (key == 78)
		root->cam->scale += 0.05;
	else if (key == 69)
		root->cam->scale -= 0.05;
	render(root);
	return (0);
}

int		mouse_press(int button, int x, int y, t_rt *root)
{
	root->mouse->active = 1;
	if ((x < (WIN_X - IMG2_X) / 2 || x > (WIN_X + IMG2_X) / 2 ||
				y < WIN_Y - IMG2_Y))
	{
		root->mouse->button = button;
		zoom(root, button);
	}
	root->mouse->x = root->mouse->oldx;
	root->mouse->y = root->mouse->oldy;
	root->mouse->x = x;
	root->mouse->y = y;
	render(root);
	return (0);
}

int		mouse_release(int button, int x, int y, t_rt *root)
{
	(void)x;
	(void)y;
	root->mouse->active = 0;
	root->mouse->button = 0;
	root->cam->n = 1;
	render(root);
	return (0);
}

int		mouse_motion(int x, int y, t_rt *root)
{
	if (root->mouse->active == 1)
	{
		root->mouse->oldx = root->mouse->x;
		root->mouse->oldy = root->mouse->y;
		root->mouse->x = x;
		root->mouse->y = y;
		translate(root);
		render(root);
	}
	return (0);
}

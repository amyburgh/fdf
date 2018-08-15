/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 11:03:48 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/08 21:10:34 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

t_image	*del_image(t_rt *root, t_image *img)
{
	if (img)
	{
		if (img->ptr)
			mlx_destroy_image(root->mlx, img->ptr);
		ft_memdel((void**)&img);
	}
	return (NULL);
}

void	clear_image(t_image *img, int n)
{
	if (n == 1)
		ft_bzero(img->data, IMG1_X * IMG1_Y * 4);
	else if (n == 2)
		ft_bzero(img->data, IMG2_X * IMG2_Y * 4);
}

void	pixel_put_image(t_image *img, int x, int y, int color)
{
	*(int *)(img->data + ((x + y * img->size_line / 4) * 4)) = color;
}

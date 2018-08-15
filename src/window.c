/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:38:52 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:36:24 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void	display_info(t_rt *root)
{
	mlx_string_put(root->mlx, root->win, (WIN_X - IMG2_X) / 2 + 20,
			WIN_Y - IMG2_Y - BD + 10, WHITE, "COLOR PICKER:");
	mlx_string_put(root->mlx, root->win, (WIN_X - IMG2_X) / 2 + 420,
			WIN_Y - IMG2_Y - BD + 10, WHITE, "HEIGHT ADJUST:");
	mlx_string_put(root->mlx, root->win, (WIN_X - IMG2_X) / 2 + 630,
			WIN_Y - IMG2_Y / 2 - 20, BLACK, ">>> RESET <<<");
}

int		create_images(t_rt *root)
{
	t_image		*img1;
	t_image		*img2;
	t_image_m	*mouse;
	t_image_m	*arrows;

	MCHECK(!(img1 = (t_image*)ft_memalloc(sizeof(t_image))) ||
			!(img2 = (t_image*)ft_memalloc(sizeof(t_image))) ||
			!(mouse = (t_image_m*)ft_memalloc(sizeof(t_image_m))) ||
			!(arrows = (t_image_m*)ft_memalloc(sizeof(t_image_m))));
	img1->ptr = mlx_new_image(root->mlx, IMG1_X, IMG1_Y);
	img1->data = mlx_get_data_addr(img1->ptr, &img1->bpp, &img1->size_line,
			&img1->endian);
	img2->ptr = mlx_new_image(root->mlx, IMG2_X, IMG2_Y);
	img2->data = mlx_get_data_addr(img2->ptr, &img2->bpp, &img2->size_line,
			&img2->endian);
	mouse->ptr = mlx_xpm_file_to_image(root->mlx, "images/mouse_diagram.xpm",
			&mouse->width, &mouse->height);
	arrows->ptr = mlx_xpm_file_to_image(root->mlx, "images/arrows.xpm",
			&mouse->width, &mouse->height);
	root->img1 = img1;
	root->img2 = img2;
	root->img_m = mouse;
	root->img_a = arrows;
	return (0);
}

int		create_window(t_rt *root)
{
	if (!(root->mlx = mlx_init()))
		return (1);
	if (!(root->win =
				mlx_new_window(root->mlx, WIN_X, WIN_Y, root->map->title)))
		return (1);
	ft_strdel(&root->map->title);
	return (0);
}

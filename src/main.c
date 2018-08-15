/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 06:11:02 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:13:59 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"
#include "mlx.h"

void	error(int error)
{
	if (error == 1)
		ft_putendl("usage: ./fdf \033[31m[source_file missing]\033[0m");
	else if (error == 2)
		ft_putendl("error: \033[31m[failed map validation]\033[0m");
	else if (error == 3)
		ft_putendl("error: \033[31m[failed to create window or image]\033[0m");
	else if (error == 4)
		ft_putendl("error: \033[31m[failed to initiaize values]\033[0m");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_rt	root;
	t_map	map;

	if (argc != 2)
		error(1);
	if (!(root.map = read_file(open(argv[1], O_RDONLY), argv[1], &map)))
		error(2);
	if (create_window(&root) || create_images(&root))
		error(3);
	if (init_all(&root))
		error(4);
	render(&root);
	mlx_hook(root.win, 2, 0, key_press, &root);
	mlx_hook(root.win, 4, 0, mouse_press, &root);
	mlx_hook(root.win, 5, 0, mouse_release, &root);
	mlx_hook(root.win, 6, 0, mouse_motion, &root);
	mlx_loop_hook(root.mlx, render, &root);
	mlx_loop(root.mlx);
	return (0);
}

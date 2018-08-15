/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:00:17 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/13 16:41:56 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

static void	store_map_data_z(t_map *map, char *str, int i)
{
	t_point	**tab;
	char	**digits;
	int		j;

	tab = (t_point**)ft_memalloc(sizeof(t_point*) * map->height);
	while (++i < map->height)
	{
		j = -1;
		tab[i] = (t_point*)ft_memalloc(sizeof(t_point) * map->width);
		if (i < map->height - 1)
			while (++j < map->width)
				tab[i][j].z = map->tab[i][j].z;
		else
		{
			j = -1;
			digits = ft_strsplit(str, ' ');
			while (digits[++j])
				tab[i][j].z = ft_atoi(digits[j]);
		}
	}
	ft_tabdel((void**)map->tab, map->height - 1);
	map->tab = tab;
	ft_tabdel((void**)digits, map->width);
}

t_map		*read_file(int fd, char *title, t_map *map)
{
	char	*line;

	if (fd < 0)
		return (NULL);
	init_map(map);
	map->title = ft_strjoin("The Greatest fdf Ever => ", title);
	while (get_next_line(fd, &line) == 1)
	{
		if (!map->width)
			map->width = map_width(line);
		else if (map->width != map_width(line))
			return (NULL);
		if (validate_map(line))
			return (NULL);
		map->height++;
		store_map_data_z(map, line, -1);
		ft_strdel(&line);
	}
	if (!map->width || !map->height)
		return (NULL);
	close(fd);
	return (map);
}

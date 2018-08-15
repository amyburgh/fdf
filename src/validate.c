/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:08:16 by amyburgh          #+#    #+#             */
/*   Updated: 2018/08/08 21:15:39 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	validate_map(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (!IS_DIGIT(*str) && !SPACES1(*str) && *str != '-')
			return (1);
		str++;
	}
	return (0);
}

size_t	map_width(char *str)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (IS_DIGIT(*str) && !flag)
		{
			count++;
			flag = 1;
		}
		if (SPACES1(*str))
			flag = 0;
		str++;
	}
	return (count);
}

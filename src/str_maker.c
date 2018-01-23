/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:54:37 by lballiot          #+#    #+#             */
/*   Updated: 2018/01/23 16:52:09 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** fct qui calcule le carre le plus proche (supperieur) pour la taille d'str
*/

size_t	ft_sqrt_tetra(size_t nb)
{
	size_t rc;
	size_t nb_cpy;

	nb_cpy = nb;
	rc = 1;
	while (rc <= nb_cpy)
	{
		if (rc * rc == nb_cpy)
			return (rc);
		rc++;
		if (rc == nb_cpy)
		{
			rc = 1;
			nb_cpy = nb_cpy + 1;
		}
	}
	return (0);
}

/*
** ft qui cree et remplie la structure str
*/

s_str	*ft_str_struct_maker(size_t sq, size_t i)
{
	s_str	*map;
	size_t	x;
	size_t	y;

	x = 0;
	if (!(map = (s_str*)malloc(sizeof(s_str))))
		return (NULL);
	map->sq = sq;
	map->i = i;
	if (!(map->str = (char**)malloc(sizeof(char*) * (sq))))
		return (NULL);
	map->str[sq] = NULL;
	while (x < sq)
	{
		map->str[x] = ft_strnew(sq + 1);
		y = 0;
		while (y < sq)
			map->str[x][y++] = '.';
		map->str[x][y] = '\n';
		x++;
	}
	return (map);
}

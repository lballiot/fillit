/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:07:20 by rvolberg          #+#    #+#             */
/*   Updated: 2018/01/23 16:46:24 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function that changes the coordinate to place them in the upper left corner
*/

l_tetra		*ft_initial_move_tetra(l_tetra *list)
{
	int i;
	int x;
	int y;

	x = list->x[0];
	y = list->y[0];
	i = 0;
	while (i < 4)
	{
		if (list->x[i] < x)
		{
			x = list->x[i];
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		list->x[i] = list->x[i] - x;
		list->y[i] = list->y[i] - y;
		i++;
	}
	return (list);
}

/*
** function that creates and fill a link for
*/

l_tetra		*ft_lst_tetra(int *a, int *b, char c, int nb)
{
	l_tetra	*maillon;
	int		i;

	i = 0;
	if (!(maillon = (l_tetra*)malloc(sizeof(l_tetra))))
		return (NULL);
	if ((a) && (b))
	{
		if (!(maillon->x = (void*)malloc(sizeof(int) * (4))))
			return (NULL);
		if (!(maillon->y = (void*)malloc(sizeof(int) * (4))))
			return (NULL);
		maillon->c = c;
		maillon->nb = nb;
		while (i <= 3)
		{
			maillon->x[i] = a[i];
			maillon->y[i] = b[i];
			i++;
		}
	}
	maillon->next = NULL;
	return (maillon);
}

/*
** fonction qui trouve les coordonnes a placer dans la structure list
*/

l_tetra		*ft_tetra_coord(char *tab, l_tetra *list, char c, int nb)
{
	l_struct l;

	l.t = -1;
	l.vertical = 0;
	l.horizontal = 0;
	l.i = -1;
	while (tab[++l.i] != '\0')
	{
		if (tab[l.i] == '\n')
		{
			l.horizontal++;
			l.i++;
			l.vertical = 0;
		}
		if ((tab[l.i] >= 'A' && tab[l.i] <= 'Z') && (++l.t < 4))
		{
			l.a[l.t] = l.vertical;
			l.b[l.t] = l.horizontal;
		}
		l.vertical++;
	}
	list = ft_lst_tetra(l.a, l.b, c, nb);
	list = ft_initial_move_tetra(list);
	return (list);
}

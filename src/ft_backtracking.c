/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:07:58 by rvolberg          #+#    #+#             */
/*   Updated: 2018/01/23 16:43:05 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function that checks what char is in the tetra and returns it
*/

char		ft_chartetra(char *tetra)
{
	int		i;

	i = 0;
	while (!((tetra[i] >= 'A') && (tetra[i] <= 'Z')))
		i++;
	return (tetra[i]);
}

/*
** function that adds a link to the l_tetra struct
*/

void		ft_ltetradd(l_tetra **list, l_tetra *new)
{
	new->next = *list;
	*list = new;
}

/*
** reverse the links in list
*/

l_tetra		*ft_lstrev(l_tetra *list)
{
	l_tetra *temp;
	l_tetra *rev;

	temp = NULL;
	rev = NULL;
	while (list != NULL)
	{
		temp = list;
		list = temp->next;
		temp->next = rev;
		rev = temp;
	}
	return (rev);
}

/*
** function that fill list with all the tetra
*/

l_tetra		*ft_list(char **tetra, size_t i)
{
	l_tetra		*list;
	l_tetra		*temp;
	size_t		c;
	char		alpha;

	list = NULL;
	c = 0;
	while (c < i)
	{
		temp = NULL;
		alpha = ft_chartetra(tetra[c]);
		temp = ft_tetra_coord(tetra[c], temp, alpha, c);
		ft_ltetradd(&list, temp);
		c++;
	}
	list = ft_lstrev(list);
	return (list);
}

/*
** main backtracking
*/

void		ft_backtracking(char **tab_tetra, size_t i)
{
	size_t		sq;
	s_str		*map;
	l_tetra		*list;

	list = NULL;
	sq = ft_sqrt_tetra(i * 4);
	map = ft_str_struct_maker(sq, i);
	list = ft_list(tab_tetra, i);
	while ((ft_tetra_in_str(list, map)) != 1)
	{
		i = i + 1;
		sq = ft_sqrt_tetra(i * 4);
		map = ft_str_struct_maker(sq, i);
	}
	i = -1;
	while (++i < map->sq)
		ft_putstr(map->str[i]);
}

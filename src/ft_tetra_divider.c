/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetra_divider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:15:47 by rvolberg          #+#    #+#             */
/*   Updated: 2018/01/23 16:50:16 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** change les '#' en alphabetique dans l'ordre d'arrive
*/

static char		**ft_tetra_is_alpha(char **tab)
{
	int		x;
	size_t	y;
	int		a;

	a = 'A';
	x = 0;
	y = 0;
	while (tab[y])
	{
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] == '#')
				tab[y][x] = a;
			x++;
		}
		x = 0;
		y++;
		a++;
	}
	return (tab);
}

/*
** transforme chaine de caractere en tableau ** de char
*/

char			**ft_tetra_divider(char *str, size_t i)
{
	char	**tab;
	int		ind;
	char	*cpy;

	ind = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	tab[i] = NULL;
	while (i > 0)
	{
		tab[ind] = ft_strnew(22);
		cpy = ft_strcpy(cpy, str);
		tab[ind] = ft_strncpy(tab[ind], cpy, 21);
		str = str + 21;
		i--;
		ind++;
	}
	tab = ft_tetra_is_alpha(tab);
	return (tab);
}

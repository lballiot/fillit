/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetra_divider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:15:47 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/13 11:13:15 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** change les '#' en alphabetique dans l'ordre d'arrive
*/

static char			 **ft_tetra_is_alpha(char **tab)
{
	int x;
	size_t y;
	int a;

	a = 'A';
	x = 0;
	y = 0;
	while (tab[y])
	{
		while (tab[y][x] != '\0')
		{
			if(tab[y][x] == '#')
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

char 				**ft_tetra_divider(char *str, size_t i)
{
	char **tab;
	size_t y;
	size_t x;
	
	y = 0;
	x = 0;
	tab = NULL;
	if(!(tab = (char**)malloc(sizeof(char*) * (i))))
		return (NULL);
	if (ft_strequ(str, ""))
	{
		tab[0] = NULL;
	}		
	else
	{
		while (y < i)
		{
			tab[y] = ft_strsub(str, x, 21);
			x = x + 21;
			y++;	
		}
	}
	tab[i] = NULL;//
	tab = ft_tetra_is_alpha(tab);
	return (tab);
}





/*

x
	y = 0;//
		while (y < i)
	{
		ft_putstr("\ntetramino avant alpha ");
		ft_putnbr(y);
		ft_putstr(" :\n");
		ft_putstr(tab[y]);
		y++;
		}			





static size_t 		ft_tetra_count(char const *str)
{
	int				i;
	size_t			j;

	j = 1;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar('A');//
		if (str[i] == '\n' && str[i -1] == '\n' && str[i - 2] != '\n'
			&& str[i + 1] != '\0')//
		{
			j++;
			ft_putchar('B');//
		}
		i++;
	}
	ft_putchar('C');//
//	ft_putnbr(j);//
	return (j);
}

static char			**fill_tab(const char *str, char **tab, size_t y)
{
	size_t	i;
	size_t	x;
	size_t    a;
	
	a = 0;
	i = 0;
	while (a <= y)   //(str[i] != '\0')
	{
			ft_putchar('L');//
			while (str[i] == '\n' && str[i - 1] == '\n' && str[i] != '\0')
			{
				i++;
				ft_putchar('D');//
			}
			x = i;
			while (str[i] != '\n' && str[i - 1] != '\n' && str[i] != '\0')
			{
				i++;
				ft_putchar('E');//
			}
			if (i != x)
			{
				ft_putchar('F');//
				tab[a] = ft_strsub(str, x, (i - x));
				a++;
				ft_putchar('G');//
			}
	}
	ft_putnbr(y);//
	tab[a] = NULL;
	return (tab);
}
*/

/*	char	**tab;
	size_t	j;

	tab = NULL;
//	ft_putstr("tetra dans ft_tab:\n");//
//	ft_putstr(str);//
//   ft_putchar('\n');//
//ft_putstr("nombre de tetra dans ft_tab:\n");//
//    ft_putnbr(i);//
//    ft_putchar('\n');//
	if (str)
	{
		ft_putchar('H');//
		j = ft_tetra_count(str);
		if (!(tab = (char**)malloc(sizeof(char*) * (j + 1))))
			return (NULL);
		if (ft_strequ(str, ""))
		{
			tab[0] = NULL;
			ft_putchar('I');//
		}		
		else
		{
			ft_putchar('J');//
			tab = fill_tab(str, tab, i);
		}
	}
	ft_putchar('K');//
*/

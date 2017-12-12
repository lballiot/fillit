/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetra_divider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:15:47 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/12 15:55:18 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char 				**ft_tetra_divider(char *str, unsigned int i)
{

	char **tab;
	unsigned int y;
	unsigned int x;
	
	y = 0;
	x = 0;
	tab = NULL;
	if(!(tab = (char**)malloc(sizeof(char*) * (i + 1))))
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
	tab[y + 1] = NULL;
	return (tab);
}





/*
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

static char			**fill_tab(const char *str, char **tab, unsigned int y)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int    a;
	
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetra_divider.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:15:47 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/12 12:17:55 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

static char			**fill_tab(const char *str, char **tab)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	y;

	y = 0;
	i = 0;
	while (str[i] != '\0')
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
				tab[y] = ft_strsub(str, x, (i - x));
				y++;
				ft_putchar('G');//
			}
	}
	ft_putnbr(y);//
	tab[y] = NULL;
	return (tab);
}

char 				**ft_tetra_divider(char *str)
{
	char	**tab;
	size_t	j;

	tab = NULL;
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
			tab = fill_tab(str, tab);
		}
	}
	ft_putchar('K');//
	return (tab);
}

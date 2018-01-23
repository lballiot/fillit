/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:56:52 by lballiot          #+#    #+#             */
/*   Updated: 2018/01/10 10:56:42 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static l_struct		ft_check2(l_struct l, char *str)
{
	if (str[l.i] == '#')
		l.sharp++;
	if (str[l.i] == '.')
		l.point++;
	if (str[l.i] == '\n' && str[l.i + 1] != '\n')
		l.backn++;
	if (str[l.i] != '\n' && str[l.i] != '\0')
		l.c++;
	if (str[l.i] == '#' && str[l.i - 5] == '#')
		l.bonds++;
	if (str[l.i] == '#' && str[l.i - 1] == '#')
		l.bonds++;
	if (str[l.i] == '#' && str[l.i + 1] == '#')
		l.bonds++;
	if (str[l.i] == '#' && str[l.i + 5] == '#')
		l.bonds++;
	return (l);
}

static l_struct		ft_check3(l_struct l, char *str)
{
	if (str[l.i] != '.' && str[l.i] != '#' && str[l.i] != '\n'
			&& str[l.i] != '\0')
		l.t = -1;
	if (str[l.i] == '\n' && str[l.i + 1] != '\0')
	{
		if (l.c != 4)
			l.t = -1;
		l.c = 0;
	}
	if ((str[l.i] == '\n' && str[l.i - 1] == '\n') || (str[l.i + 1] == '\0'
				&& str[l.i] == '\n'))
	{
		if (l.sharp != 4 || l.point != 12 || l.backn != 4 || l.bonds <= 4)
			l.t = -1;
		l.sharp = 0;
		l.point = 0;
		l.backn = 0;
	}
	return (l);
}

int					ft_check(char *str, int tetra)
{
	l_struct l;

	l.point = 0;
	l.backn = 0;
	l.bonds = 0;
	l.i = 0;
	l.sharp = 0;
	l.c = 0;
	l.t = 0;
	if (!str)
		return (-1);
	if (tetra > 545 || tetra < 20)
		return (-1);
	while (str[l.i])
	{
		l = ft_check2(l, str);
		l = ft_check3(l, str);
		if (l.t == -1)
			return (-1);
		l.i++;
	}
	return (0);
}

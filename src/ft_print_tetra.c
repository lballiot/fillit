/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:39:55 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/13 11:12:57 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void ft_print_tetra(char **tab)
{
	int i;

	i = 0;

	while (tab[i])
	{
		ft_putstr("tetramino numero tableau ");
		ft_putnbr(i);
		ft_putstr(" :\n");
		ft_putstr(tab[i]);
		i++;
	}
}

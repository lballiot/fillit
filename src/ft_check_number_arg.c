/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:39:04 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/13 11:12:46 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_number_arg(int ac)
{
	char	*usage;

	usage = "usage : ./fillit [file name]\n";
//modifier usage
	if (ac != 2)
	{
		ft_putstr_fd(usage, 2);
		return (0);
	}
	return (1);
}

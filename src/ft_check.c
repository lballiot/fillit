/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:56:52 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/13 10:59:05 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check(char *str)
{
	int i;
	size_t sharp;
	size_t point = 0;

	i = -1;
	sharp = 0;
	if (!str)
	{
		write(1, "\nif nothing\n", 12);
		return (-1);
	}
	if (ft_strlen(str) > 545)
	{
		printf("\nstrlen\n");
		return (-1);
	}
	while (str[++i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n' && str[i] != '\0')
		{
			printf("\n!= . # /n\n");
			return (-1);
		}
		if (str[i] == '#')
		{
			sharp++;
//			printf("# : %zu\n", sharp);
		}
		if (str[i] == '.')
			point++;
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			if (sharp != 4)
			{
				printf("\nsharp != 4\n");
				return (-1);
			}
			if (point != 12)
			{
				printf("\npoint != 12\n");
				return (-1);
			}
			sharp = 0;
			point = 0;
		}
	}
//	write(1, "toto\n", 5);
	return (0);
}	

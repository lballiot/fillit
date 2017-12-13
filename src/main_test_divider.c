/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_divider.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:30:49 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/13 11:14:12 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int main (void)
{
	char *str;
	char **tab;
	int i;

	i = 0;

//	str = "test1 \n\n test2 \ntest3 test3bis \n\n test4\n";
	str = "#...\n#...\n#...\n#...\n\n....\n....\n..##\n..##";

	//ft_putendl(str);
	tab = ft_tetra_divider(str, i);
	while (tab)
	{
		ft_putstr(tab[i]);
		i++;
		ft_putchar('1');
	}
	return (0);
}

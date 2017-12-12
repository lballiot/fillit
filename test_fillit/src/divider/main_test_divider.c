/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_divider.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:30:49 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/12 12:18:17 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_tetra_divider(char *str);


int main (void)
{
	char *str;
	char **tab;
	int i;

	i = 0;

//	str = "test1 \n\n test2 \ntest3 test3bis \n\n test4\n";
	str = "#...\n#...\n#...\n#...\n\n....\n....\n..##\n..##";

	//ft_putendl(str);
	tab = ft_tetra_divider(str);
	while (tab)
	{
		ft_putstr(tab[i]);
		i++;
		ft_putchar('1');
	}
	return (0);
}

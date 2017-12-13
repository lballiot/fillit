/* ************************************************************************** */
/*                              */
/*          :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*      +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*  +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:41:26 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/13 11:13:04 by lballiot         ###   ########.fr       */
/*                              */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**ft_read(int o_fd)
{
	char	*buf;
	char	*str_tetra;
	char	**tab_tetra;
	int		read_fd;
	size_t	i; // compteur tetraminos

	tab_tetra = NULL;
	i = 0;
	read_fd = 0;
	str_tetra = ft_strnew(21);//
	buf = ft_strnew(21);//

	//perte du dernier \n du dernier tetra ds read, rajouter quelque part a la main
	while ((read_fd = read(o_fd, buf, 21)) > 0)
	{
		buf[read_fd] = '\0';
		// verification du tetra dans le buf
		str_tetra = ft_strcat(str_tetra, buf);
		buf = ft_strnew(21);
		i++;
	}
	free(buf);
	//ft_putstr(str_tetra);//
	tab_tetra = ft_tetra_divider(str_tetra, i);
	if (read_fd == -1)
	{
		ft_putstr_fd("read() failed\n", 2);
		tab_tetra[0] = "read() failed\n";//
		return(tab_tetra);
	}
	return(tab_tetra);
}

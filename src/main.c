/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:28:40 by rvolberg          #+#    #+#             */
/*   Updated: 2018/01/23 16:48:32 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_check_number_arg(int ac)
{
	char	*usage;

	usage = "usage : ./fillit [file name]\n"; //modifier usage
	if (ac != 2)
	{
		ft_putstr_fd(usage, 2);
		return (0);
	}
	return (1);
}

int		ft_open(char **argv)
{
	int		open_fd;

	open_fd = 0;
	open_fd = open(argv[1], O_RDONLY);
	if (open_fd == -1)
		ft_putstr_fd("open() failed\n", 2);
	return (open_fd);
}

char	**ft_read(int o_fd, char **tab_tetra)
{
	char	*buf;
	char	*str_tetra;
	size_t	counter;
	int		tetra;

	tetra = 0;
	counter = 0;
	str_tetra = ft_strnew(21);
	buf = ft_strnew(21);
	while (read(o_fd, buf, 21) > 0)
	{
		tetra += ft_strlen(buf);
		if (ft_check(buf, tetra) == -1)
		{
			ft_putstr_fd("error\n", 2);
			return (0);
		}
		str_tetra = ft_strjoin(str_tetra, buf);
		buf = ft_strnew(21);
		counter++;
	}
	free(buf);
	tab_tetra = ft_tetra_divider(str_tetra, counter);
	ft_backtracking(tab_tetra, counter);
	return (tab_tetra);
}

int		main(int argc, char **argv)
{
	int		open_fd;
	char	**tab_tetra;

	tab_tetra = NULL;
	if ((ft_check_number_arg(argc)) == 0)
		return (0);
	open_fd = ft_open(argv);
	if (open_fd == -1)
		return (0);
	tab_tetra = ft_read(open_fd, tab_tetra);
	if (tab_tetra == NULL)
		return (0);
	if (close(open_fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 2);
		return (0);
	}
	return (0);
}

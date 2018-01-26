/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:28:40 by rvolberg          #+#    #+#             */
/*   Updated: 2018/01/26 12:49:52 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** function that check the number of input files and if need be, return
** the usage of the program
*/

int		ft_check_number_arg(int ac)
{
	char	*usage;

	usage = "usage:\t ./fillit source_file target_file\n"
		"\t ./fillit source_file ... target_directory";
	if (ac != 2)
	{
		ft_putstr_fd(usage, 2);
		return (0);
	}
	return (1);
}

/*
** function that open the iput file
*/

int		ft_open(char **argv)
{
	int		open_fd;

	open_fd = 0;
	open_fd = open(argv[1], O_RDONLY);
	if (open_fd == -1)
		ft_putstr_fd("open() failed\n", 2);
	return (open_fd);
}

/*
** function that reads the input file and send it to the function
** that changes it to a char**
*/

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
	ft_putstr("o_fd = ");
	ft_putnbr(o_fd);
	ft_putstr("\nread = ");
	ft_putnbr(read(o_fd, buf, 21));
	if (read(o_fd, buf, 21) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_putstr("\n\nafter if \no_fd = ");
	ft_putnbr(o_fd);
	ft_putstr("\nread = ");
	ft_putnbr(read(o_fd, buf, 21));
//	after the condition the read if going one tetraminos after the beginning 
	while ((read(o_fd, buf, 21)) > 0)
	{
		tetra += ft_strlen(buf);
		if (ft_check(buf, tetra) == -1)
		{
			ft_putstr("error\n");
			return (0);
		}
		str_tetra = ft_strjoin(str_tetra, buf);
		buf = ft_strnew(21);
		counter++;
	}
	free(buf);
	tab_tetra = ft_tetra_divider(str_tetra, counter);
	ft_putstr("toto\n");
	if (tab_tetra == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_backtracking(tab_tetra, counter);
	return (tab_tetra);
}

/*
** main function
*/

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

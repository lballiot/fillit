/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:28:40 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/13 11:18:46 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				main(int argc, char **argv)
{
	int	open_fd;
	char **tab_tetra;
	int		check;

	open_fd = 0;
	if ((ft_check_number_arg(argc)) == 0)
		return (0);
	open_fd = ft_open(argv);
	if (open_fd == -1)
		return (1);
//	check = ft_check()
	if (ft_check() == -1)
	{
		ft_putstr_fd("error\n", 2);
		return (0);
	}
	tab_tetra = ft_read(open_fd);
	if ((ft_strcmp(tab_tetra[1], "read() failed\n") == 0))
		return (1);

	ft_print_tetra(tab_tetra); //test du tetra_divier

	if (close(open_fd) == -1)
	{
		ft_putstr_fd("close() failed\n", 2);
		return (1);
	}
	return (0);
}

/*
** index chaine de tetraminos 


static char			*ft_str_counter(char *str)
{
	char *ptr_str;
	
	ptr_str = str;
	while (*ptr_str != '\0' && *ptr_str != '\n' && (*ptr_str -1) != '\n')
		ptr_str++;
	return (ptr_str);
}

** creation et remplissage liste chainee

static l_tetra *ft_fill_struct(char *str)
{
	l_tetra *list;
	l_tetra *begin;

	if (!(list = (l_tetra*)malloc(sizeof(l_tetra))))
		return(NULL);

	if (str)
	{
		if (!(list->tetra = (char*)malloc(sizeof(21))))//
			return (NULL);//
		list->tetra = ft_memcpy(list->tetra, (const void*)str, 20);
		str = ft_str_counter(str);
		list->next = list;
		begin = list;
	}
	while (str)
	{
		if (!(list->tetra = (char*)malloc(sizeof(21))))//
			return (NULL);//
		list->tetra = ft_memcpy(list->tetra, (const void*)str, 20);
		str = ft_str_counter(str);
		list->next = list;
	}
	if (!(str))
		list->tetra = NULL;
	list->next = NULL;
	return (list);

 */

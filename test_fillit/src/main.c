/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:28:40 by rvolberg          #+#    #+#             */
/*   Updated: 2017/12/12 18:11:39 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//char **ft_tab_tetra_maker(char *str, int i, char **tab);
//char **ft_tetra_divider(char *str, unsigned int i);

static int		ft_check_number_arg(int argc)
{
	char		*usage;

	usage = "usage : ./fillit [file name]\n";//
	if (argc < 2)
	{
		ft_putstr_fd(usage, 2);
		return (0);
	}
		if (argc > 2)
	{
		ft_putstr_fd(usage, 2);
		return (0);
	}
		return (1);
}

/*
** ouverture fichier donner en param
*/

static int			ft_open(char **argv)
{
	int open_fd;

	open_fd = 0;
	open_fd = open(argv[1], O_RDONLY);
	if (open_fd == -1)
	{
		ft_putstr_fd("open() failed\n", 2);
	}
	return (open_fd);
}

/*
** print tab pour tester tetra_divider
*/

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


/*
** lecture ficher, traduit en chaine de caracteres
** puis separe tetra par tetra dans tab**
*/

static char			**ft_read(int o_fd)
{
	char *buf;
	char *str_tetra;
	char **tab_tetra;
	int	read_fd;
	unsigned int i; // compteur tetraminos
	
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
//	ft_putstr(str_tetra);//
	tab_tetra = ft_tetra_divider(str_tetra, i);

	if (read_fd == -1)
	{
		ft_putstr_fd("read() failed\n", 2);
		tab_tetra[0] = "read() failed\n";//
		return(tab_tetra);
	}
	
return(tab_tetra);
}


int				main(int argc, char **argv)
{
	int	open_fd;
	char **tab_tetra;	

	open_fd = 0;
	if ((ft_check_number_arg(argc)) == 0)
		return (0);
	open_fd = ft_open(argv);
	if (open_fd == -1)
		return (1);
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

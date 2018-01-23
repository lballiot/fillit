/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:23:17 by lballiot          #+#    #+#             */
/*   Updated: 2018/01/23 17:23:24 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct		tetra_list
{
	int 			*x;
	int 			*y;
	char			c;
	int				nb;
	struct tetra_list   *next;
}			 l_tetra;

typedef struct		tab_ret_list // ajouter pour simplifier, a voir..
{
	size_t 			i;//
	size_t 			sq;
	char			**str;
	struct tab_ret_list		*next;
}					s_str;

typedef struct			struct_list
{
	int i;
	size_t sharp;
	size_t point;
	size_t c;
	size_t backn;
	size_t bonds;
	int t;
	size_t vertical;
	size_t horizontal;
	int a[4];
	int b[4];
}						l_struct;


/*
				FUNCTION TO REMOVE
char **tab_tetra_maker(char *str, int i, char **tab);
char **ft_str_size(size_t sq);
char **ft_str_maker(char **str, size_t sq);
s_str *ft_tetra_remover(int t, char **tetra, s_str *map);//
s_str *ft_placement(l_tetra *list, s_str *map, char **tetra, int t);//
l_tetra *ft_geometry(l_tetra *list, s_str *map);//
l_tetra *ft_first_tetra_mover(s_str *map, l_tetra *list);//
char ft_tetra_finder(char str, int i, char **tetra, int t);
void ft_print_tab(s_str *map);//
l_tetra *ft_coord_modif_x(l_tetra *list);//
l_tetra *ft_check_error(int x, s_str *map, char **tab_tetra);
int ft_place_str_checker(l_tetra *list, s_str *map);//
void ft_print_tetra(char **tab);
void ft_print_list(l_tetra *list);
*/
///////////////////////////////////////////////////////////////////////////////

//								FUNCTION WE USE                              //

s_str *ft_str_struct_maker(size_t sq, size_t i);//

size_t ft_sqrt_tetra(size_t nb);

l_tetra *ft_initial_move_tetra(l_tetra *list);

l_tetra*ft_lst_tetra(int *a, int *b, char c, int nb);

l_tetra *ft_tetra_coord(char *tab, l_tetra *list, char c, int nb);

char	ft_chartetra(char *tetra);

void ft_ltetradd(l_tetra **list, l_tetra *new);

l_tetra *ft_lstrev(l_tetra *list);//

l_tetra         *ft_list(char **tetra, size_t i);

void ft_backtracking(char **tab_tetra, size_t i);

void ft_remove(char c, s_str *map);//

void ft_place(char c, s_str *map, l_tetra *list, int *tab);

int ft_check_place(l_tetra *list, s_str *map, int x, int y);

int ft_tetra_in_str(l_tetra *list, s_str *map);//

int ft_check(char *str, int tetra);

char **ft_tetra_divider(char *str, size_t i);

int ft_check_number_arg(int ac);

int ft_open(char **av);

char **ft_read(int o_fd, char **tab_tetra);

#endif

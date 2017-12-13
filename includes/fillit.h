/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:02:27 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/13 10:59:42 by lballiot         ###   ########.fr       */
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

typedef	struct		struct_list
{
    char            *tetra;
    struct s_list   *next;
}					l_tetra;

//int		ft_check_number_arg(int ac);

char		**ft_tetra_divider(char *str, size_t i);

char		**tab_tetra_maker(char *str, int i, char **tab);

int			ft_open(char **av);

int			ft_check_number_arg(int ac);

void		ft_print_tetra(char **tab);

char		**ft_read(int o_fd);

int			ft_check(char *str);

#endif

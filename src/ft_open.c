/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lballiot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:36:49 by lballiot          #+#    #+#             */
/*   Updated: 2017/12/13 10:38:23 by lballiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int          ft_open(char **argv)
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

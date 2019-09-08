/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 14:12:47 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/01/24 14:12:48 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

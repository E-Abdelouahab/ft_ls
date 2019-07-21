/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:26:38 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 00:54:27 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	usage_error(char c)
{
	ft_printf("ls : illegal option -- %c\n", c);
	ft_printf("usage: ls [-RSalrt] [file ...]\n");
	exit(1);
}

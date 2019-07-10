/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:26:38 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/07 15:31:44 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	usage_error(char c)
{
	printf("ls : illegal option -- %c\n", c);
	printf("usage: ls [-RSalrt] [file ...]\n");
}

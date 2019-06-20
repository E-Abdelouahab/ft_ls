/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:23:08 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/18 16:52:06 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*basename(char *str, char c)
{
	char	*last_pos;

	last_pos = 0;
	while (*str)
	{
		if (*str == c)
			last_pos = (char*)str;
		++str;
	}
	return (last_pos++);
}

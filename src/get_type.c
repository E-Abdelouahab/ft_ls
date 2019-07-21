/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:03:36 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 02:40:39 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		get_type(int type)
{
	if (type == DT_DIR)
		return DIRECTORY;
	else if (type == DT_CHR)
		return CHR;
	else if (type == DT_BLK)
		return BLOCK;
	else if (type == DT_REG)
		return REGULAR;
	else if (type == DT_LNK)
		return LINK;
	else if (type == DT_SOCK)
		return SOCKET;
	else if (type == DT_FIFO)
		return FIFO;
	else
		return UNKNOWN;
}

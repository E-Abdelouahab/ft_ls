/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:36:06 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/18 22:11:57 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		get_type(__uint8_t type)
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

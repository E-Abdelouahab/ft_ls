/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:36:06 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/19 18:07:33 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		get_type2(mode_t st_mode)
{
	if ((st_mode & S_IFMT) == S_IFDIR)
		return DIRECTORY;
	else if ((st_mode & S_IFMT) == S_IFCHR)
		return CHR;
	else if ((st_mode & S_IFMT) == S_IFBLK)
		return BLOCK;
	else if ((st_mode & S_IFMT) == S_IFREG)
		return REGULAR;
	else if ((st_mode & S_IFMT) == S_IFLNK)
		return LINK;
	else if ((st_mode & S_IFMT) == S_IFSOCK)
		return SOCKET;
	else if ((st_mode & S_IFMT) == S_IFIFO)
		return FIFO;
	else
		return UNKNOWN;
	
}

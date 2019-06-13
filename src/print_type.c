/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 06:19:35 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/05/14 06:38:16 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_type(int filemode)
{
	if ((filemode & S_IFMT) == S_IFDIR)
		printf("d");
	else if ((filemode & S_IFMT) == S_IFCHR)
		printf("c");
	else if ((filemode & S_IFMT) == S_IFBLK)
		printf("b");
	else if ((filemode & S_IFMT) == S_IFREG)
		printf("-");
	else if ((filemode & S_IFMT) == S_IFLNK)
		printf("l");
	else if ((filemode & S_IFMT) == S_IFSOCK)
		printf("s");
	else if ((filemode & S_IFMT) == S_IFIFO)
		printf("p");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_permissions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 06:19:35 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/17 11:52:55 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_type(unsigned short filemode)
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

void	print_permissions(unsigned short filemode)
{
	print_type(filemode);
	if (filemode & S_IRUSR)
		printf("r");
	else
		printf("-");
	if (filemode & S_IWUSR) 
		printf("w");
	else
		printf("-");
	if (filemode & S_IXUSR)
		printf("x");
	else
		printf("-");
	if (filemode & S_IRGRP)
		printf("r");
	else
		printf("-");
	if (filemode & S_IWGRP)
		printf("w");
	else
		printf("-");
	if (filemode & S_IXGRP)
		printf("x");
	else
		printf("-");
	if (filemode & S_IROTH)
		printf("r");
	else
		printf("-");
	if (filemode & S_IWOTH)
		printf("w");
	else
		printf("-");
	if (filemode & S_IXOTH)
		printf("x  ");
		else
			printf("-  ");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_permissions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 06:19:35 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 00:54:27 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_type(unsigned short filemode)
{
	if ((filemode & S_IFMT) == S_IFDIR)
		ft_printf("d");
	else if ((filemode & S_IFMT) == S_IFCHR)
		ft_printf("c");
	else if ((filemode & S_IFMT) == S_IFBLK)
		ft_printf("b");
	else if ((filemode & S_IFMT) == S_IFREG)
		ft_printf("-");
	else if ((filemode & S_IFMT) == S_IFLNK)
		ft_printf("l");
	else if ((filemode & S_IFMT) == S_IFSOCK)
		ft_printf("s");
	else if ((filemode & S_IFMT) == S_IFIFO)
		ft_printf("p");
}

void	print_permissions(unsigned short filemode)
{
	print_type(filemode);
	if (filemode & S_IRUSR)
		ft_printf("r");
	else
		ft_printf("-");
	if (filemode & S_IWUSR) 
		ft_printf("w");
	else
		ft_printf("-");
	if (filemode & S_IXUSR)
		ft_printf("x");
	else
		ft_printf("-");
	if (filemode & S_IRGRP)
		ft_printf("r");
	else
		ft_printf("-");
	if (filemode & S_IWGRP)
		ft_printf("w");
	else
		ft_printf("-");
	if (filemode & S_IXGRP)
		ft_printf("x");
	else
		ft_printf("-");
	if (filemode & S_IROTH)
		ft_printf("r");
	else
		ft_printf("-");
	if (filemode & S_IWOTH)
		ft_printf("w");
	else
		ft_printf("-");
	if (filemode & S_IXOTH)
		ft_printf("x  ");
		else
			ft_printf("-  ");
}

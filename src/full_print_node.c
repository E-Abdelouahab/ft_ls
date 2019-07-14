/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_print_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:21:51 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/14 13:14:43 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	print_bin(int bin)
// {
// 	if (bin < 2)
// 		ft_putchar(bin + '0');
// 	else
// 	{
// 		print_bin(bin / 2);
// 		print_bin(bin % 2);
// 	}
// }
#include "../inc/ft_ls.h"

void	print_size_by_type(t_node *node, t_info *info)
{
	int	maj;
	int min;

	maj = major(node->m_rdev);
	min = minor(node->m_rdev);
	if ((node->type == DT_CHR) || (node->type == DT_BLK))
			printf("%4d, %4d ", maj, min);
	else
		print_size(node->size, info->flags);
}

void	print_name_by_type(t_node *head)
{
	char	*linkname;
	int		r;

	linkname = falloc((head->size + 1), 1, 1);
	if (head->type == DT_LNK)
	{
		r = readlink(head->path, linkname, head->size + 1);
		 if (r < 0)
		 	handle_error(head->path);
		else
		{
			linkname[head->size] = '\0';
			printf("%s%s -> %s\n", head->name, RESET, linkname);
		}
	}
	else
		printf("%s\n", head->name);
}

void	full_print_node(t_node *head, t_info *info)
{
	while(head)
	{
		print_permissions(head->perm);
		printf("%3u ", head->h_links);
		printf("%-10s ", head->owner);
		printf("%-14s ", head->group);
		print_size_by_type(head, info);
		printf("%-14s ", get_time(head->m_time));
		print_color(head->type, head->perm);
		print_name_by_type(head);
		print_color(0, 0);
		head = head->next;
	}
}

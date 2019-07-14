/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:18:43 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/13 14:11:26 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void handle_error2(char *name)
{
	printf("ft_ls: %s: %s\n\n", name, strerror(errno));
}

void	read_all(t_node **head, t_info **info, int tracker)
{
	DIR				*dir;
	struct dirent	*dp;
	t_node			*dirs;
	t_node			*all;
	t_node			*copy;

	dirs = NULL;
	all = NULL;
	dir = opendir((*head)->path);
	if (!dir)
	{
		handle_error2((*head)->name);
		return;
	}
	if (tracker)
		printf("%s:\n", (*head)->path);
	(*info)->path_tbi = (*head)->path;
	(*info)->list_len = 0;
	(*info)->max_len = 0;
	while ((dp = readdir(dir)) != NULL)
	{
			normal_fill(info, dp);
			(*info)->insert_func((char*)(&all), (char*)info);
			((*info)->list_len)++;
			if (is_dir(dp->d_type))
				(*info)->insert_func((char*)(&dirs), (char*)info);
	}
	if (all)
		(*info)->print_func(all, *info);
	else
		printf("\n");
	if ((*info)->flags & FLAG_RCAP)
	{
		while (dirs)
		{
			(*info)->path_tbi = (*head)->path;
			(*info)->name_tbi = dirs->name;
			copy = new_lnode(*info);
			read_all(&copy, info, tracker + 1);
			dirs = dirs->next;
		}
	}
	closedir(dir);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 01:11:00 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/16 23:25:23 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	read_content(t_node **head, t_info **info, int tracker)
{
	DIR				*dir;
	struct dirent	*dp;
	t_node			*dirs;
	t_node			*all;
	t_node			*copy;

	dirs = NULL;
	all = NULL;
	dir = opendir((*head)->path);
	printf("path : %s , name: %s\n", (*head)->path, (*head)->name);
	if (!dir)
	{
		handle_error((*head)->name);
		return;
	}
	if (tracker || !((*info)->flags & FLAG_RCAP))
		printf("%s:\n", (*head)->path);
	(*info)->path_tbi = (*head)->path;
	(*info)->list_len = 0;
	(*info)->max_len = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") || is_hidden(dp->d_name))
			continue;
		else
		{	
			normal_fill(info, dp);
			(*info)->insert_func((char*)(&all), (char*)info);
			((*info)->list_len)++;
			if (is_dir(dp->d_type))
				(*info)->insert_func((char*)(&dirs), (char*)info);
		}
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
			read_content(&copy, info, tracker + 1);
			dirs = dirs->next;
		}
	}
	closedir(dir);
}

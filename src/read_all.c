/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:18:43 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/10 20:47:11 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	read_all(t_node **head, t_info **info,int tracker)
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
		return;	
	if (tracker)
		printf("%s:\n", (*head)->path);
	while ((dp = readdir(dir)) != NULL)
	{
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
			continue;
		else
		{
			fill_info(info, dp);
			(*info)->insert_func((char*)(&all), (char*)info);
			if (is_dir(dp->d_type))
				(*info)->insert_func((char*)(&dirs), (char*)info);
		}
	}
	if (all)
		f_print(all, *info);
	else
		printf("\n");
	if ((*info)->flags & FLAG_RCAP)
	{
		while (dirs)
		{
			(*info)->path_tbi = (*head)->path;
			copy = new_lnode(*info);
			read_content(&copy, info, tracker + 1);
			dirs = dirs->next;
		}	
	}
	closedir(dir);
}

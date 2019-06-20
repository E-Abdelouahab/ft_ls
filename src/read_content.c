/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 01:11:00 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/19 16:25:01 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	read_content(t_node **head, int tracker)
{
	DIR			*dir;
	struct		dirent *dp;
	t_node		*dirs;
	t_node		*all;
	t_node		*copy;

	dirs = NULL;
	all = NULL;
	dir = opendir((*head)->path);
	if (!dir)
		return;
	if (tracker)
		printf("%s:\n", (*head)->path);
	while ((dp = readdir(dir)) != NULL)
	{
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") || is_hidden(dp->d_name))
			continue;
		else
		{
			insert_lnode(&all,get_dname((*head)->path, dp->d_name),dp->d_name, get_type(dp->d_type));
			if (is_dir(dp->d_type))
				insert_lnode(&dirs, get_dname((*head)->path, dp->d_name), dp->d_name, get_type(dp->d_type));
		}
	}
	if (all)
		f_print(all);
	else
		printf("\n");
	while (dirs)
	{
		copy = new_lnode(dirs->path,dirs->name,dirs->type);
		read_content(&copy, tracker + 1);
		dirs = dirs->next;
	}
	closedir(dir);
}

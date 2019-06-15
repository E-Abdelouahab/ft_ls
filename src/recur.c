/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:04:34 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/15 23:28:39 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_node	*recur(t_node *head)
{
	DIR			*dir;
	struct		dirent *dp;
	t_node		*dirs;
	t_node		*files;
	t_node		*root;

	root = NULL;
	dirs = root;
	files = root;
	printf("path : %s \n", head->path);
	dir = opendir(head->path);
	if (!dir)
		return (NULL);
	while ((dp = readdir(dir)) != NULL)
	{
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
			continue;
		else
		{
			if (is_dir(dp->d_type))
				dirs = insert_node(dirs, get_fname(dp->d_name), get_dname(head->path, dp->d_name));
			else
				files = insert_node(files, get_fname(dp->d_name), NULL);
		}
	}
	if (dirs == NULL || (dirs->left == NULL && dirs->right == NULL))
		return root;
	printf("============================\n\n");
	printf("Entering: %s\n\n", head->name);
	inorder_print(files);
	inorder_dprint(dirs);
	printf(">>HEAD>>|%s|\n", dirs->name);
	printf(">>>>left|%s|\n", dirs->left->name);
	printf(">>>>right|%s|\n", dirs->right->name);
	recall(dirs);
	closedir(dir);
	return (root);
}

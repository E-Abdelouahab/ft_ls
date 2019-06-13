/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:04:34 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/12 22:23:29 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void recur(t_node *root, char *str)
{
	DIR *dir;
	struct dirent *dp;
	char * file_name;
	dir = opendir(str);
	dp=readdir(dir);
	char *ins_name;
	while ((dp=readdir(dir)) != NULL) {
		if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
			continue;
		else {
			if (is_dir(dp->d_type))
			{
				ins_name = get_name(str, dp->d_name);
				insert_node(root, ins_name);
				recur(root, dp->d_name);
			}
		}
	}
	closedir(dir);
}

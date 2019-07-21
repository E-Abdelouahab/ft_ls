/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:47:09 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 20:42:36 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*get_username(uid_t uid_var)
{
	struct passwd	*pwd;
	char			*username;

	pwd = getpwuid(uid_var);
	username = ft_strdup(pwd->pw_name);
	return (username);
}

char	*get_groupname(gid_t gid_var)
{
	struct group	*grp_;
	char			*groupname;

	grp_ = getgrgid(gid_var);
	groupname = ft_strdup(grp_->gr_name);
	return (groupname);
}

void	fill_extra_info(t_node **node, struct stat *inf)
{
	(*node)->h_links = inf->st_nlink;
	(*node)->owner = get_username(inf->st_uid);
	(*node)->group = get_groupname(inf->st_gid);
	(*node)->blk_size = inf->st_blocks;
	(*node)->m_rdev = inf->st_rdev;
}

t_node	*new_lnode(t_info *info)
{
	t_node		*node;
	struct stat	inf;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	if (info->ikhan == 0)
		node->path = get_dname(info->path_tbi, info->name_tbi);
	else
		node->path = ft_strdup(info->name_tbi);
	node->name = ft_strdup(info->name_tbi);
	node->type = info->type_tbi;
	node->previous = NULL;
	node->next = NULL;
	lstat(node->path, &inf);
	node->size = inf.st_size;
	node->m_time = inf.st_mtime;
	node->perm = inf.st_mode;
	fill_extra_info(&node, &inf);
	return (node);
}

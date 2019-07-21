/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:16:30 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 20:48:46 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	read_args_helper1_1(t_info **info, t_node **dirs)
{
	(*info)->insert_func((char*)(dirs), (char*)info);
	((*info)->counter)++;
}

void	read_args_helper1(t_info **info, t_args **head, t_node **dirs,
	t_node **all)
{
	struct stat		inf;
	struct stat		inf2;

	(*info)->name_tbi = (*head)->name;
	lstat((*head)->name, &inf);
	stat((*head)->name, &inf2);
	if ((inf.st_mode & S_IFMT) == S_IFLNK && (inf2.st_mode & S_IFMT) ==
		S_IFDIR && (*info)->flags & FLAG_L)
	{
		(*info)->type_tbi = LINK;
		(*info)->insert_func((char*)(all), (char*)info);
		((*info)->list_len)++;
	}
	else
	{
		if ((inf2.st_mode & S_IFMT) == S_IFDIR)
			read_args_helper1_1(info, dirs);
		else
		{
			(*info)->type_tbi = get_type2(inf.st_mode);
			(*info)->insert_func((char*)(all), (char*)info);
			((*info)->list_len)++;
		}
	}
}

void	read_args_helper2(t_info **info, t_node **dirs)
{
	t_node	*all;

	all = *dirs;
	while (*dirs)
	{
		(*info)->path_tbi = (*dirs)->name;
		(*info)->ikhan = 0;
		if ((*info)->counter == 1)
			ft_printf("%s:\n", (*info)->path_tbi);
		read_function(dirs, info);
		*dirs = (*dirs)->next;
	}
	free_nodes(all);
}

void	read_args(t_args **head, t_info **info)
{
	t_node			*dirs;
	t_node			*all;
	t_args			*tbf;

	dirs = NULL;
	all = NULL;
	tbf = (*head);
	while (*head)
	{
		read_args_helper1(info, head, &dirs, &all);
		(*head) = (*head)->next;
	}
	free_args(tbf);
	if (all != NULL || (*info)->counter > 1)
		(*info)->counter = 1;
	else
		(*info)->counter = 0;
	if (all)
		(*info)->print_func(all, *info);
	else
		ft_printf("\n");
	free_nodes(all);
	(*info)->print_total = 1;
	read_args_helper2(info, &dirs);
}

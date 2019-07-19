/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rwina.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:16:30 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/19 22:57:29 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"



void	read_args(t_args **head, t_info **info)
{
	struct stat		inf;
	struct stat		inf2;
	t_node			*dirs;
	t_node			*all;
	int				counter;

	dirs = NULL;
	all = NULL;
	counter = 0;
	while (*head)
	{
			(*info)->name_tbi = (*head)->name;
			lstat((*head)->name, &inf);
			stat((*head)->name, &inf2);
			if ((inf.st_mode & S_IFMT) == S_IFLNK &&
				(inf2.st_mode & S_IFMT) == S_IFDIR &&
				(*info)->flags & FLAG_L)
				{
					(*info)->type_tbi = LINK;
					(*info)->insert_func((char*)(&all), (char*)info);
					((*info)->list_len)++;
				}

			else
			{
				if((inf2.st_mode & S_IFMT) == S_IFDIR)
				{
					(*info)->insert_func((char*)(&dirs), (char*)info);
					counter++;
				}
				else
				{
					(*info)->type_tbi = get_type2(inf.st_mode);
					(*info)->insert_func((char*)(&all), (char*)info);
					((*info)->list_len)++;
				}
			}
			(*head) = (*head)->next;
	}
	if (all)
		(*info)->print_func(all, *info);
	else
		printf("\n");
	(*info)->print_total = 1;
	while (dirs)
	{
		(*info)->path_tbi = ft_strdup(dirs->name);
		(*info)->ikhan = 0;
		if(all != NULL || counter > 1)
			printf("%s:\n",(*info)->path_tbi);
		read_function(&dirs, info);
		dirs = dirs->next;
	}
}

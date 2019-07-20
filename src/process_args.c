/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 22:55:52 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/20 12:29:24 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	open_only(char *name, t_info **info)
{
	DIR				*dir;
	struct dirent	*dp;

	dir = opendir(name);
	dp = readdir(dir);
	(*info)->name_tbi = ft_strdup(dp->d_name);
	(*info)->path_tbi = ft_strdup(dp->d_name);
}


t_args	*process_args(int ac, char **av, t_info **info)
{
	int		first_item;
	t_args	*args;

	*info = (t_info*)malloc(sizeof(t_info));
	args = NULL;
	init_info(info);
	first_item = get_options(ac, av, info);
	get_function(info);
	if (first_item == 0 || first_item == ac)
	{
		open_only(".", info);
		(*info)->insert_arg_func(&args, *info, ".");
	}
	else
	{
		while (first_item < ac)
		{
			(*info)->insert_arg_func(&args, *info, av[first_item]);
			first_item++;
		}
	}
	return (args);
}

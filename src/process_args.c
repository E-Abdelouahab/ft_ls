/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 22:55:52 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/05 20:17:13 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_args	*process_args(int ac, char **av)
{
	int		first_item;
	t_args	*args;
	t_info	*info;

	args = NULL;
	info = (t_info*)malloc(sizeof(t_info));
	init_info(&info);
	first_item = get_options(ac, av, &info);
	get_function(&info);
	while (first_item < ac)
	{
	info->insert_arg_func(&args, info, av[first_item]);
	first_item++;
	}
	return args;
}

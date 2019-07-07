/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_job.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 21:50:20 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/05 15:16:06 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	do_job(t_info **info, t_args **args)
{
	t_node	*node;

	node = NULL;
	while(*args)
	{
		node->path = (*args)->name;
		read_content(&node, info);
		(*args) = (*args)->next;
	}
}

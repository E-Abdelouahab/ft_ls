/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:24:05 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/07 20:36:32 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int sort_args_func(t_args *node, t_args *new_node, t_info *info)
{
	if(info->flags & FLAG_T)
		return (node->time < new_node->time) ? -1 : 1;
	if(info->flags & FLAG_SCAP)
		return (node->size < new_node->size) ? -1 : 1;
	else
		return (strcoll(node->name, new_node->name));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:18:14 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/11 21:57:07 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int sort_function(t_node *node, t_node *new_node, t_info *info)
{
	if(info->flags & FLAG_T)
		return (node->m_time > new_node->m_time) ? -1 : 1;
	if(info->flags & FLAG_SCAP)
		return (node->size > new_node->size) ? -1 : 1;
	else
		return (strcoll(node->path, new_node->path));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_argnode_rev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:14:08 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 20:22:47 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	insert_argnode_rhelper(t_args **args, t_args **new_node, t_info *info)
{
	t_args	*current;

	current = *args;
	while (current->next != NULL && sort_args_func(current->next,
		*new_node, info) > 0)
		current = current->next;
	(*new_node)->next = current->next;
	if (current->next != NULL)
		(*new_node)->next->previous = *new_node;
	current->next = *new_node;
	(*new_node)->previous = current;
}

int		insert_argnode_rev(t_args **args, t_info *info, char *name)
{
	t_args	*new_node;
	t_args	*current;

	current = *args;
	new_node = new_argnode(name);
	if (*args == NULL)
	{
		*args = new_node;
		return (0);
	}
	if (sort_args_func(current, new_node, info) < 0)
	{
		new_node->next = *args;
		new_node->next->previous = new_node;
		*args = new_node;
	}
	else
		insert_argnode_rhelper(args, &new_node, info);
	return (0);
}

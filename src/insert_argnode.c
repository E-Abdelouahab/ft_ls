/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_argnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:14:08 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/19 18:21:52 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int	insert_argnode(t_args **args, t_info *info, char *name)
{
	t_args *new_node;
	t_args *current;

	current = *args;
	new_node = new_argnode(name);

	if (*args == NULL)
	{
		*args = new_node;
		return (0);
	}
	if (sort_args_func(current, new_node, info) > 0)
	{
		new_node->next = *args;
		new_node->next->previous = new_node;
		*args = new_node;
	}
	else
	{
			current = *args;
			while (current->next != NULL && sort_args_func(current->next, 
				new_node, info) < 0)
				current = current->next;
			new_node->next = current->next; 
			if (current->next != NULL)
				new_node->next->previous = new_node;
			current->next = new_node;
			new_node->previous = current;
	}
	return (0);
}

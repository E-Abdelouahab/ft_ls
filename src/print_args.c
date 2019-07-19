/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 21:41:17 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/28 21:42:02 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_args(t_args *args)
{
	t_args *current_node = args;

	while ( current_node != NULL)
	{
		printf("%s\t", current_node->name);
		current_node = current_node->next;
	}
		printf("\n\n");
}

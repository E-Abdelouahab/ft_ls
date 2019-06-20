/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 13:34:30 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/18 22:13:20 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	f_print(t_node *head)
{
	t_node *current_node = head;

	while ( current_node != NULL)
	{
		print_color(current_node->type);
		printf("%s\t", current_node->name);
		print_color(0);
		current_node = current_node->next;
	}
		printf("\n\n");
}

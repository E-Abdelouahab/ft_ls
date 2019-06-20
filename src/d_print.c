/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:46:28 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/06/18 16:15:23 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	d_print(t_node *head)
{
	t_node	*current_node = head;

	while ( current_node != NULL) {
		printf(ANSI_COLOR_BLUE"%s  "ANSI_COLOR_RESET, current_node->name);
		current_node = current_node->next;
	}
}

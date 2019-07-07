/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 00:01:12 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/06 12:42:06 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	get_function(t_info **info)
{
	if ((*info)->flags & FLAG_T)
		(*info)->sort_func = my_cmp;
	else if ((*info)->flags & FLAG_SCAP)
		(*info)->sort_func = my_cmp;
	else
		(*info)->sort_func = strcoll;
	if ((*info)->flags & FLAG_RLOW)
	{
		(*info)->insert_arg_func = insert_argnode_rev;
		(*info)->insert_func = insert_lnode_rev;
	}
	else
	{
		(*info)->insert_arg_func = insert_argnode;
		(*info)->insert_func = insert_lnode;
	}
	
	// if((*info)->flags & FLAG_L)
	// 	(*info)->print_func = //print with details
	// else
	// 	(*info)->print_func = //normal print
	
}
`

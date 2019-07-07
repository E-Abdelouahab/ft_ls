/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:29:36 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/05 16:53:33 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	init_info(t_info **info)
{
	(*info)->path_tbi = NULL;
	(*info)->name_tbi = NULL;
	(*info)->type_tbi = 0;
	(*info)->flags = 0;
	(*info)->insert_func = NULL;
	(*info)->sort_func = NULL;
	(*info)->print_func = NULL;
	(*info)->tracker = 0;
}

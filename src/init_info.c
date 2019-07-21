/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:29:36 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 03:44:17 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	init_info(t_info **info)
{
	(*info)->max_len = 0;
	(*info)->list_len = 0;
	(*info)->name_tbi = NULL;
	(*info)->path_tbi = NULL;
	(*info)->type_tbi = 0;
	(*info)->flags = 0;
	(*info)->insert_func = NULL;
	(*info)->print_func = NULL;
	(*info)->tracker = 0;
	(*info)->ikhan = 1;
	(*info)->print_total = 0;
	(*info)->counter = 0;
}

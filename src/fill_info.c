/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:23:30 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/05 15:50:18 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	fill_info(t_node *head, t_info **info, struct dirent *dp)
{
	(*info)->path_tbi = get_dname(head->path, dp->d_name);
	(*info)->name_tbi = dp->d_name;
	(*info)->type_tbi = get_type((int)(dp->d_type));
}

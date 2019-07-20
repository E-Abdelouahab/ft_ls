/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:23:30 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/20 14:04:18 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	normal_fill(t_info **info, struct dirent *dp)
{
	int		name_len;

	name_len = ft_strlen(dp->d_name);
	if(name_len > (*info)->max_len)
		(*info)->max_len = name_len;
	if ((*info)->name_tbi != NULL)
		free((*info)->name_tbi);
	(*info)->name_tbi = ft_strdup(dp->d_name);
	(*info)->type_tbi = get_type((int)(dp->d_type));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:23:30 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/10 23:57:32 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	fill_info(t_info **info, struct dirent *dp)
{
	int		name_len;

	name_len = ft_strlen(dp->d_name);
	if(name_len > (*info)->max_len)
		(*info)->max_len = name_len;
	(*info)->name_tbi = ft_strdup(dp->d_name);
	(*info)->type_tbi = get_type((int)(dp->d_type));
}
